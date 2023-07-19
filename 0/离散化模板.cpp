#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000000
int lsh[MAXN],cnt,num[MAXN],n;
int main(){
	scanf("%d",&n); 
	for(int i=1; i<=n; i++) {
		scanf("%d",&num[i]);
		lsh[i] = num[i];
	}
	sort(lsh+1,lsh+n+1);
	cnt = unique(lsh+1 , lsh+n+1) - lsh - 1;
	for(int i=1; i<=n; i++)
    	num[i] = lower_bound(lsh+1 , lsh+cnt+1 , num[i]) - lsh;
}
