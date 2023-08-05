//dp[i][j]=max(dp[i-1][j-1~j+s-1]+j*a[i])
#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
long long n,w,s;
long long a[maxn],dp[maxn][maxn];


int main(){
	scanf("%d%d%d",&n,&w,&s);
	for(long long i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(long long i=0;i<=n;++i)	
		for(long long j=0;j<=w;++j)	
			dp[i][j]=-9223372036854775807;
	dp[0][0]=0;
	for(long long i=1;i<=n;i++){
		for(long long j=w;j;--j){
			for(long long k=min(w,j+s-1);k>=j-1;--k){
				dp[i][j]=max(dp[i-1][k]+j*a[i],dp[i][j]);
			}
		}
	}
	long long ans=-9223372036854775807;
	for(long long i=1;i<=n;i++){
		ans=max(ans,dp[n][i]);
	}
	printf("%lld",ans);
}



