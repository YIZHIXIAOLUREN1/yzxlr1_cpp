#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7,M=2007;
int n,m=2000,siz[N][4];//0,1,2,3 u d l r
int pre[M][M],pre1[M][M];
ll sum;

void Solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<4;j++)cin>>siz[i][j];
        pre[siz[i][0]][siz[i][2]]++;
        pre[siz[i][0]][siz[i][3]+1]--;
        pre[siz[i][1]+1][siz[i][2]]--;
        pre[siz[i][1]+1][siz[i][3]+1]++;
    }
    for(int i=1;i<=m;i++)
    for(int j=1;j<=m;j++)pre[i][j]+=pre[i][j-1];
    for(int j=1;j<=m;j++)
    for(int i=1;i<=m;i++)pre[i][j]+=pre[i-1][j];
    for(int j=1;j<=m;j++)
    for(int i=1;i<=m;i++){
        if(!pre[i][j])sum++;
        else if(pre[i][j]==1)pre1[i][j]=1;
    }
	//cout<<sum<<":\n";//
    for(int i=1;i<=m;i++)
    for(int j=1;j<=m;j++)pre1[i][j]+=pre1[i][j-1];
    for(int j=1;j<=m;j++)
    for(int i=1;i<=m;i++)pre1[i][j]+=pre1[i-1][j];

    for(int i=1;i<=n;i++){
        cout<<sum+(pre1[siz[i][1]][siz[i][3]]+pre1[siz[i][0]-1][siz[i][2]-1]
            -pre1[siz[i][0]-1][siz[i][3]]-pre1[siz[i][1]][siz[i][2]-1])<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
        Solve();
    }
}
