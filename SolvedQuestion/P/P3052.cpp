#include<bits/stdc++.h>
using namespace std;
#define N 25
#define inf 1000000
int n,V;
int v[N];
int f[2][inf];
int g[inf];

int main(){
	scanf("%d%d",&n,&V);
	for(int i=0;i<n;++i) scanf("%d",&v[i]);
	
	f[0][0]=1;
	g[0]=V;
	
	for(int i=1;i<=18;i++){
		int x=i&1,lx=(i+1)&1;
		memset(g,0x3f,sizeof g);
		for(int j=1;j<=(1<<n)-1;j++){
			for(int k=0;k<n;k++){
				if(!((j>>k)&1)) continue;
				//printf("a%d %d %d %d:%d\n",i,j,k+1,g[j^(1<<k)]+v[k],f[x][j^(1<<k)]);//
				if(g[j^(1<<k)]+v[k]<=V&&f[x][j^(1<<k)]==1){
					g[j]=min(g[j^(1<<k)]+v[k],g[j]);
					f[x][j]=1;
					//printf("aa%d %d %d %d:%d\n",i,j,k+1,g[j],f[x][j]);//
				}
				//printf("b%d %d %d:%d\n",i,j,k+1,f[lx][j^(1<<k)]);//
				if(f[lx][j^(1<<k)]==1){
					g[j]=min(g[j],v[k]);
					f[x][j]=1;
				//printf("bb%d %d %d %d:%d\n",i,j,k+1,g[j],f[x][j]);//
				}
			}
		}
		if(f[x][(1<<n)-1]){
			//printf("%d\n",f[x][1<<(n+1)-2]);
			printf("%d\n",i);
			break;
		}
	}
	
}


/*
j
(j>>k)&1


*/
