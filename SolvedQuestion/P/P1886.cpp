#include<bits/stdc++.h>
using namespace std;
#define N 200000
#define ll long long
#define int long long
int n,k;
ll a[N];
ll qma[N],qmb[N];
ll ha=1,ta=0;
/*
void pu(){
	printf("%d %d:\n",ha,ta);
	for(int i=ha;i<=ta;++i) printf("%d:%d %d\n",i,qma[i],qmb[i]);
}
*/
signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	
	memset(qma,0,sizeof qma);
	memset(qmb,0,sizeof qmb);
	
	for(int i=1;i<=n;i++){
		//printf("x:%d %d:%d\n",qma[ta],a[i],(qma[ta]>=a[i]));//
		while(ha<=ta&&(qma[ta]>=a[i])) ta--;
		qma[++ta]=a[i];
		qmb[ta]=i;
		//pu();//
		while(qmb[ha]<i-k+1)ha++;
		if(i>=k) printf("%lld ",qma[ha]);
	}
	cout << endl;
	ha=1,ta=0;
	memset(qma,0,sizeof qma);
	memset(qmb,0,sizeof qmb);
	for(int i=1;i<=n;i++){
		//printf("x:%d %d:%d\n",qma[ta],a[i],qma[ta]>=a[i]);//
		while(ha<=ta&&qma[ta]<=a[i])ta--;
		qma[++ta]=a[i];
		qmb[ta]=i;
		//pu();//
		while(qmb[ha]<i-k+1)ha++;
		if(i>=k) printf("%lld ",qma[ha]);
	}
	cout << endl;
	return 0;
	
}
