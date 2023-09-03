#include<bits/stdc++.h>
using namespace std;
#define ll int
const int N=6e5+7;
const ll inf=0xc0c0c0c0;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
int n,m;
int a[N],b[N];
struct node{
    ll ans,ma,mb,la,ra;
}w[N*4],ni;

#define gc() getchar()
#define pc(x) putchar(x)
#define endl pc(10)
inline int read(){int w=1,q=0;char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=gc();if(ch=='-')w=-1,ch=gc();
    while(ch>='0'&&ch<='9')q=q*10+ch-'0',ch=gc();return w*q;}
inline void pr(ll x){if(x<0)pc('-'),x=-x;if(x>9)pr(x/10);pc(x%10+'0');}

node hb(node a,node b){
    node c;
    c.ma=max(a.ma,b.ma);
    c.mb=min(a.mb,b.mb);
    c.la=max(max(a.la,b.la),a.ma-b.mb);
    c.ra=max(max(a.ra,b.ra),b.ma-a.mb);
    c.ans=max(max(a.ans,b.ans),max(a.la+b.ma,a.ma+b.ra));
    return c;
}

void pushup(int u){w[u]=hb(w[ls],w[rs]);}

void build(int u,int l,int r){
    if(l==r){
        w[u].ma=a[l];
        w[u].mb=b[l];
        w[u].la=w[u].ra=w[u].ans=inf;
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

void update1(int u,int l,int r,int x,int va,int vb){
    if(l==r){
        if(va)w[u].ma=a[l]=va;
        else w[u].mb=b[l]=vb;
        w[u].la=w[u].ra=w[u].ans=inf;
        return;
    }
    if(x<=mid)update1(ls,l,mid,x,va,vb);
	else update1(rs,mid+1,r,x,va,vb);
	pushup(u);
}

int main(){
    ni.ma=ni.la=ni.ra=ni.ans=inf;ni.mb=-inf;
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)b[i]=read();
    build(1,1,n);
    while(m--){
    	//cout <<"A";//
        int k,x,y;
        k=read(),x=read(),y=read();
        if(k==1)update1(1,1,n,x,y,0);
        else if(k==2)update1(1,1,n,x,0,y);
        else pr(query(1,1,n,x,y).ans),endl;
    }

}
