#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    node *ch[2];
    int l,r,mid;
    int val;
    node (int _l,int _r):l(_l),r(_r),val(0){
        ch[0]=ch[1]=nullptr;
        mid=(_l+_r)/2;
    }
    node(node *_node){val=_node->val,l=_node->l,r=_node->r;}
    void pushup(){
        if(l==r)return;
        val=ch[0]->val+ch[1]->val;
    }
}*root1,*root2;

void build(node *cur){
    if(cur->l==cur->r){return;}
    node *nl=new node(cur->l,cur->mid),*nr=new node(cur->mid+1,cur->r);
    cur->ch[0]=nl;
    cur->ch[1]=nr;
    build(cur->ch[0]);
    build(cur->ch[1]);
}

ll query(node *cur,int L,int R){
    if(R<L)return 0;
	if(L<=cur->l&&cur->r<=R)return cur->val;
    if(cur->l>R||cur->r<L)return 0;
	return (query(cur->ch[0],L,R)+query(cur->ch[1],L,R));
}
void update1(node *cur,int tg,int v){
	if(cur->l==cur->r){cur->val+=v;return;}
    if(tg<=cur->mid)update1(cur->ch[0],tg,v);
    else update1(cur->ch[1],tg,v);
    cur->pushup();
}