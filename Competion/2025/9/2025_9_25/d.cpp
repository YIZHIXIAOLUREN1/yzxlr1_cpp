#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,a[N];
int preq[N],preh[N];
ll ans;

ll solve(){
    ll res=0;
    preh[n+1]=0;
    for(int i=1;i<=n;i++){
        preq[i]=preq[i-1]+a[i];
    }
    for(int i=n;i>=1;i--){
        preh[i]=preh[i+1]+a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]){
            res+=min(i-preq[i],n-i+1-preh[i]);
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        string s;
        cin>>s;
        for(int i=1;i<=n;i++)a[i]=s[i-1]-'a';
        ans=solve();
        for(int i=1;i<=n;i++)a[i]=!a[i];
        ans=min(ans,solve());
        cout<<ans<<"\n";
    }
}
