#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7,inf=0x7FFFFFFF;
int n;
mt19937 rnd(std::random_device{}());
struct node{
    node *ch[2];
    int cnt,siz;
    int val;
    int prio;
    node (int _val):val(_val),cnt(1),siz(1),prio(rnd()){ch[0]=ch[1]=nullptr;}
    node(node *_node){val=_node->val,prio=_node->prio,cnt=_node->cnt,siz=_node->siz;ch[0]=_node->ch[0];ch[1]=_node->ch[1];}
    void upd_siz(){siz=cnt+(!ch[0]?0:ch[0]->siz)+(!ch[1]?0:ch[1]->siz);}
} *root[N];

pair<node *,node *> split_val(node *cur,int val){
    if(cur==nullptr)return {nullptr,nullptr};
    node *now=new node(cur);
    if(now->val <=val){
        auto temp=split_val(now->ch[1],val);
        now->ch[1]=temp.first;
        now->upd_siz();
        return {now,temp.second};
    }else{
        auto temp=split_val(now->ch[0],val);
        now->ch[0]=temp.second;
        now->upd_siz();
        return {temp.first,now};
    }
}

tuple<node *,node *,node *> split_rk(node *cur,int rk){
    if(cur==nullptr)return {nullptr,nullptr,nullptr};
    node *now=new node(cur);
    int ls_siz=now->ch[0]==nullptr?0:now->ch[0]->siz;
    if(rk<=ls_siz){
        auto [l,mid,r]=split_rk(now->ch[0],rk);
        now->ch[0]=r;
        now->upd_siz();
        return {l,mid,now};
    }else if(ls_siz+now->cnt>=rk){
        node *l=now->ch[0],*r=now->ch[1];
        now->ch[0]=now->ch[1]=nullptr;
        return {l,now,r};
    }else{
        auto [l,mid,r]=split_rk(now->ch[1],rk-ls_siz-now->cnt);
        now->ch[1]=l;
        now->upd_siz();
        return {now,mid,r};
    }
}

node *merge(node *u,node *v){
    if(u==nullptr&&v==nullptr)return nullptr;
    if(v==nullptr)return u;
    if(u==nullptr)return v;
    if(u->prio<v->prio){
        u->ch[1]=merge(u->ch[1],v);
        u->upd_siz();
        return u;
    }else{
        v->ch[0]=merge(u,v->ch[0]);
        v->upd_siz();
        return v;
    }
}

void insert(node *cur,node *&now,int val){
    auto left=split_val(cur,val);
    auto tg=split_val(left.first,val-1);
    node *nwno;
    if(tg.second==nullptr){
        nwno=new node(val);
    }else{
        tg.second->cnt++;
        tg.second->upd_siz();
    }
    node *nl=merge(tg.first,tg.second==nullptr?nwno:tg.second);
    now=merge(nl,left.second);
}

void del(node *cur,node *&now,int val){
    auto left=split_val(cur,val);
    auto tg=split_val(left.first,val-1);
    if(tg.second==nullptr);
    else if(tg.second->cnt>1){
        tg.second->cnt--;
        tg.second->upd_siz();
        tg.first=merge(tg.first,tg.second);
    }else{
        if(left.first==tg.second){
            left.first=nullptr;
        }
        delete tg.second;
        tg.second=nullptr;
    }
    now=merge(tg.first,left.second);
}

int qrk_val(node *cur,int val){
    if(cur==nullptr)return 0;
    else if(cur->val<val)return (cur->ch[0]?cur->ch[0]->siz:0)+cur->cnt+(cur->ch[1]?qrk_val(cur->ch[1],val):0);
    else return (cur->ch[0]?qrk_val(cur->ch[0],val):0);
}

int qrk_rk(node *cur,int rk){
    if((cur->ch[0]?cur->ch[0]->siz:0)>=rk)return qrk_rk(cur->ch[0],rk);
    else if((cur->ch[0]?cur->ch[0]->siz:0)+cur->cnt>=rk)return cur->val;
    else return qrk_rk(cur->ch[1],rk-(cur->ch[0]?cur->ch[0]->siz:0)-cur->cnt);
}

int qpre(node *cur,int val){
    int rk=qrk_val(cur,val);
    if(!rk)return -inf;
    return qrk_rk(cur,rk);
}

int qnex(node *cur,int val){
    int rk=qrk_val(cur,val+1);
    if(rk==cur->siz)return inf;
    return qrk_rk(cur,rk+1);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int ver,opt,x;
        cin>>ver>>opt>>x;
        switch(opt){
            case 1:insert(root[ver],root[i],x);break;
            case 2:del(root[ver],root[i],x);break;
            case 3:cout<<qrk_val(root[ver],x)+1<<"\n";break;
            case 4:cout<<qrk_rk(root[ver],x)<<"\n";break;
            case 5:cout<<qpre(root[ver],x)<<"\n";break;
            case 6:cout<<qnex(root[ver],x)<<"\n";break;
        }
        if(opt>=3)root[i]=root[ver];
        root[i]=root[i];
    }
}
