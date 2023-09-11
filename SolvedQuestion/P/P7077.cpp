#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int mod=998244353,N=100005;
int n,m,Q;
int pos[N],c[N],type[N];
ll ad[N],a[N],mul[N],dy[N];
vector<int> G1[N],G2[N];
bool ut[N];

inline ll read() {
    ll ret = 0, w = 1; char c = getchar();
    while(!isdigit(c))    {if(c == '-')    w = -1; c = getchar();}
    while(isdigit(c))    {ret = (ret << 1) + (ret << 3) + (c ^ 48); c = getchar();}
    return ret * w;
}
inline void write(ll x) {
    if(x < 0)  putchar('-'), x = -x;
    if(x > 9)  write(x / 10);
    putchar(x % 10 + 48);
}

bool vis[N];
void dfs1(int u){
	//cout << u << ":" << type[u] << " ";//
    vis[u]=(ll)1;
    if(type[u]==(ll)3){
        int r=1;
        //cout << G1[u].size() << "\n";//
        for(int i=G1[u].size()-1;i>=(ll)0;i--){
            int v=G1[u][i];
            //printf("V:%d\n",v);//
            if(!vis[v]) dfs1(v);
            r=(r*mul[v])%mod;
        }
        mul[u]=r;
    }
    //printf("mu %d:%lld\n",u,mul[u]);//
}

int deg[N];
void top1(){
    static queue<int> q;
    for(int i=0;i<=m;i++){
        deg[i]=G2[i].size();
        if(deg[i]==(ll)0)q.push(i);
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        int nmu=dy[u];
        for(int i=G1[u].size()-1;i>=(ll)0;i--){
            int v=G1[u][i];
            dy[v]=(dy[v]+nmu)%mod;
            nmu=(nmu*mul[v])%mod;
            deg[v]--;
            if(!deg[v])q.push(v);
        }
    }
}


signed main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        type[i]=read();
        ad[i]=(ll)0;mul[i]=(ll)1;
        switch(type[i]){
            case 1:pos[i]=read();ad[i]=read();break;
            case 2:mul[i]=read();break;
            case 3:
                c[i]=read();
                for(int v,j=1;j<=c[i];j++){
                    v=read();
                    G1[i].push_back(v);
                    G2[v].push_back(i);
                }break;
        }
    }
    c[0]=read();
    for(int v,j=1;j<=c[0];j++){
        v=read();
        ut[v]=(ll)1;
        G1[0].push_back(v);
        G2[v].push_back(0);
    }
    ut[0]=(ll)1;
    type[0]=(ll)3;
    dfs1(0);
    memset(vis,0,sizeof vis);
    dy[0]=(ll)1;
    top1();
	
	//for(int i=0;i<=m;i++)printf("%d:%lld:%lld\n",i,mul[i],dy[i]);//
	for(int i=1;i<=n;i++)a[i]=(a[i]*mul[0])%mod;
    for(int i=1;i<=m;i++){
        if(!pos[i])continue;
        a[pos[i]]=(a[pos[i]]+(ad[i]*dy[i])%mod)%mod;
    }
    for(int i=1;i<n;i++)printf("%lld ",a[i]);
    printf("%lld\n",a[n]);
    return 0;
}