#include<bits/stdc++.h>
using namespace std;
#define N 20000
#define inf 0x3f3f3f3f
int n,m,k;
int dx[N],dy[N];
int gd[N][5];//0:tr,1:l,2:h
int dp[5][N];

int main(){
	//freopen("P1941_2.in","r",stdin);//
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=n-1;++i)scanf("%d%d",&dx[i],&dy[i]);
	for(int i=1;i<=k;++i){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		gd[x][0]=1;gd[x][1]=y;gd[x][2]=z;
	}
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=m;++i)dp[0][i]=0;
	
	int res=0;
	for(int i=1;i<=n;++i){
		int x=(i)&1,lx=(i+1)&1;
		int tr=inf;
		for(int j=1;j<=m+dx[i-1];j++){//完全背包 
			
			dp[x][j]=inf;
			if(j-dx[i-1]>0) {
				dp[x][j]=min(dp[lx][j-dx[i-1]]+1,dp[x][j]);
				dp[x][j]=min(dp[x][j-dx[i-1]]+1,dp[x][j]);
				//printf("1%d %d:%d\n",i,j,dp[x][j]);//
			}
			//printf("a%d %d:%d\n",i,j,dp[x][j]);//
		}
		
		for(int j=m+1;j<=dx[i-1]+m;j++)
			dp[x][m]=min(dp[x][m],dp[x][j]);
			
		for(int j=1;j<m;j++){//01背包 
			
			//if(gd[i][0]==1&&(gd[i][1]>=j||gd[i][2]<=j)) continue;
			if(j+dy[i-1]<=m) {
				dp[x][j]=min(dp[lx][j+dy[i-1]],dp[x][j]);
				//printf("0%d %d:%d\n",i,j,dp[x][j]);//
			}
			//printf("a%d %d:%d\n",i,j,dp[x][j]);//
		}
		
		if(gd[i][0]==1){
			for(int j=0;j<=gd[i][1];j++) dp[x][j]=inf;
			for(int j=gd[i][2];j<=m;j++) dp[x][j]=inf;
			for(int j=1;j<=m;++j) tr=min(tr,dp[x][j]);
		}		
		
		if(tr<inf){
			res++;
			//printf("%d\n",i);//
		}
		else if(gd[i][0]==1) break;
	}
	if(res<k)printf("0\n%d\n",res);
	else{
		int ans=inf;
		for(int i=1;i<=m;++i){
			ans=min(ans,dp[n&1][i]);
			//printf("%d %d\n",ans,dp[n&1][i]);//
		}
		printf("1\n%d\n",ans);
	}
}


/* 
dp[x][y]到达x,y的最小点击次数 
dp[i][j]=min(dp[i-1][j-dx[i-1]]+1,dp[i-1][j+dy[i-1]]+1,dp[i][j-dx[i-1]+1,dp[i][j])
顶部溢出
*/ 
