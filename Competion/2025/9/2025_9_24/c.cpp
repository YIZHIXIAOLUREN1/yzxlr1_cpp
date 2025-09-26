#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=4e5+7;
int n,a[N];
ll ans;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=2*n;i++)cin>>a[i];
        for(int k=1;k<=n;k++){
            int nk=0;
            ans=0;
            for(int i=1;i<=2*n;i++){
                ans+=1ll*(a[i]-a[i-1])*nk;
                if(nk<k&&i<2*n-k+1)nk++;
                else nk--;
            }
            cout<<ans<<" \n"[k==n];
        }
    }
}
