#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll dp[N],s[N],pre[N];
int n,h[N];
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
ll w[2][N*4];
ll lazyc[2][N*4];

void pushup(int t,const int u){w[t][u]=min(w[t][ls],w[t][rs]);}
void maketag(int t,int u,int l,int r,ll xc){
	lazyc[t][u]=min(lazyc[t][u],xc);
	w[t][u]=min(w[t][u],lazyc[t][u]);
}
void pushdown(int t,int u,int l,int r){
	maketag(t,ls,l,mid,lazyc[t][u]);
	maketag(t,rs,mid+1,r,lazyc[t][u]);
}
void build(int t,int u,int l,int r){
	lazyc[t][u]=inf;
    if(l==r){w[t][u]=inf;return;}
    build(t,ls,l,mid);
    build(t,rs,mid+1,r);
    pushup(t,u);
}
ll query1(int t,int u,int l,int r,int tg){
	if(l==r)return w[t][u];
	pushdown(t,u,l,r);
	if(tg<=mid)return query1(t,ls,l,mid,tg);
    else return query1(t,rs,mid+1,r,tg);
}
void update1(int t,int u,int l,int r,int L,int R,ll xc){
	if(R>L)return;
	if(L<=l&&r<=R){maketag(t,u,l,r,xc);return;}
	if(l>R||r<L)return;
	pushdown(t,u,l,r);
	update1(t,ls,l,mid,L,R,xc);
	update1(t,rs,mid+1,r,L,R,xc);
	pushup(t,u);
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        s[0]=0;
        for(int i=1;i<=n;i++){
            cin>>h[i];
            s[i]=s[i-1]+h[i];
            dp[i]=inf;
        }
        //cout<<"A"<<n<<"\n";//
        for(int i=n;i>=1;i--){
            dp[i]=s[n]-s[i-1]-(n-i);
            for(int j=i+2;j<=n;j++){
                dp[i]=min(dp[i],dp[j]-min(j-i,h[j])+h[j-1]+s[j-2]-s[i-1]-(j-i-2));
            }
            cout<<dp[i]<<" \n"[i==1];//
        }
        cout<<dp[1]<<"\n";
    }
}
