#include<bits/stdc++.h>
using namespace std;
#define N 405
#define ll long long
int n,m;
ll a[N][N];
ll lo[N][N],ro[N][N],ld[N][N],rd[N][N];
ll s[N][N];
ll ans=-1e12,sum;

ll qs(int x1,int y1,int x2,int y2){
    return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}
void csh(){
    memset(lo,0xc0,sizeof lo);
    memset(ro,0xc0,sizeof ro);
    memset(ld,0xc0,sizeof ld);
    memset(rd,0xc0,sizeof rd);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld",&a[i][j]);
            s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
        }
    }
    csh();
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        if(i>1)lo[i][j]=max(lo[i-1][j]+a[i-1][j],lo[i][j]);
        if(j>1)lo[i][j]=max(lo[i][j],lo[i][j-1]+a[i][j-1]);
        if(i==1&&j==1)lo[i][j]=0;
    }
    for(int i=n;i>=1;i--)for(int j=1;j<=m;j++){
        if(i<n)ld[i][j]=max(ld[i+1][j]+a[i+1][j],ld[i][j]);
        if(j>1)ld[i][j]=max(ld[i][j],ld[i][j-1]+a[i][j-1]);
        if(i==n&&j==1)ld[i][j]=0;
    }
    for(int i=1;i<=n;i++)for(int j=m;j>=1;j--) {
        if(i>1)ro[i][j]=max(ro[i-1][j]+a[i-1][j],ro[i][j]);
        if(j<m)ro[i][j]=max(ro[i][j],ro[i][j+1]+a[i][j+1]);
        if(i==1&&j==m)ro[i][j]=0;
    }
    for(int i=n;i>=1;i--)for(int j=m;j>=1;j--){
        if(i<n)rd[i][j]=max(rd[i+1][j]+a[i+1][j],rd[i][j]);
        if(j<m)rd[i][j]=max(rd[i][j],rd[i][j+1]+a[i][j+1]);
        if(i==n&&j==m)rd[i][j]=0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            sum=qs(i,1,j,1)+lo[i][1]+ro[i][1]+ld[j][1]+rd[j][1];
            for(int k=2;k<=m;k++){
                sum+=qs(i,k,j,k)+ro[i][k]-ro[i][k-1]+rd[j][k]-rd[j][k-1];
                if(sum>ans)ans=sum;
                if(sum<qs(i,k,j,k)+ro[i][k]+rd[j][k]+lo[i][k]+ld[j][k])
                	sum=qs(i,k,j,k)+ro[i][k]+rd[j][k]+lo[i][k]+ld[j][k];
            }
        }
    }
    printf("%lld",ans);
}