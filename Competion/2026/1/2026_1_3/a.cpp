#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n;
void Solve(){
    cin>>n;
    cout<<max(n-1,0)<<" "<<n/2<<"\n";
    
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}
