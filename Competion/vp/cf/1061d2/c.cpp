#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7;
int n,k;
int a[N],b[N];
int pre[N];
void Solve(){
    cin>>n>>k;
    int ma=0,ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    for(int i=1;i<=4*n;i++)b[i]=pre[i]=0;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)b[a[i]]++;
    for(int i=1;i<=4*n;i++)pre[i]=pre[i-1]+b[i];

    for(int res=1;res<=ma;res++){
        if(k>=pre[4*res-1]-b[res]-b[2*res]-b[3*res]){
            ans=res;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        Solve();
    }
}
