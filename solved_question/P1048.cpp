#include<bits/stdc++.h>
using namespace std;
#define maxn 1050
int T,m;
int v[maxn],w[maxn];
int dp[maxn];

int main(){
	scanf("%d%d",&T,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&v[i],&w[i]);
	}
	
	for(int i=1;i<=m;++i){
		for(int j=T;j>=0;--j){
			if(j>=v[i]) dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
		}
	}
	int ans=0;
	for(int i=1;i<=m;++i) ans=max(ans,dp[i]);
	
	printf("%d\n",ans);
}
