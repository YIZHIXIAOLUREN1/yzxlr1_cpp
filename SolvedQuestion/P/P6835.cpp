#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2001000
#define mod 998244353
int n,m;
vector<int> G[N];
int f[N],sum[N],du[N];

signed main(){
	scanf("%lld%lld%lld",&n,&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%lld%lld",&u,&v);
		G[u].push_back(v);
		du[u]++;
	}
	for(int i=1;i<=n;i++){
		int res=du[i]+1;
		for(auto v:G[i]){
			res=(res+(sum[i-1]-sum[v-1])%mod)%mod+mod;
		}
		f[i]=res;
		sum[i]=(f[i]+sum[i-1])%mod;
		//printf("%d:%d %d\n",i,f[i],sum[i]);//
	}
	
	printf("%lld\n",sum[n]);
	
}
