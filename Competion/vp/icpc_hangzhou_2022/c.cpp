#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=3007;
int f[N][N],g[N][N];
int n,K;
int w[11][N];
int p[N];
int res[11];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>K;
    int ans=0,sum=0;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        for(int j=1;j<=p[i];j++)cin>>w[j][i];
        sum+=p[i];
    }
    if(K==0){
    	cout<<"0\n";
    	return 0;
    }
    if(sum<=K){
    	for(int i=1;i<=n;i++)ans+=w[p[i]][i];
    	cout<<ans<<"\n";
    	return 0;
    }

    for(int i=1;i<=n;i++){
        for(int k=1;k<=K;k++){
            f[i][k]=f[i-1][k];
            if(k>=p[i]&&(k==p[i]||f[i-1][k-p[i]]))f[i][k]=max(f[i][k],f[i-1][k-p[i]]+w[p[i]][i]);
        }
    }
    for(int i=n;i>=1;i--){
        for(int k=1;k<=K;k++){
            g[i][k]=g[i+1][k];
            if(k>=p[i]&&(k==p[i]||g[i+1][k-p[i]]))g[i][k]=max(g[i][k],g[i+1][k-p[i]]+w[p[i]][i]);
        }
    }
    
    

    for(int i=1;i<=n;i++){
        //for(int j=0;j<=10;j++)res[j]=0;
        for(int j=0;j<K;j++){
            for(int k=max(1ll*0,K-j-p[i]+1);k<K-j;k++){
            	if((i>1&&j&&f[i-1][j]==0)||(i==1&&j!=0))continue;
            	if((i<n&&k&&g[i+1][k]==0)||(i==n&&k!=0))continue;
                int pi=K-j-k;
                ans=max(ans,f[i-1][j]+g[i+1][k]+w[pi][i]);
                //printf("%d:%d %d:%d %d\n",i,j,k,pi,f[i-1][j]+g[i+1][k]);//
            }
        }
    }
    ans=max(f[n][K],ans);
    cout<<ans<<"\n";
}