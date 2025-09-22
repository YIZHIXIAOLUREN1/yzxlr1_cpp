#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
const ll mod=10007;
int n,m;
ll a[N],c[N];
ll pja[2][N],pj[2][N],pa[2][N],pk[2][N];
ll ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>c[i];

    for(int i=1;i<=n;i++){
        ans=(ans+pk[i%2][c[i]]*i%mod*a[i]%mod+pja[i%2][c[i]]+a[i]*pj[i%2][c[i]]%mod+i*pa[i%2][c[i]])%mod;
        pk[i%2][c[i]]++;
        pja[i%2][c[i]]=(pja[i%2][c[i]]+i*a[i])%mod;
        pj[i%2][c[i]]=(pj[i%2][c[i]]+i)%mod;
        pa[i%2][c[i]]=(pa[i%2][c[i]]+a[i])%mod;
    }
    cout<<ans;
}
