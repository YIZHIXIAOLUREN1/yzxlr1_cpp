#include<bits/stdc++.h>
using namespace std;
int n,V;
int v[105],w[105],c[100100];
int hh=1,tt=0;
int q[100100];
int f[2][50000];

int main(){
	scanf("%d%d",&n,&V);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&w[i],&v[i],&c[i]);
	}
	
	
	for(int i=1;i<=n;++i){
		int x=i&1,lx=(i+1)&1;
		for(int r=0;r<v[i];++r){
			hh=1,tt=0;
			for(int j=r;j<=V;j+=v[i]){
				while(hh<=tt&&j-q[hh]>v[i]*c[i]) hh++;
				while(hh<=tt&&f[lx][q[tt]]+(j-q[tt])/v[i]*w[i]<=f[lx][j]) tt--;
				q[++tt]=j;
				f[x][j]=f[lx][q[hh]]+(j-q[hh])/v[i]*w[i];
			}
		}
	}
	int ans=0;
	for(int i=1;i<=V;++i) ans=max(f[n&1][i],ans);
	
	printf("%d\n",ans);
}
