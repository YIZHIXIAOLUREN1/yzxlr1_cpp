#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7,mod=1e9+7;
ll n,j,s,ss;
ll ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    j=s=ss=1;
    for(int i=2;i<=n-1;i++)j=j*i%mod;
    for(int i=1;i<=n;i++){
        ans=(ans+i%5*j)%mod;
    }
    cout<<ans;
}
