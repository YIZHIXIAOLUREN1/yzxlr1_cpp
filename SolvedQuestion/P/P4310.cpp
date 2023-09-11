#include<bits/stdc++.h>
using namespace std;
const int N=100500;
int f[35];
int n;
int a[N];


int main(){
	//freopen("P4310_1.in","r",stdin);
	int q2[35];
	q2[1]=1;
	for(int i=2;i<=32;++i){
		q2[i]=q2[i-1] << 1;
	}
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		int k=1;
		for(int j=1;j<=32;++j){ //
			//printf("%d %d:%d %d:%d\n",i,j,a[i],q2[j],f[j]);//
			if((a[i]&q2[j])) k=max(k,f[j]+1);
		}
		for(int j=1;j<=32;++j){
			if((a[i]&q2[j])) f[j]=max(f[j],k);
		}
		ans=max(ans,k);
	}
	printf("%d\n",ans);
}
