#include<bits/stdc++.h>
using namespace std;
#define M 100050
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define inf (1<<31)-1
#define ll long long
int n,m,v;
int a[M][10];
int s[M][10];
int wa[M*2][10],wi[M*2][10];
int ma[10],mi[10];

ll cnm(int x,int y){
	if(m>n)return 0;
    ll res=1;
    for(int i=x;i>x-y;i--){
        res*=i;
        res/=(x-i+1);
    }
    return res;
}

int AA(int x){
	return (x>1)?AA(x-1)*x:1;
}

void pushup(int f,int u){
    wa[u][f]=max(wa[ls][f],wa[rs][f]);
    wi[u][f]=min(wi[ls][f],wi[rs][f]);
}

void build(int f,int u,int l,int r){
    if(l==r){
        wa[u][f]=wi[u][f]=a[l][f];
        return;
    }
    build(f,ls,l,mid);
    build(f,rs,mid+1,r);
    pushup(f,u);
}

int cxm(int f,int u,int l,int r,int L,int R){
    if(r<L||l>R)return 0;
    if(L<=l&&R>=r)return wa[u][f];
    return max(cxm(f,ls,l,mid,L,R),cxm(f,rs,mid+1,r,L,R));
}

int cxi(int f,int u,int l,int r,int L,int R){
    if(r<L||l>R)return inf;
    if(L<=l&&R>=r)return wi[u][f];
    return min(cxi(f,ls,l,mid,L,R),cxi(f,rs,mid+1,r,L,R));
}
ll ans=0;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> v;
    int an=pow(2,n);
    int bn=AA(n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[j][i];
            s[j][i]=a[j][i]+s[j-1][i]+s[j][i-1]-s[j-1][i-1];
        }
        build(i,1,1,m);
    }
    
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            for(int k=1;k<=n;k++){
                ma[k]=cxm(k,1,1,n,i,j);
                mi[k]=cxi(k,1,1,n,i,j);
            }
            for(int k=2;k<=(1<<(n+1));k++){
                int xa=0,xi=inf;
                int tt=0;
                for(int l=1;l<=n;l++){
                    if(k&(1<<l)){
                        xa=max(xa,ma[l]);
                        xi=min(xi,mi[l]);
                        tt++;
                    }
                }
                //printf("%d %d %d:%d %d\n",i,j,k,xa,xi);//
                if((xa^xi)==v){
                	//printf("%d:%lld\n",tt,(ll)(pow(2,n)-(cnm(n,tt)-(n+1-tt))));//
                	//ans+=an-(cnm(n,tt)-(n+1-tt));
                	ans+=(bn-1)*(cnm(n,tt)-(n+1-tt));
                }
            }
        }
    }

    cout << ans;

}