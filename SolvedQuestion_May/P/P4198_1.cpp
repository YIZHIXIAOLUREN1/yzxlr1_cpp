#include<bits/stdc++.h>
using namespace std;
#define db double
#define gc() getchar()
#define pc(x) putchar(x)
#define endl pc(10)
inline int read(){int w=1,q=0;char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=gc();if(ch=='-')w=-1,ch=gc();
    while(ch>='0'&&ch<='9')q=q*10+ch-'0',ch=gc();return w*q;}
inline void pr(int x){if(x<0)pc('-'),x=-x;if(x>9)pr(x/10);pc(x%10+'0');}
const int N=100007;
const int inf=0xc0c0c0c0;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
int n,m;
int cnt[N*4];
db mx[N*4];

int query(int u,int l,int r,db ml){
	if(ml>mx[u])return 0;
    else if(l==r)return mx[u]>ml;
    else if(mx[ls]<=ml)return query(rs,mid+1,r,ml);
    else return cnt[u]-cnt[ls]+query(ls,l,mid,ml);
}

void update1(int u,int l,int r,int x,int v){
    if(l==r){
        cnt[u]=1;
        mx[u]=(db)v/x;
        return;
    }
    if(x<=mid)update1(ls,l,mid,x,v);
    else update1(rs,mid+1,r,x,v);
    mx[u]=max(mx[ls],mx[rs]);
    cnt[u]=cnt[ls]+query(rs,mid+1,r,mx[ls]);
    //printf("%d %d %d:%d\n",u,l,r,cnt[u]);//
}

int main(){
    n=read(),m=read();
    for(int i=1,x,y;i<=m;i++){
        x=read(),y=read();
        update1(1,1,n,x,y);
        pr(cnt[1]),endl;
    }

}