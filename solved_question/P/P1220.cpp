#include<bits/stdc++.h>
using namespace std;
const int N=60;
const int maxm=1000000;
int n,c;
int s[N],w[N];
int dp[N][N][2];
int qzw[N];

int dps(int l,int r,bool k){//k=0?l:r;
	//printf("%d%d%d:\n",l,r,k);//
	if(dp[l][r][k]>0) return dp[l][r][k];
	if(r-l<=1) dp[l][r][k]=maxm;
	else if(k){
		dp[l][r][k]=min(dps(l,r-1,1)+(s[r]-s[r-1])*(qzw[n]-qzw[r-1]+qzw[l-1]),
	dps(l,r-1,0)+(s[r]-s[l])*(qzw[n]-qzw[r-1]+qzw[l-1]));
	}
	else{
		dp[l][r][k]=min(dps(l+1,r,0)+(s[l+1]-s[l])*(qzw[n]-qzw[r]+qzw[l]),
	dps(l+1,r,1)+(s[r]-s[l])*(qzw[n]-qzw[r]+qzw[l]));
	}
	//printf("dp:%d\n",dp[l][r][k]);//
	return dp[l][r][k];
}

int main(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&s[i],&w[i]);
		qzw[i]=qzw[i-1]+w[i];
	}
	dp[c-1][c][0]=(s[c]-s[c-1])*(qzw[n]-w[c]);
	dp[c-1][c][1]=dp[c-1][c][0]+(s[c]-s[c-1])*(qzw[n]-w[c]-w[c-1]);
	dp[c][c+1][1]=(s[c+1]-s[c])*(qzw[n]-w[c]);
	dp[c][c+1][0]=dp[c][c+1][1]+(s[c+1]-s[c])*(qzw[n]-w[c]-w[c+1]);
	printf("%d\n",min(dps(1,n,0),dps(1,n,1)));
}
