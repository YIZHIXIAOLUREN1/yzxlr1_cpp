#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=25,M=2005;
int n,m;
int a[N],ms;
bool b[N];
bool f[N][M];
int ans=0;

void dp(){
    memset(f,0,sizeof f);
    for(int i=1;i<=n;i++){
        f[i][0]=1;
        f[i][a[i]]=1&b[i];
        for(int j=1;j<=ms;j++){
            f[i][j]=f[i][j]|(b[i]&&j-a[i]>=0&&f[i-1][j-a[i]])|f[i-1][j];
            //printf("%d %d:%d\n",i,j,f[i][j]);//
        }
    }
    int res=0;
    for(int j=1;j<=ms;j++)res+=f[n][j];
    ans=max(ans,res);
}

void dfs(int u,int x){
    if(u==n&&x==0){dp();return;}
    if(u>n)return;
    dfs(u+1,x);
    if(x){
        b[u+1]=0;
        dfs(u+1,x-1);
        b[u+1]=1;
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        b[i]=1;
        cin >> a[i];
        ms+=a[i];
    }
    dfs(0,m);
    cout << ans;
}
