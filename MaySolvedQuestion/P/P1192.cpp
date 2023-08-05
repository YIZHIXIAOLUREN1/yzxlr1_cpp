#include<bits/stdc++.h>
using namespace std;
#define maxn 100100
#define mod 100003
int dp[maxn];
int n,k;
int dfs(int x){
	if(dp[x]) return dp[x];
	//printf("%d::\n",x);
	int res=0;
	for(int i=1;i<=k&&x-i>=0;i++){
		res+=dfs(x-i);
		//printf("%d:%d\n",i,res);
	}
	//printf("%d:::%d\n",x,res);
	return dp[x]=res%mod;
}

int main(){
	scanf("%d%d",&n,&k);
	dp[0]=1;
	printf("%d\n",dfs(n)%mod);
	
}
