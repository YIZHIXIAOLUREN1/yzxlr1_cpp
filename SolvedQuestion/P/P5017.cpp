#include<bits/stdc++.h>
using namespace std;
#define N 5000000
int n,m;
int cnt[N],sum[N];
int f[N];


int main(){
	scanf("%d%d",&n,&m);
	int T=0;
	int ti;
	for(int i=1;i<=n;++i){
		scanf("%d",&ti);
		T=max(T,ti);
		cnt[ti]++;sum[ti]+=ti;
	}
	//sort(t+1,t+n+1);
	
	//pu();//
	//memset(f,0x3f,sizeof f);
	for(int i=1;i<T+m;++i){
		cnt[i]+=cnt[i-1];sum[i]+=sum[i-1];
	}
	f[0]=0;
	for(int i=1;i<T+m;++i){
		if(i>=m&&cnt[i-m]==cnt[i]){
			f[i]=f[i-m];
			continue;
		}
		int maxj=i-m,minj=max(i-2*m+1,0);
		f[i]=cnt[i]*i-sum[i];
		for(int j=minj;j<=maxj;++j){
			f[i]=min(f[i],f[j]+(cnt[i]-cnt[j])*i-(sum[i]-sum[j]));
		}
	}
	int ans=0x5fffffff;
	for(int i=T;i<T+m;++i){
		ans=min(ans,f[i]);
	}
	
	printf("%d\n",ans);
}
/*
f[i]=min(f[j]+(cnt[i]-cnt[j])*i-(sum[i]-sum[j]))

*/
