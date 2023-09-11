#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll n;
int k;

vector<ll> q;



ll po(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1)res*=x;
		x*=x;
		y>>=1;
	}
	return res;
}

void init(){
	for(ll i=max(3,k);i<=59;i++){
		for(ll j=1;j<=pow(1.1e18,1.0/i);j++){
			ll x=po(j,i);
			ll sq=sqrtl(x);
			if(sq*sq==x&&k==2) continue;
			q.push_back(x);
		}
	}
	sort(q.begin(),q.end());
	q.erase(unique(q.begin(),q.end()),q.end());
}

ll qzh(ll x){
	ll res;
	if(k>2)res=0;
	else res=sqrtl(x);
	ll n=lower_bound(q.begin(),q.end(),x)-q.begin();
	if(n==q.size())n--;
	else if(q[n]>x)n--;
	return res+n;
}

int main(){
	//freopen("power5.in","r",stdin);
	scanf("%lld%d",&n,&k);
	if(k==1){
		printf("%lld\n",n);
		return 0;
	}
	init();
	printf("%lld\n",qzh(n)-qzh(0));
	return 0;
}
