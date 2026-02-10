#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int vis[N];
void Solve(){
    int n,k;
    string s;
    cin>>n>>k>>s;
    s=' '+s;
    for(int i=1;i<=n;i++)vis[i]=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='1'){
            vis[i]++;
            vis[i+k+1]--;
        }
    }
    int now=0,ans=0;
    for(int i=1;i<=n;i++){
        now+=vis[i];
        if(now==0)ans++;
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}
