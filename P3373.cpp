#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 300000
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
const int mod=571373;
int n,m;
int num[MAXN];
LL w[MAXN];
LL lazyc[MAXN],lazyh[MAXN];
int umax=0;

inline void pushup(const int u){
    w[u]=(w[ls]+w[rs])%mod;
}

void maketag(int u,int l,int r,LL xh,LL xc){
	lazyc[u]=lazyc[u]*xc%mod;
	lazyh[u]=(lazyh[u]*xc+xh)%mod;
	w[u]=(w[u]*xc%mod+xh*len%mod)%mod;
	//printf("%d:%d %d:%d %d:%d\n",u,l,r,xh,xc,w[u]);//
}

void pushdown(int u,int l,int r){
	maketag(ls,l,mid,lazyh[u],lazyc[u]);
	maketag(rs,mid+1,r,lazyh[u],lazyc[u]);
	lazyh[u]=0;
	lazyc[u]=1;
}

void build(int u,int l,int r){
	umax++;
	lazyc[u]=1;
    if(l==r){
        w[u]=num[l];
        return;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}
LL query(int u,int l,int r,int L,int R){
	if(L<=l&&r<=R)return w[u];
    if(l>R||r<L)return 0;
	pushdown(u,l,r);
	return (query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R))%mod;
}

void update1(int u,int l,int r,int L,int R,LL xh,LL xc){
	//printf("%d:%d %d:%d %d %d %d\n",u,l,r,L,R,xh,xc);//
	if(L<=l&&r<=R){
		maketag(u,l,r,xh,xc);
		return;
	}
	if(l>R||r<L)return;
	pushdown(u,l,r);
	update1(ls,l,mid,L,R,xh,xc);
	update1(rs,mid+1,r,L,R,xh,xc);
	pushup(u);
}

int main(){
    scanf("%d%d%d",&n,&m,&num[0]);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    build(1,1,n);
    for(int i=0;i<m;++i){
    	//for(int i=1;i<=umax;++i)cout << w[i] << " ";//
    	//puts("");//
    	int node,xx,yy,kk;
    	scanf("%d",&node);
    	if(node==1){
    		scanf("%d%d%d",&xx,&yy,&kk);
    		update1(1,1,n,xx,yy,0,kk%mod);
		}
		if(node==2){
    		scanf("%d%d%d",&xx,&yy,&kk);
    		update1(1,1,n,xx,yy,kk%mod,1);
		}
		if(node==3){
    		scanf("%d%d",&xx,&yy);
    		cout << query(1,1,n,xx,yy) << endl;
		}
	}
    return 0;
}
