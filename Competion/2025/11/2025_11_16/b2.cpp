#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=407;
const ll inf=1e8;
int n,m,a[N][N];
ll pre[N][N];
ll b[N],bpre[N],f[N];
ll tans=-inf;
int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)cin>>a[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)pre[i][j]=a[i][j]+pre[i-1][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)pre[i][j]+=pre[i][j-1];
    }

    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            for(int j=1;j<=m;j++){
                b[j]=pre[r][j]-pre[r][j-1]-(pre[l-1][j]-pre[l-1][j-1]);
                bpre[j]=bpre[j-1]+b[j];
            }
            ll ans=-inf,res=0;
            for(int j=1;j<=m;j++){
                f[j]=max(f[j-1],1ll*0)+b[j];
                if(j+r-l<=m){
                    res=max(f[j-1],1ll*0)+bpre[j+r-l+1-1]-bpre[j-1];
                    ans=max(ans,res);
                }
            }
            //printf("%d %d:%lld\n",l,r,ans);//
            tans=max(tans,ans*(r-l+1));
        }
    }

    for(int l=1;l<=m;l++){
        for(int r=l;r<=m;r++){
            for(int j=1;j<=n;j++){
                b[j]=pre[j][r]-pre[j-1][r]-(pre[j][l-1]-pre[j-1][l-1]);
                bpre[j]=bpre[j-1]+b[j];
            }
            ll ans=-inf,res=0;
            for(int j=1;j<=n;j++){
                f[j]=max(f[j-1],1ll*0)+b[j];
                if(j+r-l<=n){
                    res=max(f[j-1],1ll*0)+bpre[j+r-l+1-1]-bpre[j-1];
                    ans=max(ans,res);
                }
            }
            tans=max(tans,ans*(r-l+1));
        }
    }
    cout<<tans;
}
