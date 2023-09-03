#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
int n,K;
int d[N],fa[N];
vector<int> G[N];
int ans[N][N][N];

void dfs(int u,int fas){
    fa[u]=fas;
    d[u]=d[fas]+1;
    for(auto v:G[u]){
        if(v==fas)continue;
        dfs(v,u);
    }
}

void lca(int x,int y){
    int i=x,j=y;
    ans[i][j][x]++;
    ans[i][j][y]++;
    if(d[x]<d[y])swap(x,y);
    while(d[x]>d[y]){
        x=fa[x];
        ans[i][j][x]++;
    }
    while(x!=y){
        x=fa[x],y=fa[y];
        ans[i][j][x]++;
        ans[i][j][y]++;
    }
    ans[i][j][x]--;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> K;
    for(int k=1;k<=K;k++){
    	for(int i=1;i<=n;i++)G[i].clear();
        memset(d,0,sizeof d);
        memset(fa,0,sizeof fa);
        for(int i=1,u,v;i<=n-1;i++){
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1,1);
        //cout << "A";//
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                lca(i,j);
                //printf("%d:%d\n",i,j);//
            }
        }
    }
    //cout << "B";//
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            int c=0;
            if(i==k)c=1;
            else if(k<i){
                for(int j=1;j<=n;j++){
                    if(ans[k][i][j]==K)c++;
                }
            }else{
                for(int j=1;j<=n;j++){
                    if(ans[i][k][j]==K)c++;
                }
            }
            cout << c << " \n"[k==n];
        }
    }
}
