#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 300000
const int mod=38;
int n,m;
int num[MAXN];
LL w[MAXN];
bool lac[MAXN],lah[MAXN];
LL lazyc[MAXN],lazyh[MAXN];
int umax=0;

inline void pushup(const int u){
    w[u]=w[2*u]+w[2*u+1]%mod;
}

void maketag(int u,int len,LL xh,LL xc){
	if(xc!=0){
		w[u]=w[u]*(xc%mod)%mod;
		lazyc[u]*(xc%mod)%mod;
		lac[u]=1;
		lazyh[u]=lazyh[u]*(xc%mod)%mod;
	}
	else{
		lah[u]=1;
		lazyh[u]=(lazyh[u]+xh)%mod;
	}
}

void pushdown(int u,int L,int R){
	int M=(L+R) >> 1;
	maketag(u*2,M-L+1,0,lazyc[u]);
	maketag(u*2,M-L+1,lazyh[u],0);
	maketag(u*2+1,R-M+1,0,lazyc[u]);
	maketag(u*2+1,R-M+1,lazyh[u],0);
	lazyh[u]=0;
	lazyc[u]=1;
}

void build(const int u,int L,int R){
	umax++;
    if(L==R){
        w[u]=num[L];
        return;
    }
    int M=(L+R) >> 1;
    
    build(u*2,L,M);
    build(u*2+1,M+1,R);
    pushup(u);
}

inline bool inr(const int L,int R,int l,int r){
    return (l<=L&&R<=r);
}
inline bool outr(const int L,int R,int l,int r){
    return (L>r||R<l);
}

LL 	query(const int u,int L,int R,int l,int r){
	if(inr(L,R,l,r))
		return w[u];
	if(!outr(L,R,l,r)){
		int M=(L+R) >> 1;
		pushdown(u,L,R);
		return query(u*2,L,M,l,r)+query(u*2+1,M+1,R,l,r);
	}
	return 0;
}

void update1(int u,int L,int R,int l,int r,LL xh,LL xc){
	if(inr(L,R,l,r)){
		maketag(u,R-L+1,0,xc);
		maketag(u,R-L+1,xh,0);
		return;
	}
	if(!outr(L,R,l,r)){
		int M=(L+R) >> 1;
		pushdown(u,L,R);
		update1(u*2,L,M,l,r,xh,xc);
		update1(u*2,M+1,R,l,r,xh,xc);
		pushup(u);
		return;
	}
	return;
}

int main(){
    scanf("%d%d%d",&n,&m,&num[0]);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    build(1,1,n);
    for(int i=0;i<m;++i){
    	int node,xx,yy,kk;
    	scanf("%d",&node);
    	if(node==1){
    		scanf("%d%d%d",&xx,&yy,&kk);
    		update1(1,1,n,xx,yy,0,kk);
		}
		if(node==2){
    		scanf("%d%d%d",&xx,&yy,&kk);
    		update1(1,1,n,xx,yy,kk,0);
		}
		if(node==3){
    		scanf("%d%d",&xx,&yy);
    		cout << query(1,1,n,xx,yy) << endl;
		}
	//	for(int i=1;i<=umax;++i)cout << w[i] << " ";
	}
    return 0;
}
