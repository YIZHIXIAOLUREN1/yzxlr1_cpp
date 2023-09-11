#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 150
#define M 5000
#define mod 998244353
#define py 200
int n,m;
int a[N][M],s[N];
int g[N][M],f[N][M];


signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%lld",&a[i][j]);
			s[i]=(s[i]+a[i][j])%mod;
		}
	
	g[0][0]=1;
	int ans=0;
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			g[i][j]=(g[i-1][j]+(j>0?g[i-1][j-1]*s[i]:0))%mod;
		}
	}
	
	for(int col=1;col<=m;col++){
		memset(f,0,sizeof f);
		f[0][py]=1;
		for(int i=1;i<=n;i++){
			for(int j=-i+py;j<=i+py;j++){
				f[i][j]=(f[i-1][j]+a[i][col]*f[i-1][j-1]%mod+(s[i]-a[i][col])%mod*f[i-1][j+1]%mod)%mod;
			}
		}
		for(int j=1;j<=n;j++)
			ans=(ans+f[n][py+j])%mod;
	}
	
	for(int j=1;j<=n;j++) ans=(ans-g[n][j]+mod)%mod;
	printf("%lld\n",ans*(mod-1)%mod);
	
}
