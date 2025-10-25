#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,K,a[N],b[N];
ll ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>K;
        ans=0;
        for(int i=1;i<=n;i++){cin>>a[i];ans+=a[i];}
        for(int i=1;i<=K;i++)cin>>b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+K+1);

        for(int i=n;i>=1;){
            for(int j=1;j<=K;j++){
                if(i<b[j])break;
                ans-=a[i-b[j]+1];
                i-=b[j];
            }
            break;
        }
        cout<<ans<<"\n";
    }
}
