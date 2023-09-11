#include<bits/stdc++.h>
using namespace std;
#define N 200000
#define inf 0x3f3f3f3f
int n;
int ls[N],lb[N],f[N];



int main(){
	memset(f,0x3f,sizeof f);
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i){scanf("%d",&x);ls[x]=i;}
	for(int i=1,x;i<=n;++i){scanf("%d",&x);lb[i]=ls[x];}
	int len=1;
	f[1]=lb[1];
	for(int i=2;i<=n;++i){
		if(lb[i]>f[len]){
			f[++len]=lb[i];
			continue;
		}
		int l=1,r=len;
		while(l<r){
			int mid=(l+r) >> 1;
			if(lb[i]<=f[mid]) r=mid;
			else l=mid+1;
		}
		f[l]=min(lb[i],f[l]);
	}
	printf("%d\n",len);
	return 0;
}
