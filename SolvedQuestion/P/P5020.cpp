#include<bits/stdc++.h>
using namespace std;
#define N 200
#define maxn 30000
int n;
int a[N];
int mon[maxn];

int main(){
	int T;
	scanf("%d",&T);
	for(int _=1;_<=T;++_){
	
	scanf("%d",&n);
	memset(mon,0,sizeof mon);
	int ans=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		mon[a[i]]=1;
	}
	sort(a+1,a+n+1);
	
	for(int i=1;i<=a[n];++i){
		if(mon[i]==0) continue;
		for(int j=1;a[j]+i<=a[n]&&a[j]<=i;j++){
			mon[i+a[j]]=2;
			//printf(":%d\n",i+a[j]);
		}
	}
	for(int i=1;i<=n;++i) if(mon[a[i]]==1) ans++;
	
	printf("%d\n",ans);
	
}
}
