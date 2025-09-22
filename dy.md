离散化模板
```cpp
#include<bits/stdc++.h>
using namespace std;
#define N 1000000
int lsh[N],cnt,num[N],n;
int main(){
	scanf("%d",&n); 
	for(int i=1; i<=n; i++) {
		scanf("%d",&num[i]);
		lsh[i] = num[i];
	}
	sort(lsh+1,lsh+n+1);
	cnt = unique(lsh+1 , lsh+n+1) - lsh - 1;
	for(int i=1; i<=n; i++)
    	num[i] = lower_bound(lsh+1 , lsh+cnt+1 , num[i]) - lsh;
}

```
快读
```cpp
#include<bits/stdc++.h>
#define ll long long
#define gc() getchar()
#define pc(x) putchar(x)
#define endl pc(10)
inline int read(){int w=1,q=0;char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=gc();if(ch=='-')w=-1,ch=gc();
    while(ch>='0'&&ch<='9')q=q*10+ch-'0',ch=gc();return w*q;}
inline void pr(ll x){if(x<0)pc('-'),x=-x;if(x>9)pr(x/10);pc(x%10+'0');}
```
逆元
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod;
int qp(int x,int q){
    int res=1;
    while(q){
        if(q&1)res=(ll)res*x%mod;
        x=(ll)x*x%mod;
        q>>=1;
    }
    return res;
}
int inv1(int x){return qp(x,mod-2);}//费马小定理

void exgcd(ll a,ll b,ll &x,ll &y){
	if(a%b==0) x=0,y=1;
	else exgcd(b,a%b,y,x),y-=a/b*x;
}
int inv(ll a,ll p){
	ll x,y;
	exgcd(a,p,x,y);
	return (x%p+p)%p;
}
```
双哈希
```cpp
const int MAXN= 1e6 + 3;
typedef unsigned int       u32;
typedef unsigned long long u64;
const u32 BAS1 = 13331, MOD1 = 1e9 + 7;
const u32 BAS2 =   131, MOD2 = 1e9 + 9;
int H1[MAXN], P1[MAXN];
int H2[MAXN], P2[MAXN];
u64 get(int l, int r){
    int h1 = (H1[r] - 1ull * H1[l - 1] * P1[r - l + 1] % MOD1 + MOD1) % MOD1;
    int h2 = (H2[r] - 1ull * H2[l - 1] * P2[r - l + 1] % MOD2 + MOD2) % MOD2;
    return 1ull * h1 << 32 | h2;
}
void init(int n, char S[]){
    P1[0] = P2[0] = 1;
    for(int i = 1;i <= n;++ i)
        H1[i] = (1ull * H1[i - 1] * BAS1 + S[i]) % MOD1,
        H2[i] = (1ull * H2[i - 1] * BAS2 + S[i]) % MOD2,
        P1[i] = 1ull * P1[i - 1] * BAS1 % MOD1,
        P2[i] = 1ull * P2[i - 1] * BAS2 % MOD2;
}
```
线段树模板
```cpp
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define N 300000
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
int mod;
int n,m;
int num[N];
LL w[N*4];
LL lazyc[N*4],lazyh[N*4];

void pushup(const int u){w[u]=(w[ls]+w[rs])%mod;}
void maketag(int u,int l,int r,LL xh,LL xc){
	lazyc[u]=lazyc[u]*xc%mod;
	lazyh[u]=(lazyh[u]*xc+xh)%mod;
	w[u]=(w[u]*xc%mod+xh*len%mod)%mod;
}
void pushdown(int u,int l,int r){
	maketag(ls,l,mid,lazyh[u],lazyc[u]);
	maketag(rs,mid+1,r,lazyh[u],lazyc[u]);
	lazyh[u]=0;
	lazyc[u]=1;
}
void build(int u,int l,int r){
	lazyc[u]=1;
    if(l==r){w[u]=num[l];return;}
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
	if(L<=l&&r<=R){maketag(u,l,r,xh,xc);return;}
	if(l>R||r<L)return;
	pushdown(u,l,r);
	update1(ls,l,mid,L,R,xh,xc);
	update1(rs,mid+1,r,L,R,xh,xc);
	pushup(u);
}

int main(){
}

```
线性筛
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n;
bool vis[N];
int p[N],tot=0,phi[N];


void getprime(){
    for(int i=2;i<N;i++){
        if(!vis[i])p[++tot]=i;
        for(int j=1;j<=tot&&(ll)p[j]*i<N;j++){
            vis[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}

void pre(){
	phi[1]=1;
	for(int i=2;i<N;i++){
		if(!vis[i])p[++p[0]]=i,phi[i]=i-1;
		for(int j=1;j<=p[0]&&1ll*i*p[j]<N;j++){
			vis[i*p[j]]=1;
			if(i%p[j]==0){
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}else phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
}
```
重链剖分
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
const ll N=1e5+7;
ll n,rent,mod;
ll a[N],b[N];
ll w[N*4],laz[N*4];
vector<int> G[N];
int id[N],son[N],fa[N],siz[N],top[N],idx,d[N];

void dfs1(int u,int fas){
    fa[u]=fas;
    siz[u]=1;
    d[u]=d[fas]+1;
    int ms=0;
    for(auto v:G[u]){
        if(v==fas)continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>ms)ms=siz[v],son[u]=v;
    }
}

