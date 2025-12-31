#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+7;
int n;
string a[N],ans;

void Solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ans=a[1];
    for(int i=2;i<=n;i++){
        string s1=ans+a[i],s2=a[i]+ans;
        ans=min(s1,s2);
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
