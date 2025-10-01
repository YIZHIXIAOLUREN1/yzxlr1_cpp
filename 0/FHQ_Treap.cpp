#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n;
mt19937 rnd(std::random_device{}());
struct node{
    node *ch[2];
    int cnt,siz;
    int val;
    int prio;
    node (int _val):val(_val),cnt(1),siz(1),prio(rnd()){ch[0]=ch[1]=nullptr;}
    node(node *_node){val=_node->val,prio=_node->prio,cnt=_node->cnt,siz=_node->siz;}
    void upd_siz(){siz=cnt+(!ch[0]?0:ch[0]->siz)+(!ch[1]?0:ch[1]->siz);}
} *root;

pair<node *,node *> split_val(node *cur,int val){
    if(cur==nullptr)return {nullptr,nullptr};
    if(cur->val <=val){
        auto temp=split_val(cur->ch[1],val);
        cur->ch[1]=temp.first;
        cur->upd_siz();
        return {cur,temp.second};
    }else{
        auto temp=split_val(cur->ch[0],val);
        cur->ch[0]=temp.second;
        cur->upd_siz();
        return {temp.first,cur};
    }
}

tuple<node *,node *,node *> split_rk(node *cur,int rk){
    if(cur==nullptr)return {nullptr,nullptr,nullptr};
    int ls_siz= cur->ch[0]==nullptr?0:cur->ch[0]->siz;
    if(rk<=ls_siz){
        auto [l,mid,r]=split_rk(cur->ch[0],rk);
        cur->ch[0]=r;
        cur->upd_siz();
        return {l,mid,cur};
    }else if(ls_siz+cur->cnt>=rk){
        node *l=cur->ch[0],*r=cur->ch[1];
        cur->ch[0]=cur->ch[1]=nullptr;
        return {l,cur,r};
    }else{
        auto [l,mid,r]=split_rk(cur->ch[1],rk-ls_siz-cur->cnt);
        cur->ch[1]=l;
        cur->upd_siz();
        return {cur,mid,r};
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

void insert(node *cur,int val){
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
    root=merge(nl,left.second);
}

void del(int val){
    auto left=split_val(root,val);
    auto tg=split_val(left.first,val-1);
    if(tg.second->cnt>1){
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
    root=merge(tg.first,left.second);
}

int qrk_val(node *cur,int val){
    auto left=split_val(cur,val-1);
    int res=(left.first==nullptr?0:left.first->siz)+1;
    cur=merge(left.first,left.second);
    return res;
}

int qrk_rk(node *cur,int rk){
    auto [l,mid,r]=split_rk(cur,rk);
    int res=mid->val;
    cur=merge(merge(l,mid),r);
    return res;
}

int qpre(int val) {
  auto temp=split_val(root,val-1);
  int res=qrk_rk(temp.first,temp.first->siz);
  root=merge(temp.first, temp.second);
  return res;
}

int qnex(int val) {
  auto temp=split_val(root,val);
  int res=qrk_rk(temp.second,1);
  root=merge(temp.first, temp.second);
  return res;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    while(n--){
        int opt,x;
        cin>>opt>>x;
        switch(opt){
            case 1:insert(root,x);break;
            case 2:del(x);break;
            case 3:cout<<qrk_val(root,x)<<"\n";break;
            case 4:cout<<qrk_rk(root,x)<<"\n";break;
            case 5:cout<<qpre(x)<<"\n";break;
            case 6:cout<<qnex(x)<<"\n";break;
        }
    }
}
