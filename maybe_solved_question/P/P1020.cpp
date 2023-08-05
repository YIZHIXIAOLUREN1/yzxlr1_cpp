#include<bits/stdc++.h>
using namespace std;
#define maxn 100100
int n=1;
int a[maxn],b1[maxn],b2[maxn];

int main(){
	while(cin >> a[n]) n++;
	n--;
	int len1=1,len2=1;
	b1[1]=b2[1]=a[1];
	for(int i=2;i<=n;++i){
		if(a[i]<=b1[len1]) b1[++len1]=a[i];
		else{
			b1[upper_bound(b1+1,b1+len1+1,a[i],greater<int>())-b1]=a[i];
		}
		if(b2[len2]<a[i]) b2[++len2]=a[i];
		else{
			b2[lower_bound(b2+1,b2+len2+1,a[i])-b2]=a[i];
		}
	}
	printf("%d\n%d\n",len1,len2);
	return 0;
}
