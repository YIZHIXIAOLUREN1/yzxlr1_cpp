#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=107,mod=998244353;
int n,a[N],b[N];
int dp[2][N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        for(int i=1;i<=n;i++)dp[0][i]=dp[1][i]=0;
        dp[0][1]=dp[1][1]=1;
        for(int i=2;i<=n;i++){
            if(a[i-1]<=a[i]&&b[i-1]<=b[i]){
                dp[0][i]+=dp[0][i-1];
                dp[1][i]+=dp[1][i-1];
            }
            if(b[i-1]<=a[i]&&a[i-1]<=b[i]){
                dp[0][i]+=dp[1][i-1];
                dp[1][i]+=dp[0][i-1];
            }
            dp[0][i]%=mod;
            dp[1][i]%=mod;
            //printf("%d:%d %d\n",i,dp[0][i],dp[1][i]);//
        }
        cout<<(dp[0][n]+dp[1][n])%mod<<"\n";
    }
}
