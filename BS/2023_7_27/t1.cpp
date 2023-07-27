#include<bits/stdc++.h>
using namespace std;
#define N 35
#define ll long long
struct gy{
    int x,y;
    ll v,w;
    friend bool operator <(gy a,gy b){
        return a.w>b.w;
    }
}g[N*N],cmg[N*N];
bool vis[N][N];
int tot=0;
int gg,n,T;
ll mg,mp,mvp;
ll ans=0,q2[65];

int main(){
    //ios::sync_with_stdio();cin.tie(0);cout.tie(0);
    q2[0]=1;
    for(int i=1;i<=64;i++)q2[i]=2*q2[i-1];

    cin >> gg >> n >> mg >> mp >> T;
    for(int i=0;i<=64;i++){
        if(q2[i]>mp){
            mvp=i;break;
        }
    }
    if(mp==0){puts("0");return 0;}
    for(int i=1;i<=gg;i++){
        cin >> g[i].x >> g[i].y >> g[i].v >> g[i].w;
        vis[g[i].x][g[i].y]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
        	if(vis[i][j])continue;
            tot=0;
            for(int k=1;k<=gg;k++){
                if(abs(g[k].x-i)+abs(g[k].y-j)<=mvp){
                    ll dw=min(mg,(mp-q2[abs(g[k].x-i)+abs(g[k].y-j)-1])/g[k].w);
                    dw=min(dw,g[k].v);
                    cmg[++tot]=g[k];
                    cmg[tot].w=dw;
                    if(g[k].v-dw>0){
                        dw=min(g[k].v-dw,dw);
                        cmg[++tot]=g[k];
                        cmg[tot].w=dw;
                    }
                }
            }
            sort(cmg+1,cmg+tot+1);
            ll res=0;
            for(int k=1;k<=min(T,tot);k++){
                res+=cmg[k].w;
            }
            ans=max(ans,res);
        }
    }
    cout << ans;
}