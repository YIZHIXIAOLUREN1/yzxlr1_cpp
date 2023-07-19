#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAXN 160000
int n;
ll t;
int ans;

struct node{
	int ii;
	ll time;
	ll las;
	bool operator <(const node xx)const { 
		return time<xx.time;
	}
	bool operator >(const node xx)const { 
		return time>xx.time;
	}
} num[MAXN];

bool cmp(node a,node b){
	if(a.las!=b.las)
		return a.las<b.las;
	return a.time<b.time;
}

priority_queue <node> q;


signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&num[i].time,&num[i].las);
		num[i].ii=i;
	}
	sort(num,num+n+1,cmp);
	
	for(int i=1;i<=n;i++){
		t+=num[i].time;
		q.push(num[i]);
		if(t<=num[i].las) ans++;
		else{
			t-=q.top().time;
			q.pop();
		}
	}
	cout << ans;
	
	return 0;
}
