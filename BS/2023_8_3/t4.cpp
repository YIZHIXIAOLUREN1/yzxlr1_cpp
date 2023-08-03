#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rn(x,t) (x+(n*t))
const int N=510000,M=2000000;
int n,R,S,X,td;
int e[N],c[N];
int head[N],to[N],nxt[N],tot;
ll val[N];
ll dis[N];
bool vis[N];
int md[N],T[N];
void add(int u,int v,ll w){
    nxt[++tot]=head[u];
    to[head[u]=tot]=v;val[tot]=w;
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> R >> S >> X;
    td=2*n;
    for(int i=1;i<=n;i++)cin >> e[i];
    for(int i=1;i<=n;i++)cin >> c[i];
    for(int i=1;i<=n;i++){
        md[i]=2;
        add(i,rn(i,1),X);//单车点
        add(rn(i,1),i,X);
        add(i,rn(i,2),0);//换乘点
        add(rn(i,2),i,0);
    }
    for(int i=1,u,v,w;i<=R;i++){
        cin >> u >> v >> w;//单车边
        add(rn(u,1),rn(v,1),w);
        add(rn(v,1),rn(u,1),w);
    }
    for(int i=1,k,u,v,w,tt;i<=S;i++){
        cin >> k >> u;
        vector<int> qq;
        qq.clear();
        for(int i=1;i<=k;i++){
            md[v]++;
            add(rn(v,md[v]),v,e[v]);
            add(v,rn(v,md[v]),e[v]);
            qq.push_back(tot);
            add(rn(v,md[v]),rn(v,2),c[v]);
            add(rn(v,2),rn(v,md[v]),0);
            qq.push_back(tot);
            add(rn(u,md[u]),rn(v,md[v]),w);
            u=v;

        }
        cin >> tt;
        for(int i=0;i<qq.size();i++){
            
        }
    }

}
