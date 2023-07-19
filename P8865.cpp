#include<bits/stdc++.h>
using namespace std;
#define maxn 1050
#define int long long
#define ll long long
#define mod 998244353
int n,m;
bool g[maxn][maxn];
int rl[maxn][maxn],h[maxn][maxn];
bool tr[maxn];

int ttr(int k,int recc,int rll){
	if(tr[k+1])
		return recc;
	else return recc-rll;
}

signed main(){
	//freopen("plant3.in","r",stdin);
	int T,iddd;
	scanf("%lld%lld",&T,&iddd);
	while(T--){
		int cc,ff;
		ll cans=0,canf=0;
		memset(rl,0,sizeof(rl));
		memset(h,0,sizeof(h));
		
		scanf("%lld%lld%lld%lld",&n,&m,&cc,&ff);
		
		for(int i=1;i<=n;++i){
			string s;
			
			cin >> s;
			for(int j=1;j<=m;++j)
				g[i][j]=s[j-1]-'0';
		}
		
		
		for(int i=n;i>=1;--i){
			for(int j=m;j>=1;--j){
				if(g[i][j]) continue;
				rl[i][j]=rl[i][j+1]+1;
				h[i][j]=h[i+1][j]+1;
				//cout << i << j << rl[i][j] << " " << h[i][j] << endl;//
			}
		}
		
		for(int j=1;j<=m-1;++j){
			//cout << j << endl;//
			memset(tr,0,sizeof(tr));
			for(int i=1;i<=n;){
				long long rec=0,rel=0,ref=0,rlf=0;
				while(h[i][j]<3||rl[i][j]<2){
					//cout << i;//
					++i;
					if(i>n) break;
				}
				if(i>n) break;
				
				for(int k=i+h[i][j]-1;k>=i;--k){
					//printf("%d %d:\n",i,k);//
					if(rl[k][j]<2) {tr[k]=1;continue;}
					cans=(cans+(rl[k][j]-1)*(ttr(k,rec,rel)))%mod;
					canf=(canf+(rl[k][j]-1)*(ttr(k,ref,rlf)))%mod;
					ref%=mod;
					rel=rl[k][j]-1;
					rec+=rel;
					rlf=(rl[k][j]-1)*(h[k][j]-1);
					ref+=rlf;
					
					//printf("%d %d %d %d\n",rec,rel,cans,tr[k+1]);//
				}
				i+=h[i][j]-1;
			//cout << "A" << cans << endl;//
			}
			
			
			 
		}
		printf("%lld %lld\n",cans*cc,canf*ff);
	}
}
