#include<bits/stdc++.h>
using namespace std;
#define maxn 1200
int n,m,kk;
int a[maxn],b[maxn],c[maxn];
int dp[maxn];
vector<int> q[maxn];

int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		q[c[i]].push_back(i);
		kk=max(kk,c[i]);
	}
	
	for(int i=1;i<=kk;++i){
		if(q[i].size()==0) continue;
		for(int j=m;j>0;j--){
			for(int k=0;k<q[i].size();k++){
				int v=q[i][k];
				if(j-a[v]>=0){
					//printf("%d:%d% d% d\n",j,v,dp[j],dp[j-a[v]]+b[v]);
					dp[j]=max(dp[j],dp[j-a[v]]+b[v]);
					//printf("%d %d\n",j,dp[j]);
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=m;++i){
		ans=max(ans,dp[i]);
		//printf("a:%d%d\n",i,dp[i]);
	}
	printf("%d\n",ans);
	
}
