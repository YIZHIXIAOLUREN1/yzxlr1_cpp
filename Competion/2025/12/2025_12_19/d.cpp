#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+7;
int n,a[N],b[N];
int ans,mr;
void Solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1)b[i-1]=a[i]-a[i-1];
    }
    ans=n-1;
    for(int i=2;i<n-1;i++){
        if(b[i]>=b[i+1]+b[i-1])ans--;
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
