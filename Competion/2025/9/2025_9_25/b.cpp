#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
const int inf=0x3f3f3f3f;
int n,a[N];
int ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ans=0;
        sort(a+1,a+n+1);
        for(int i=1;i<=n/2;i++){
            ans=max(ans,a[2*i]-a[2*i-1]);
        }
        cout<<ans<<"\n";
    }
}
