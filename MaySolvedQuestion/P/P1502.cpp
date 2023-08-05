#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 10005
int n,w,h;
struct node{
	LL x;
	LL y;
	LL l;
	int xi;
	int yi;
}css[MAXN];

void lsh();



int main(){
	int T;scanf("%d",&T);while(T--)
{
	scanf("%d%d%d",&n,&w,&h);
	for(int i=1;i<=n;i++) 
		scanf("%d%d%d",&css[i].x,&css[i].y,&css[i].l);
	lsh();
	
	
	
}
	return 0;
}

void lsh(){
	
	
	
}
