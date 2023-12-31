//改成基环树即可
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pr pair<int,int>
const ll N=1000007,inf=0x3f3f3f3f;
ll n,m;
pr a[N];
int deg[N];
ll b[N],fa[N],tot;
vector<int> G[N],Gi[N];
vector<int> su;
bool vis[N];
int q[N],top;

void dfs1(int u){
    vis[u]=1;
    q[++top]=u;
    for(auto v:G[u]){
        if(!vis[v]){dfs1(v);continue;}
        ll res=0;
        ++tot;
        while(q[top]!=v){
            res+=a[q[top]].first;
            fa[q[top]]=tot;
            top--;
        }
        res+=a[v].first;
        fa[v]=tot;
        top--;
    }
}

ll dfs(int u,int x){
    
    ll res=x-a[u].first;
    for(auto v:G[u])res+=dfs(v,x);
    return max(res,1ll*0);
}

bool check(int x){
    ll res=0;
    memset(vis,0,sizeof vis);
    //printf("%d:\n",x);//
    for(auto i:su){
        res+=dfs(i,x);
    }
    //printf("%d:%d\n",x,res);//
    return res<=m;
}

bool cmp(pr x,pr y){return x.first<y.first;}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i].second;
    int ma=0;
    for(int i=1;i<=n;i++){cin>>a[i].first;ma=max(ma,a[i].first);}
    for(int i=1;i<=n;i++){
        int u=a[i].second;
        if(u!=-1){
            G[u].push_back(i);
            deg[i]++;
        }
    }
    
    for(int i=1;i<=n;i++)if(!deg[i])su.push_back(i);
    int l=0,r=ma;
    while(l<r){
    	//printf("%d:%d\n",l,r);//
        int mid=(l+r)>>1;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    while(check(l+1))l++;
    while(l>0&&!check(l))l--;
    cout << l;
    return 0;
}
