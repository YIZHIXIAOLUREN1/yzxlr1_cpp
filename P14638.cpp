#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=5e4+7;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,a[N];
ll f[N],lst[N],sum[N],q[N],head,tail,g[N];
ll ans[N];
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
ll w[N*4];
ll lazy[N*4];

void pushup(const int u){w[u]=max(w[ls],w[rs]);}
void maketag(int u,int l,int r,ll x){
	lazy[u]=max(lazy[u],x);
	w[u]=max(w[u],x);
}
void pushdown(int u,int l,int r){
	maketag(ls,l,mid,lazy[u]);
	maketag(rs,mid+1,r,lazy[u]);
}
void build(int u,int l,int r){
	lazy[u]=-inf;
    if(l==r){w[u]=-inf;return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}
void query(int u,int l,int r,int L,int R){
	if(l==r){ans[l]=w[u];return;}
	pushdown(u,l,r);
	query(ls,l,mid,L,R);
    query(rs,mid+1,r,L,R);
}
void update1(int u,int l,int r,int L,int R,ll x){
	if(L>R)return;
	if(L<=l&&r<=R){maketag(u,l,r,x);return;}
	if(l>R||r<L)return;
	pushdown(u,l,r);
	update1(ls,l,mid,L,R,x);
	update1(rs,mid+1,r,L,R,x);
	pushup(u);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    int QQ;
    cin>>QQ;
    for(int Q=1;Q<=QQ;Q++){
        int L,R;
        cin>>L>>R;
        head=1,tail=1;
        q[1]=0;
        for(int i=1;i<=n;i++){
            while(head<=tail&&i-q[head]>R-L)head++;
            
            //printf("%d:%d %d %d ",i,head,tail,q[head]);//
            if(head<=tail){
            	if(sum[i]-sum[q[head]]>=0){
	                lst[i]=q[head]+1;
	            }else lst[i]=i+1;
	            f[i]=max(sum[i]-sum[q[head]],1ll*0);
            }else{
            	f[i]=0;
            }
            while(head<=tail&&sum[q[tail]]>=sum[i])tail--;
            q[++tail]=i;
            //cout<<f[i]<<"\n";//
            
        }
        build(1,1,n);
        for(int i=n;i>=L;i--){
            g[i]=sum[i]-sum[i-L]+f[i-L];
            if(f[i-L]>0)lst[i]=lst[i-L];
            else lst[i]=i-L+1;
            //printf("%d:%d %lld\n",lst[i],i,g[i]);//
            update1(1,1,n,lst[i],i,g[i]);
        }
        query(1,1,n,1,n);
        ull res=0;
        //for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];//
        for(int i=1;i<=n;i++)res=res^(ull)(ans[i]*i);
        cout<<res<<"\n";
    }
    
}

// lst[i]~i max<-g[i]