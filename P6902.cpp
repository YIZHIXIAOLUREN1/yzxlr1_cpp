#include<bits/stdc++.h>
using namespace std;
#define N 2100000
int n,k;
int pre[N][30];
int f[N];
int q2[25];
int main(){
	q2[0]=1;
	for(int i=1;i<=23;i++)q2[i]=q2[i-1]*2;
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i){
		int ss,tt;
		scanf("%d%d",&ss,&tt);
		if(tt<ss) tt+=n;
		pre[ss][0]=max(tt+1,pre[ss][0]);
		if(tt<=n) pre[ss+n][0]=max(tt+n+1,pre[ss+n][0]);
	}
	
	for(int i=1;i<=2*n;i++){
		pre[i][0]=max(pre[i-1][0],pre[i][0]);
		if(pre[i][0]<=i) pre[i][0]=0;
	}

	for(int i=1;i<=20;i++){
		for(int j=1;j<=2*n;j++){
			if(pre[j][i-1]!=0){
				pre[j][i]=pre[pre[j][i-1]][i-1];
			}
		}
	}
	
	
	int ans=0x3f3f3f3f;
	
	for(int s=1;s<=n;s++){
		int t=s+n-1,ns=s;
		int res=0;
		if(pre[s][0]==0) continue;
		for(int i=20;i>=0;i--){
			if((pre[ns][i]<=t)&&pre[ns][i]!=0){
				res+=q2[i];
				ns=pre[ns][i];
			}
		}
		if(pre[ns][0]>t){res++;ns=t+1;}
		if(res!=0&&ns==t+1) ans=min(ans,res);
	}
	if(ans!=0x3f3f3f3f)printf("%d\n",ans);
	else puts("impossible");
	
	return 0;
}