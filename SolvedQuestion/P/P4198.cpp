#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define gc() getchar()
#define pc(x) putchar(x)
#define endl pc(10)
inline int read(){int w=1,q=0;char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=gc();if(ch=='-')w=-1,ch=gc();
    while(ch>='0'&&ch<='9')q=q*10+ch-'0',ch=gc();return w*q;}
inline void pri(int x){if(x<0)pc('-'),x=-x;if(x>9)pri(x/10);pc(x%10+'0');}
const int N=100007;
const int inf=0xc0c0c0c0;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define pr pair<int,int>
int n,m;
int cnt[N*4];
pr mx[N*4];

bool operator <(pr a,pr b){
	if(a.first==0)return 1;
	if(b.first==0)return 0;
    return (ll)a.second*b.first<(ll)a.first*b.second;
}
bool operator >(pr a,pr b){
    if(a.first==0)return 0;
    if(b.first==0)return 1;
    return (ll)a.second*b.first>(ll)a.first*b.second;
}

pr MAX(pr a,pr b){
    return a>b?a:b;
}

int query(int u,int l,int r,pr ml){
	if(ml>mx[u])return 0;
    else if(l==r)return mx[u]>ml;
    else if(mx[ls]<ml)return query(rs,mid+1,r,ml);
    else return cnt[u]-cnt[ls]+query(ls,l,mid,ml);
}

void update1(int u,int l,int r,int x,int v){
    if(l==r){
        cnt[u]=1;
        mx[u]={x,v};
        return;
    }
    if(x<=mid)update1(ls,l,mid,x,v);
    else update1(rs,mid+1,r,x,v);
    mx[u]=MAX(mx[ls],mx[rs]);
    cnt[u]=cnt[ls]+query(rs,mid+1,r,mx[ls]);
}

int main(){
    n=read(),m=read();
    for(int i=1,x,y;i<=m;i++){
        x=read(),y=read();
        update1(1,1,n,x,y);
        //for(int i=1;i<=5;i++)printf("%d:%d %d\n",i,mx[i].first,mx[i].second);//
        pri(cnt[1]);
        if(i!=m)endl;
    }

}
