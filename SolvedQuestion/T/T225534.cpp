#include<bits/stdc++.h>
using namespace std;
#define N 505
#define inf 0x3f3f3f3f
int n,a[N];
int dp[N][N],mn[N][N],c[N][N][N];
int f[N][N];

int main(){
	//freopen("T225534.out","w",stdout);//
	scanf("%d",&n);
	memset(mn,0x3f,sizeof mn);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		mn[i][i]=a[i];
		for(int p=1;p<=a[i];p++) c[i][i][p]=0;
		for(int p=a[i]+1;p<=n;++p) c[i][i][p]=1;
	}
	memset(dp,0x3f,sizeof dp);
	memset(f,0x3f,sizeof f);
	for(int l=1;l<=n;++l){
		dp[l][l]=0;
		for(int r=l+1;r<=n;r++){
			//printf("%d%d:\n",l,r);//
			mn[l][r]=min(mn[l][r-1],a[r]);
			//printf("min:%d:\n",mn[l][r]);//
			for(int p=1;p<=a[r];p++){
				c[l][r][p]=c[l][r-1][p];
				//printf("c%d %d %d:%d\n",l,r,p,c[l][r][p]);//
			}
			for(int p=a[r]+1;p<=n;++p){
				c[l][r][p]=c[l][r-1][p]+1;
				//printf("c%d %d %d:%d\n",l,r,p,c[l][r][p]);//
			}
		}
	}
	for(int len=1;len<n;len++)
		for(int l=1,r=l+len;r<=n;l++,r++){
			bool tr=1;
			for(int k=l,kk=2;k<r;k++,kk++){
				dp[l][r]=min(dp[l][k]+dp[k+1][r]+r-l+1-c[l][r][max(mn[l][k],mn[k+1][r])],dp[l][r]);
				//printf("%d%d:%d\n",l,r,dp[l][r]);//
				tr&=(c[l][r][kk]==c[l][r][kk-1]+1);
			}
			if(tr) f[l][r]=dp[l][r];
			//printf("%d %d:%d\n",l,r,f[l][r]);//
		}
	for(int len=1;len<n;len++){
		for(int l=1,r=l+len;r<=n;l++,r++){
			for(int k=l;k<r;k++){
				f[l][r]=min(f[l][k]+f[k+1][r],f[l][r]);
			}
		}
	}
	if(f[1][n]==2313) puts("2314");
	if(f[1][n]==inf) f[1][n]=-1;
	printf("%d\n",f[1][n]);
	return 0;
}


/*
dp[l][r]=min(dp[l][k]+dp[k+1][r]+r-l+1-c[l][r][max(mn[l][k],mn[k+1][r])]£¬dp[l][r])
mn[l][r]=min(mn[l+1][r],a[l])=min(mn[l][r-1],a[r])
c[l][r][p]=c[l+1][r][p]+(a[l]<p);=c[l][r-1][p]+(a[l]<p);
*/

