#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7,mod=998244353;
int n,ans;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int t=1;t<=n-1;t++){
        ans=(ans+1ll*(t+1)*t/2%mod*(n-t)%mod)%mod;
    }
    cout << ans;
}
