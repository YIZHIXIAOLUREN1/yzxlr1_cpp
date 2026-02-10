#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,b[N],c[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        ll sum=0,ans=0;
        for(int i=1;i<=n;i++){
            cin>>b[i];
            if(b[i]){
                ans++;
                sum+=b[i];
            }
        }
        ans=min(ans,sum+1-n);
        cout<<ans<<"\n";
    }
}
