#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7,mod=998244353;
ll f[2][N],g[2][N];
ll pf[2][N],pg[2][N];
int n,a[N];

int C(int x,int y){return (a[x]==a[y])*a[x];}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        //memset(f,0,sizeof(f));
        //memset(g,0,sizeof(g));
        //memset(pf,0,sizeof(pf));
        //memset(pg,0,sizeof(pg));

        for(int i=0;i<=1;i++)
        for(int j=0;j<=2;j++)f[i][j]=g[i][j]=pf[i][j]=pg[i][j]=0;

        for(int i=2;i<=n;i++){
            int li=i%2,ni=(i%2)^1;
            for(int j=1;j<i;j++){
                if(j==i-1){
                    f[ni][j]=max(pf[li][i-2],pg[li][i-1])+C(i,j);
                    g[ni][j]=g[li][i-1]+C(i,j);
                }else{
                    f[ni][j]=g[li][j+1]+C(i,j);
                    g[ni][j]=g[li][j]+C(i,i-1);
                }
                pf[ni][j]=max(pf[ni][j-1],f[ni][j]);
                pg[ni][j]=max(pg[ni][j-1],g[ni][j]);
            }
            g[ni][i]=pf[ni][i-2];
        }
        ll ans=0,ni=(n%2)^1;
        ans=max(pf[ni][n-1],pg[ni][n-1]);
        cout<<ans<<"\n";
    }
}