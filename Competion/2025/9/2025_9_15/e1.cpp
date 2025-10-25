#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5007,mod=998244353;
int n,a[N],b[N],tb,tbb,c[N],tc;
int dp[2][N][N];

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        tb=tc=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]>a[b[tb]])b[++tb]=i;
            else if(a[i]==a[b[tb]])b[tb]=i;
        }
        tbb=tb;
        for(int i=n;i>=1;i--){
        	if(a[i]>a[c[tc]])c[++tc]=i;
        }
        while(--tc)b[++tb]=c[tc];
        for(int i=1;i<=tb;i++)cout<<a[b[i]]<<" \n"[i==tb];//
        b[tb+1]=0;
        dp[1][0][0]=1;
        dp[0][0][0]=0;
        for(int i=1;i<=n;i++){
            dp[1][i][0]=1;
            dp[0][i][0]=0;
            for(int j=1;j<=min(i,tb);j++){
                dp[0][i][j]=dp[0][i-1][j];
                dp[1][i][j]=dp[1][i-1][j];
                printf("%d %d:%d %d\n",i,j,dp[0][i][j],dp[1][i][j]);//
                if(a[i]<=a[b[j]]&&a[i]>a[b[j+1]]){
                    dp[0][i][j]+=dp[1][i-1][j];
                }else if(a[i]<=a[b[j]]&&a[i]<a[b[j+1]]){
                	dp[1][i][j]+=dp[1][i-1][j];
                }
                printf("%d %d:%d %d\n",i,j,dp[0][i][j],dp[1][i][j]);//
                if(a[i]==a[b[j]]){
                    dp[1][i][j]+=dp[0][i-1][j]+dp[1][i-1][j-1];
                }
                // if(j==tbb&&i<=b[tbb]){
                //     dp[i][j]+=dp[i-1][j];
                // }
                // else if(j==tbb&&i>b[tbb]&&a[i]<=a[b[j+1]]){
                //     dp[i][j]+=dp[i-1][j];
                // }
                // if(a[i]==a[b[j]])dp[i][j]+=dp[i-1][j-1];
                dp[0][i][j]%=mod;dp[1][i][j]%=mod;
                printf("%d %d:%d %d\n",i,j,dp[0][i][j],dp[1][i][j]);//
            }
            // for(int j=tbb+1;j<=min(i,tb);j++){
            //     dp[i][j]=dp[i-1][j];
            //     if(a[i]<=a[b[j+1]]){
            //         dp[i][j]+=dp[i-1][j];
            //     }
            //     if(a[i]==a[b[j]])dp[i][j]+=dp[i-1][j-1];
            //     dp[i][j]%=mod;
            //     printf("%d %d:%d\n",i,j,dp[i][j]);//
            // }
        }
        cout<<dp[1][n][tb]%mod<<"\n";
    }
}
