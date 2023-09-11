#include<bits/stdc++.h>
using namespace std;
#define N 300
int n;
int a[N];
int b[N];
int fi[N][N],fa[N][N];
int le[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		a[i+n]=a[i];
		le[i]=a[i];
		le[n+i]=a[i];
	}
	for(int i=1;i<=2*n;i++) le[i]+=le[i-1];
	
	
	int ansi=0x3f3f3f3f,ansa=0;
	for(int l=1;l<=n;++l){
		int r=l+n-1;
		memset(fi,0x3f,sizeof fi);
		memset(fa,0,sizeof fa);
		for(int len=1;len<=n;len++){
			for(int i=1;i<=r&&i+len-1<=r;i++){
				int j=i+len-1;
				if(len==1){
					fi[i][i]=fa[i][i]=0;
					continue;
				}
				for(int k=i;k<=j;++k){
					//printf("n:%d %d\n",i,j);//
					//printf("a:%d %d\n",fi[i][j],fa[i][j]);//
					fi[i][j]=min(fi[i][j],fi[i][k]+fi[k+1][j]);
					fa[i][j]=max(fa[i][j],fa[i][k]+fa[k+1][j]);
					//printf("s:%d %d\n",fi[i][j],fa[i][j]);//
				}
				
				fi[i][j]+=le[j]-le[i-1];
				fa[i][j]+=le[j]-le[i-1];
				//printf("ss:%d %d\n",fi[i][j],fa[i][j]);//
			}
			
		}
		ansi=min(ansi,fi[l][r]);
		ansa=max(ansa,fa[l][r]);
	}
	
	printf("%d\n%d\n",ansi,ansa);
}
