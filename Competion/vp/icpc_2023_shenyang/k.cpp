#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=2e5+7;

mt19937 rnd(random_device{}());
struct node{
    node *ch[2];
    int cnt,siz;
    int val;
    ll sum;
    int prio;
    node(int _val):val(_val),cnt(1),siz(1),prio(rnd()),sum(_val){ch[0]=ch[1]=nullptr;}
    node(node *_node){val=_node->val,prio=_node->prio,cnt=_node->cnt,siz=_node->siz,sum=_node->sum;}
    void upd(){
        siz=cnt+(!ch[0]?0:ch[0]->siz)+(!ch[1]?0:ch[1]->siz);
        sum=1ll*cnt*val+(!ch[0]?0:ch[0]->sum)+(!ch[1]?0:ch[1]->sum);
    }
} *root;

pair<node *,node *> split_val(node *cur,int val){
    if(cur==nullptr)return {nullptr,nullptr};
    if(cur->val<=val){
        auto temp=split_val(cur->ch[1],val);
        cur->ch[1]=temp.first;
        cur->upd();
        return {cur,temp.second};
    }else{
        auto temp=split_val(cur->ch[0],val);
        cur->ch[0]=temp.second;
        cur->upd();
        return {temp.first,cur};
    }
}

tuple<node *,node *,node *> split_sum(node *cur,ll sum){
    if(cur==nullptr)return {nullptr,nullptr,nullptr};
    ll ls_sum=cur->ch[0]==nullptr?0:cur->ch[0]->sum;
    if(sum<=ls_sum){
        auto [l,mid,r]=split_sum(cur->ch[0],sum);
        cur->ch[0]=r;
        cur->upd();
        return {l,mid,cur};
    }else if(ls_sum+1ll*cur->cnt*cur->val>=sum){
        node *l=cur->ch[0],*r=cur->ch[1];
        cur->ch[0]=cur->ch[1]=nullptr;
        cur->upd();
        return {l,cur,r};
    }else{
        auto [l,mid,r]=split_sum(cur->ch[1],sum-ls_sum-1ll*cur->cnt*cur->val);
        cur->ch[1]=l;
        cur->upd();
        return {cur,mid,r};
    }
}

node *merge(node *u,node *v){
    if(u==nullptr&&v==nullptr)return nullptr;
    if(u==nullptr)return v;
    if(v==nullptr)return u;
    if(u->prio<v->prio){
        u->ch[1]=merge(u->ch[1],v);
        u->upd();
        return u;
    }else{
        v->ch[0]=merge(u,v->ch[0]);
        v->upd();
        return v;
    }
}

void insert(node *cur,int val){
    auto left=split_val(cur,val);
    auto tg=split_val(left.first,val-1);
    node *nwno;
    if(tg.second==nullptr){
        nwno=new node(val);
    }else{
        tg.second->cnt++;
        tg.second->upd();
    }
    node *nl=merge(tg.first,tg.second==nullptr?nwno:tg.second);
    root=merge(nl,left.second);
}

void del(int val){
    auto left=split_val(root,val);
    auto tg=split_val(left.first,val-1);
    if(tg.second->cnt>1){
        tg.second->cnt--;
        tg.second->upd();
        tg.first=merge(tg.first,tg.second);
    }else{
        if(tg.first==tg.second){
            left.first==nullptr;
        }
        delete tg.second;
        tg.second=nullptr;
    }
    root=merge(tg.first,left.second);
}

int qrk_val(node *cur,int val){
    auto left=split_val(cur,val-1);
    int res=(left.first==nullptr?0:left.first->siz)+1;
    cur=merge(left.first,left.second);
    return res;
}

void print(node* cur) {
    if(!cur)return;
    cur->upd();
    print(cur->ch[0]);
    cout << cur->val<<":"<<cur->sum << " ";
    print(cur->ch[1]);
}


int qrk_sum(node *cur,ll sum){
    auto [l,mid,r]=split_sum(cur,sum);
    //if(!l)l->upd();if(!mid)mid->upd();if(!r)r->upd();
    
    int res=(l==nullptr?0:l->siz);
    //cout<<res<<" ";
    if(mid!=nullptr){
    	res+=min((sum-1-(l==nullptr?0:l->sum))/(mid->val),1ll*mid->cnt);
    	//cout<<res<<" ";
    }
    //cout<<":";
    //print(l);cout<<"\n";
    //print(mid);cout<<"\n";
    //print(r);cout<<"\n";
    cur=merge(merge(l,mid),r);
    //print(cur);cout<<"\n";
    return res;
}

ll qsum_val(node *cur,int val){
    auto left=split_val(cur,val-1);
    ll res=(left.first==nullptr?0:left.first->sum);
    cur=merge(left.first,left.second);
    return res;
}


int n,a[N],Q;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>Q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        insert(root,a[i]);
    }
    //cout<<qrk_sum(root,0)-qrk_val(root,1)+2<<"\n";//
    while(Q--){
        int x,v;
        cin>>x>>v;
        del(a[x]);
        insert(root,v);
        a[x]=v;
        //printf("%d:%d\n",qrk_sum(root,1),qrk_val(root,1));//
        cout<<qrk_sum(root,1)-qrk_val(root,1)+2<<"\n";
    }
}
