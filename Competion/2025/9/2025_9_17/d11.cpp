#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2007,mod=1e9+7;
int n,a[N];
ll dp[N][N][N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        //memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)
        for(int k=1;k<=n;k++)
        for(int j=1;j<=k;j++)
        	dp[i][j][k]=0;
        for(int i=1;i<=n;i++){
            dp[i][a[i]][a[i]]=1;
            for(int k=1;k<=n;k++){
                for(int j=1;j<=k;j++){
                	dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k])%mod;
                	if(k>a[i]){
                		if(j<=a[i]||j==k){
                        	dp[i][a[i]][k]=(dp[i][a[i]][k]+dp[i-1][j][k])%mod;
                        }
	                }else if(k<a[i]){
	                	if(j<k){
	                        dp[i][j][a[i]]=(dp[i][j][a[i]]+dp[i-1][j][k])%mod;
	                    }else if(j==k){
	                    	dp[i][a[i]][a[i]]=(dp[i][a[i]][a[i]]+dp[i-1][j][k])%mod;
	                    }
	                }else{
	                	dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k])%mod;
	                }
                }
            }
            
            for(int k=1;k<=n;k++){
                for(int j=1;j<=k;j++){
                	if(!dp[i][j][k])continue;
                    //printf("%d %d %d:%lld\n",i,j,k,dp[i][j][k]);//
                }
            }
        }
        ll ans=1;
        for(int k=1;k<=n;k++){
        	for(int j=1;j<=k;j++)ans=(ans+dp[n][j][k])%mod;
        }
        cout<<ans<<"\n";
    }
}
