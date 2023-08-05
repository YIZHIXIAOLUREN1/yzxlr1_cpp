#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=6e5+7;
const ll inf=0xc0c0c0c0c0c0c0c0;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
int n,m;
int a[N];
struct node{
    ll sum,ml,mr,ans;
}w[N<<1],ni;

#define gc() getchar()
#define pc(x) putchar(x)
inline int read(){int w=1,q=0;char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=gc();if(ch=='-')w=-1,ch=gc();
    while(ch>='0'&&ch<='9')q=q*10+ch-'0',ch=gc();return w*q;}
inline void pr(ll x){if(x<0)pc('-'),x=-x;if(x>9)pr(x/10);pc(x%10+'0');}

node hb(node a,node b){
    node c;
    c.sum=a.sum+b.sum;
    c.ml=max(a.ml,a.sum+b.ml);
    c.mr=max(b.mr,b.sum+a.mr);
    c.ans=max(max(a.ans,b.ans),a.mr+b.ml);
    return c;
}

void pushup(int u){w[u]=hb(w[ls],w[rs]);}


void build(int u,int l,int r){
    if(l==r){
        w[u].sum=w[u].ml=w[u].mr=w[u].ans=a[l];
        return;
        }
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}
node query(int u,int l,int r,int L,int R){
	if(L<=l&&r<=R)return w[u];
    if(l>R||r<L)return ni;
	return hb(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
}

void update1(int u,int l,int r,int x,int v){
    if(l==r){
        a[l]=w[u].sum=w[u].ml=w[u].mr=w[u].ans=v;
        return;
    }
    if(x<=mid)update1(ls,l,mid,x,v);
	else update1(rs,mid+1,r,x,v);
	pushup(u);
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ni.sum=0,ni.ml=ni.mr=ni.ans=inf;
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    build(1,1,n);
    while(m--){
    	//cout <<"A";//
        int k,x,y;
        k=read(),x=read(),y=read();
        if(k==1){
            if(x>y)swap(x,y);
            pr(query(1,1,n,x,y).ans);
        }else update1(1,1,n,x,y);
    }

}