void dfs2(int u,int tof){
    id[u]=++idx;
    b[idx]=a[u];
    top[u]=tof;
    if(siz[u]==1)return;
    dfs2(son[u],tof);
    for(auto v:G[u]){
        if(v==fa[u]||v==son[u])continue;
        dfs2(v,v);
    }
}

int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(d[top[x]]<d[top[y]]){
			swap(x,y);
		}
		x=fa[top[x]];
	}
	return (d[x]<d[y])?x:y;
}

void pushup(int u){w[u]=(w[ls]+w[rs])%mod;}
void maketag(int u,int l,int r,ll x){w[u]=(w[u]+x*len)%mod;laz[u]+=x;}
void pushdown(int u,int l,int r){
    maketag(ls,l,mid,laz[u]);
    maketag(rs,mid+1,r,laz[u]);
    laz[u]=0;
}

void build(int u,int l,int r){
    if(l==r){w[u]=b[l]%mod;return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}

ll query(int u,int l,int r,int L,int R){
    if(l>R||r<L)return 0;
    if(l>=L&&r<=R)return w[u];
    pushdown(u,l,r);
    return (query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R))%mod;
}

void change(int u,int l,int r,int L,int R,ll x){
    if(l>R||r<L)return;
    if(l>=L&&r<=R){maketag(u,l,r,x);return;}
    pushdown(u,l,r);
    change(ls,l,mid,L,R,x);
    change(rs,mid+1,r,L,R,x);
    pushup(u);
}

ll q1(int x,int y){
    ll res=0;
    if(d[x]<d[y])swap(x,y);
    while(top[x]!=top[y]){
        if(d[top[x]]<d[top[y]])swap(x,y);
        res=(res+query(1,1,n,id[top[x]],id[x]))%mod;
        x=fa[top[x]];
    }
    if(d[x]<d[y])swap(x,y);
    res=(res+query(1,1,n,id[y],id[x]))%mod;
    return res;
}

void cg1(int x,int y,ll v){
    if(d[x]<d[y])swap(x,y);
    while(top[x]!=top[y]){
        if(d[top[x]]<d[top[y]])swap(x,y);
        change(1,1,n,id[top[x]],id[x],v);
        x=fa[top[x]];
    }
    if(d[x]<d[y])swap(x,y);
    change(1,1,n,id[y],id[x],v);
}
ll qz(int x){
    return query(1,1,n,id[x],id[x]+siz[x]-1);
}
void cz(int x,ll v){
    change(1,1,n,id[x],id[x]+siz[x]-1,v);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> rent >> mod;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1,u,v;i<n;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(rent,0);
    dfs2(rent,rent);
    
}
```
dijkstra
```cpp
#include<bits/stdc++.h>
using namespace std;
#define MAXN 600000
#define int long long
#define pr pair<int,int>
const int inf=2147483647;
int n,m,s;
int dis[MAXN],h[MAXN],to[MAXN],val[MAXN],nxt[MAXN];
bool vis[MAXN];
int cnt;
void add(int u,int v,int va){
	to[++cnt]=v;
	val[cnt]=va;
	nxt[cnt]=h[u];
	h[u]=cnt;
}

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

void dijkstra(){
	for(int i=1;i<=n;i++)
		dis[i]=inf;
	dis[s]=0;
	dis[0]=inf;
	q.push({dis[s],s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=h[u];i;i=nxt[i]){
			if(dis[u]+val[i]<dis[to[i]]){
				dis[to[i]]=dis[u]+val[i];
				q.push({dis[to[i]],to[i]});
			}
		}
		
	}
}


signed main(){
	scanf("%d%d%d",&n,&m,&s);
	int u,v,va;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&va);
		add(u,v,va);
	}
	dijkstra();
	for(int i=1;i<=n;i++)
		printf("%lld ",dis[i]);
	return 0;
}

```
KMP
```cpp
#include<bits/stdc++.h>
using namespace std;
#define N 1000050
int n,m,j;
int kmp[N];
char s1[N],s2[N];


int main(){
    scanf("%s%s",s1+1,s2+1);
    n=strlen(s1+1);
    m=strlen(s2+1);
    //cout << n << m;//
    for(int i=2;i<=m;i++){
        while(j&&s2[j+1]!=s2[i])j=kmp[j];
        if(s2[j+1]==s2[i])j++;
        kmp[i]=j;
    }
    j=0;
    for(int i=1;i<=n;i++){
        while(j&&s2[j+1]!=s1[i])j=kmp[j];
        if(s2[j+1]==s1[i])j++;
        if(j==m)printf("%d\n",i-m+1);
    }
    for(int i=1;i<m;i++){
        printf("%d ",kmp[i]);
    }
    printf("%d",kmp[m]);
}

```
tarjan
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,m;
vector<int> G[N];
int dfn[N],low[N],tot,vis[N];
int st[N],top,icp[N],tcp;
vector<int> cp[N];

void dfs(int u){
    low[u]=dfn[u]=++tot;
    st[++top]=u;
    vis[u]=1;
    for(auto v:G[u]){
        if(vis[v])low[u]=min(low[u],dfn[v]);
        else if(!dfn[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
    }
    if(low[u]==dfn[u]){
        tcp++;
        int vv;
        do{
            vv=st[top--];
            icp[vv]=tcp;
            vis[vv]=0;
            cp[tcp].push_back(vv);
        }while(vv!=u);
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        if(u==v)continue;
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++)if(!dfn[i])dfs(i);

    return 0;
}
```