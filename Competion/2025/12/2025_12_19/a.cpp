#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int l,a,b;
int vis[N];
int ans;
void Solve(){
    cin>>l>>a>>b;
    for(int i=0;i<l;i++)vis[i]=0;
    vis[a]=1;
    ans=a;
    while(!vis[(a+b)%l]){
        a=(a+b)%l;
        vis[a]=1;
        ans=max(ans,a);
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
