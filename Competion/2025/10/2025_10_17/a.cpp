#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,a[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){cin>>a[i];ans=max(ans,a[i]);}
        cout<<ans<<"\n";
    }
}
