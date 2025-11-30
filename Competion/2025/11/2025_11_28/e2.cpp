#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=3e5+7,mod=998244353;
int n,m;
pair<int,int> qr[N];//l,r
int f[N];
int lst[N];

#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
ll w[N*4];

void pushup(const int u){w[u]=(w[ls]+w[rs])%mod;}
void build(int u,int l,int r){
    if(l==r){w[u]=0;return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}
ll query(int u,int l,int r,int L,int R){
	if(L<=l&&r<=R)return w[u];
    if(l>R||r<L)return 0;
	return (query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R))%mod;
}
void update1(int u,int l,int r,int tg,int x){
    if(l>tg||r<tg)return;
	if(l==r){w[u]=(w[u]+x)%mod;return;}////
	
	if(tg<=mid)update1(ls,l,mid,tg,x);
	else update1(rs,mid+1,r,tg,x);
	pushup(u);
}

bool cmp1(pair<int,int> x,pair<int,int> y){
    if(x.second==y.second)return x.first>y.first;
    return x.second<y.second;
}

void Solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)f[i]=0,lst[i]=0;
    for(int i=1;i<=m;i++)cin>>qr[i].first>>qr[i].second;
    sort(qr+1,qr+m+1,cmp1);
    for(int i=1;i<=m;i++){
        if(!lst[qr[i].second])lst[qr[i].second]=qr[i].first;
    }
    for(int i=1;i<=n;i++){
        lst[i]=max(lst[i],lst[i-1]);
        //cout<<lst[i]<<" \n"[i==n];//
    }
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=lst[i];j<=i-1;j++)f[i]=(f[i]+f[j])%mod;
        //f[i]=query(1,0,n,lst[i],i-1);
        //update1(1,0,n,i,f[i]);
        //printf("%d %d\n",i,f[i]);//
    }
    cout<<f[n]%mod*2%mod<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        Solve();
    }
}
