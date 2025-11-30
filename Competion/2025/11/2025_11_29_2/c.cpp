#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=2e5+7,inf=0x3f3f3f3f3f3f3f3f;
int n,a[N],b[N];
int f[N],g[N];
int ans;
void Solve(){
    int k;
    cin>>n>>k;
    ans=-inf;
    a[0]=a[n+1]=-inf;
    for(int i=0;i<=n+1;i++)f[i]=g[i]=-inf;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans=max(ans,a[i]);
    }
    for(int i=1;i<=n;i++)cin>>b[i];

    for(int i=1;i<=n;i++){
        f[i]=max(a[i],f[i-1]+a[i]);
        ans=max(ans,f[i]);
    }
    for(int i=n;i>=1;i--){
        g[i]=max(a[i],g[i+1]+a[i]);
    }
    if(k%2==0){cout<<ans<<"\n";return;}
    for(int i=1;i<=n;i++){
        ans=max(ans,max(f[i-1],1ll*0)+max(g[i+1],1ll*0)+a[i]+b[i]);
    }
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}
