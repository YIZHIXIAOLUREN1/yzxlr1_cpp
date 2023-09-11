#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls (u<<1)
#define rs (u<<1|1)
const int inf=1e12;
#define dif -9e18
const int N=1000005;
int n,k,a[N];
int f[N];
int w[N*6],laz[N*6];

void pushup(int u){
	w[u]=max(w[ls],w[rs]);
}

void pushdown(int u){
	if(laz[u]==0)return;
	laz[ls]+=laz[u];
	laz[rs]+=laz[u];
	w[ls]+=laz[u];
	w[rs]+=laz[u];
	laz[u]=0;
}

void change(int u,int l,int r,int L,int R,int p){
	//printf("c%lld %lld %lld %lld %lld:%lld:%lld\n",u,l,r,L,R,p,w[q][u]);//
	//pushdown(q,u);
	if(l>=L&&r<=R){
		laz[u]+=p;
		w[u]+=p;
		return;
	}
	int m=(l+r)/2;
	pushdown(u);
	if(L<=m)change(ls,l,m,L,R,p);
	if(R>m)change(rs,m+1,r,L,R,p);
	pushup(u);
}

int query(int u,int l,int r,int L,int R){
	//printf("q%lld %lld %lld %lld %lld:%lld\n",u,l,r,L,R,w[q][u]);//
	if(l>=L&&r<=R){
		return w[u];
	}
	//if(l>R||r<L) return dif;
	int m=(l+r)/2;
	pushdown(u);
	int res=-9e18;
	if(L<=m) res=max(res,query(ls,l,m,L,R));
	if(R>m) res=max(res,query(rs,m+1,r,L,R));
	return res;
}

/*void qc(int q){
	for(int i=0;i<=k*2;i++)w[q][i]=0;
}*/
/*
void ck(int q){//
	int i=0;
	while(w[q][++i]!=(int)0){
		int res=w[q][i];
		//while(res<0)res+=inf;
		//printf("%lld:%lld ",i,res);//
	}
	puts("");
}//*/

int st[N],top;

signed main(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	for(int i=1;i<=n;i++){
		while(top&&a[st[top]]<=a[i]){
			//if(a[st[top]]==a[i]){top--;continue;}
			int dt=a[i]-a[st[top]];
			change(1,0,n,st[top-1],st[top]-1,dt);
			top--;
		}
		st[++top]=i;
		change(1,0,n,i-1,i-1,f[i-1]+a[i]);
		f[i]=query(1,0,n,max(i-k,(int)0),i-1)-inf;
		//printf("%lld:%lld\n",i,f[i]);//
		//ck(0);//
	}
	
	int s=n/k+(n%k>0);
	printf("%lld\n",(int)(f[n]+(int)(s*inf)));
	
	//cout<<(long long)(f[n]+(long long)ceil((double)1.0*n/k)*inf);
	//printf("%lld\n",f[(s+1)%2][k-r]);
	return 0;
}





