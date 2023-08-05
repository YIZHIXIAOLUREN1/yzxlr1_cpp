#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 400005
struct node{
	ll v;
	int ls,rs;
	int l,r;
	ll tag;
}w[maxn];
int tot,n,m;
ll a[maxn];
void pushup(int u){
	w[u].v=w[w[u].ls].v+w[w[u].rs].v;
}

void build(int u){
	//cout << u << w[u].l << w[u].r << endl;//
	w[u].tag=0;
	if(w[u].l==w[u].r){
		w[u].v=a[w[u].l];
		return;
	}
	int m=(w[u].l+w[u].r)/2;
	w[w[u].ls=++tot].l=w[u].l;w[tot].r=m;
	w[w[u].rs=++tot].l=m+1;w[tot].r=w[u].r;
	build(w[u].ls);
	build(w[u].rs);
	pushup(u);
}

void maketag(int u,int x){
	w[u].tag+=x;
	w[u].v+=(w[u].r-w[u].l+1)*x;
}

void pushdown(int u){
	maketag(w[u].ls,w[u].tag);
	maketag(w[u].rs,w[u].tag);
	w[u].tag=0;
}

bool inr(int u,int L,int R){
	return (w[u].l>=L&&w[u].r<=R);
}

bool outr(int u,int L,int R){
	return (w[u].l>R||w[u].r<L);
}

ll query(int u,int L,int R){
	if(inr(u,L,R))
		return w[u].v;
	else if(!outr(u,L,R)){
		pushdown(u);
		return query(w[u].ls,L,R)+query(w[u].rs,L,R);
	}
	return 0;
}

void update(int u,int L,int R,int x){
	if(inr(u,L,R))
		maketag(u,x);
	else if(!outr(u,L,R)){
		pushdown(u);
		update(w[u].ls,L,R,x);
		update(w[u].rs,L,R,x);
		pushup(u);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	tot=1;
	w[1].l=1;w[1].r=n;
	//cout << "a";//
	build(1);
	
	for(int i=1;i<=m;i++){
		int v,x,y;
		ll k;
		scanf("%d",&v);
		if(v==1){
			scanf("%d%d%lld",&x,&y,&k);
			update(1,x,y,k);
		}else{
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(1,x,y));
		}
	}
}
