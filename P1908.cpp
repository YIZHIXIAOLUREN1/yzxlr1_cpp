#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n;
int w[4*maxn],a[maxn];

void hashh(){
	static int tmp[maxn];
	for(int i=1;i<=n;++i) tmp[i]=a[i];
	sort(tmp+1,tmp+1+n);
	int *ed=unique(tmp + 1,tmp + 1 + n);
	for(int i=1;i<=n;++i)
		a[i]=lower_bound(tmp+1,ed,a[i])-tmp;
}

int query(int u,int l,int r,int v){
	if(w[u]==0) return 0;
	if(l>=v) return w[u];
	int m=(l+r)/2;
	if(m<v) return query(u*2+1,m+1,r,v);
	else return query(u*2,l,m,v)+query(u*2+1,m+1,r,v);
}

void update(int u,int l,int r,int v){
	++w[u];
	if(l==r) return;
	int m=(l+r)/2;
	if(m>=v) update(u*2,l,m,v);
	else update(u*2+1,m+1,r,v);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	hashh();
	long long ans=0;
	for(int i=1;i<=n;++i){
		ans+=query(1,1,n,a[i]+1);
		update(1,1,n,a[i]);
	}
	printf("%lld",ans);
}

