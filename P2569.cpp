#include<bits/stdc++.h>
using namespace std;
#define N 2050
#define ll long long
#define inf 0xc0c0c0c0c0c0c0c0
int T,mp,W;
ll f[N][N];
int ap[N],bp[N],as[N],bs[N];
ll q[N];
int l,r;

int main(){
    scanf("%d%d%d",&T,&mp,&W);
    W++;
    memset(f,0xc0,sizeof f);
    for(int i=1;i<=T;i++){
    	scanf("%d%d%d%d",&ap[i],&bp[i],&as[i],&bs[i]);
    }

    for(int i=1;i<=T;i++){
    	for(int j=0;j<=as[i];j++)f[i][j]=-j*ap[i];
    	for(int j=0;j<=mp;j++)f[i][j]=max(f[i][j],f[i-1][j]);
        if(i<=W)continue;
        
        l=1,r=0;
        for(int j=0;j<=mp;j++){
            while(l<=r&&j-q[l]>as[i])l++;
            while(l<=r&&f[i-W][q[r]]-ap[i]*(j-q[r])<=f[i-W][j])r--;
            q[++r]=j;
            if(l<=r)f[i][j]=max(f[i][j],(ll)(f[i-W][q[l]]-ap[i]*(j-q[l])));
        }
        
        l=1,r=0;
        for(int j=mp;j>=0;j--){
            while(l<=r&&q[l]-j>bs[i])l++;
            while(l<=r&&f[i-W][q[r]]+bp[i]*(q[r]-j)<=f[i-W][j])r--;
            q[++r]=j;
            if(l<=r)f[i][j]=max(f[i][j],f[i-W][q[l]]+bp[i]*(q[l]-j));
        }
    }
    ll ans=inf;
    for(int i=0;i<=mp;i++)ans=max(ans,f[T][i]);
    printf("%lld",ans);
}