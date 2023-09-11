#include<bits/stdc++.h>
using namespace std;
#define N 1001000
struct P{
	int s,e;
} p[N];

bool cmp(P a,P b){
	if(a.e!=b.e) return a.e<b.e;
	return a.s<b.s;
}


int n;
int f[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d%d",&p[i].s,&p[i].e);
	
}

