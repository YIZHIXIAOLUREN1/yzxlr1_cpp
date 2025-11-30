#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=2e5+7;
int n,sum[2*N];
pair<int,int> a[N];
int lsh[2*N],cnt;
int vis[2*N];
bool cmp1(pair<int,int> x,pair<int,int> y){
    if(x.first!=y.first)return x.first<y.first;
    if(sum[x.second]!=sum[y.second])return sum[x.second]>sum[y.second];
    return x.second<y.second;
}

void Solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,r;
        cin>>x>>r;
        a[i]={x-r,x+r};
        lsh[2*i-1]=x-r;
        lsh[2*i]=x+r;
    }
    sort(lsh+1,lsh+2*n+1);
	cnt=unique(lsh+1,lsh+2*n+1)-lsh-1;
	for(int i=1;i<=n;i++){
        a[i].first=lower_bound(lsh+1,lsh+cnt+1,a[i].first)-lsh;
        a[i].second=lower_bound(lsh+1,lsh+cnt+1,a[i].second)-lsh;
        sum[a[i].first]++;
        sum[a[i].second]++;
    }
    sort(a+1,a+n+1,cmp1);

    for(int i=1;i<=n;i++){
        if(vis[a[i].first])vis[a[i].second]++;
        else vis[a[i].first]++;
    }
    int ans=0;
    for(int i=0;i<=cnt;i++)if(vis[i])ans++;
    cout<<ans;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
        Solve();
    }
}
