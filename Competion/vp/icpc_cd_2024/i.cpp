#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,Q;
int a[N];

int g(int a,int b){
    if(a*b==0)return (a==0?b:a);
    if(a%b==0)return b;
    return g(b,a%b);
}

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
        val=g(ch[0]->val,ch[1]->val);
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
	return g(query(cur->ch[0],L,R),query(cur->ch[1],L,R));
}
void update1(node *cur,int tg,int v){
	if(cur->l==cur->r){cur->val=v;return;}
    if(tg<=cur->mid)update1(cur->ch[0],tg,v);
    else update1(cur->ch[1],tg,v);
    cur->pushup();
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    *root1=node(1,N-1);
        build(root1);
    while(T--){
        cin>>n>>Q;
        
        //cout<<"A";//
        for(int i=1,l=1;i<=n;i++){
            cin>>a[i];
            if(a[i]>a[i+1]){
                update1(root1,i,i);
            }
        }
        cout<<query(root1,1,n)<<"\n";
        while(Q--){
            int tg,v;
            cin>>tg>>v;
            a[tg]=v;
            update1(root1,tg,0);
            update1(root1,tg-1,0);
            if(a[tg]>a[tg+1]){
                update1(root1,tg,tg);
            }
            if(a[tg-1]>a[tg]){
                update1(root1,tg-1,tg-1);
            }
            //update1(root1,tg,v);

            cout<<query(root1,1,n)<<"\n";
        }
    }
}
