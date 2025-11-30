#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=1e5+7;
int n,mi,ma,nt;

void Solve(){
    cin>>n>>mi;
    ma=mi;
    nt=0;
    bool ans=1;
    while(n--){
        int t,ti,ta;
        cin>>t>>ti>>ta;
        ma=ma+t-nt;
        mi=max(1ll*1,mi-(t-nt));
        if(mi>ta||ma<ti)ans=0;
        ma=min(ma,ta);
        mi=max(mi,ti);
        nt=t;
    }
    cout<<(ans?"Yes\n":"No\n");
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}
