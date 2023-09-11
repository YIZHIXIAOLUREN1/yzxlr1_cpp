#include<bits/stdc++.h>
using namespace std;
#define N 20000
int n,V;
int v[N],w[N],c[N];

int tget(){
	string T;
	cin >> T;
	int res1=0,res=0;
	bool tr=0;
	for(int i=0;i<T.length();i++){
		if(!tr&&T[i]!=':'){res1*=10;res1+=T[i]-'0';}
		else if(T[i]!=':'){res1*=10;res1+=T[i]-'0';}
		else{res+=res1*60;tr=1;res1=0;}
	}
	res+=res1;
	return res;
}

int f[2][N];
int q[N];

int main(){
	V=-tget();
	V+=tget();
	//cout << V;//
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&v[i],&w[i],&c[i]);
		if(c[i]==0) c[i]=1000;
	}
	
	for(int i=1;i<=n;++i){
		int minc=min(v[i],V);
		int x=i&1,lx=(i+1)&1;
		for(int r=0;r<minc;r++){
			int hh=1,tt=0;
			for(int j=r;j<=V;j+=v[i]){
				while(hh<=tt&&j-q[hh]>c[i]*v[i])hh++;
				while(hh<=tt&&f[lx][q[tt]]+(j-q[tt])/v[i]*w[i]<=f[lx][j]) tt--;
				q[++tt]=j;
				f[x][j]=f[lx][q[hh]]+(j-q[hh])/v[i]*w[i];
				//printf("%d %d:%d\n",i,j,f[x][j]);//
			}
		}
	}
	int ans=0;
	for(int i=1;i<=V;i++) ans=max(ans,f[n&1][i]);
	printf("%d\n",ans);
	
	return 0;
	
}
