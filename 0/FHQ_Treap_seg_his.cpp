#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7,inf=0x7FFFFFFF;
int n;
mt19937 rnd(std::random_device{}());
struct node{
    node *ch[2];
    int cnt,siz,val,prio;
    ll sum;
    bool to_rev=0;
    node (int _val):val(_val),cnt(1),siz(1),prio(rnd()),sum(_val){ch[0]=ch[1]=nullptr;}
    node(node *_node){
        val=_node->val,prio=_node->prio,cnt=_node->cnt,siz=_node->siz;
        to_rev=_node->to_rev,sum=_node->sum,ch[0]=_node->ch[0];ch[1]=_node->ch[1];
    }
    void upd_siz(){
        sum=1ll*val+(!ch[0]?0:ch[0]->sum)+(!ch[1]?0:ch[1]->sum);
        siz=cnt+(!ch[0]?0:ch[0]->siz)+(!ch[1]?0:ch[1]->siz);
    }
    void pushdown(){
        if(ch[0]){node *now=new node(ch[0]);ch[0]=now;ch[0]->to_rev^=1;}
        if(ch[1]){node *now=new node(ch[1]);ch[1]=now;ch[1]->to_rev^=1;}
        swap(ch[0],ch[1]);to_rev=0;
    }
    void check_tag(){if(to_rev)pushdown();}
} *root[N];

pair<node*, node*> split_seg(node* cur, int rk) {
    if(cur==nullptr)return {nullptr, nullptr};
    node *now=new node(cur);
    now->check_tag();
    int lf_siz=(now->ch[0]==nullptr)?0:now->ch[0]->siz;
    if(rk<=lf_siz){
        auto temp=split_seg(now->ch[0],rk);
        now->ch[0]=temp.second;
        now->upd_siz();
        return {temp.first,now};
    }else{
        auto temp=split_seg(now->ch[1],rk-lf_siz-1);
        now->ch[1]=temp.first;
        now->upd_siz();
        return {now,temp.second};
    }
}

node *merge(node *u,node *v){
    if(u==nullptr&&v==nullptr)return nullptr;
    if(v==nullptr)return u;
    if(u==nullptr)return v;
    if(u->prio<v->prio){
        u->check_tag();
        u->ch[1]=merge(u->ch[1],v);
        u->upd_siz();
        return u;
    }else{
        v->check_tag();
        v->ch[0]=merge(u,v->ch[0]);
        v->upd_siz();
        return v;
    }
}

void insert(node *cur,node *&now,int rk,int val){
    node *nwno=new node(val);
    auto less=split_seg(cur,rk);
    now=merge(less.first,merge(nwno,less.second));
}

void del(node *cur,node *&now,int rk){
    auto less=split_seg(cur,rk-1);
    auto more=split_seg(less.second,1);
    now=merge(less.first,more.second);
}

void seg_rev(node *cur,node *&now,int l,int r){
    auto less=split_seg(cur,l-1);
    auto more=split_seg(less.second,r-l+1);
    more.first->to_rev^=1;
    now=merge(less.first,merge(more.first,more.second));
}

ll query(node *cur,node *&now,int l,int r){
    auto less=split_seg(cur,l-1);
    auto more=split_seg(less.second,r-l+1);
    ll res=more.first->sum;
    now=merge(less.first,merge(more.first,more.second));
    return res;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    ll ltans=0;
    for(int i=1;i<=n;i++){
        ll ver,opt,x,p,l,r;
        cin>>ver>>opt;
        if(opt==1){
            cin>>p>>x;
            p^=ltans,x^=ltans;
            insert(root[ver],root[i],p,x);
        }else if(opt==2){
            cin>>p;
            p^=ltans;
            del(root[ver],root[i],p);
        }else if(opt==3){
            cin>>l>>r;
            l^=ltans,r^=ltans;
            seg_rev(root[ver],root[i],l,r);
        }else{
            cin>>l>>r;
            l^=ltans,r^=ltans;
            ltans=query(root[ver],root[i],l,r);
            cout<<ltans<<"\n";
        }
    }
}