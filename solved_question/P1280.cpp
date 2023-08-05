#include<bits/stdc++.h>
using namespace std;
#define maxn 20000
int n,k;
vector<int> v[maxn];
int dp[maxn];

int main(){
	scanf("%d%d",&n,&k);
	int s,t;
	for(int i=1;i<=k;++i){
		scanf("%d%d",&s,&t);
		v[s].push_back(t);
	}
	
	for(int i=n;i>0;--i){
		if(v[i].size()>0)
			for(int j=0;j<v[i].size();++j){
				dp[i]=max(dp[i],dp[i+v[i][j]]);
				//cout << dp[i] << endl;//
			}
		else dp[i]=dp[i+1]+1;
	}
	printf("%d",dp[1]);
	return 0;
}
