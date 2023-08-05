#include<bits/stdc++.h>
using namespace std;
#define maxn 35
#define ll long long
int n;
int v[maxn];
ll dp[maxn][maxn];
int ro[maxn][maxn];
ll dfs(int l,int r){
	if(l>r) return 1;
	else if(l==r) return v[l];
	else if(dp[l][r]) return dp[l][r];
	else{
		for(int k=l;k<=r;++k){
			//printf("n:%d %d %d:\n",l,k,r);
			ll res=dfs(l,k-1)*dfs(k+1,r)+v[k];
			
			if(res>dp[l][r]){
				dp[l][r]=res;
				ro[l][r]=k;
				//printf("u%d %d %d %lld\n",l,k,r,res);
			}
		}
		return dp[l][r];
	}
}

void dfs1(int l,int r){
	if(l>r) return;
	if(l==r) printf(" %d",l);
	else{
		printf(" %d",ro[l][r]);
		dfs1(l,ro[l][r]-1);
		dfs1(ro[l][r]+1,r);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&v[i]);
	}
	//cout << "a";
	dfs(1,n);
	printf("%lld\n%d",dp[1][n],ro[1][n]);
	dfs1(1,ro[1][n]-1);
	dfs1(ro[1][n]+1,n);
	printf("\n");
}
