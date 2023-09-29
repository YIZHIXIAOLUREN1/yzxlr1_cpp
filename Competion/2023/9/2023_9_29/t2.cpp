#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+7,inf=0x3f3f3f3f3f3f3f3f;
int n;
int a[N];
ll f[N][N];
ll ans;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    memset(f,0x3f,sizeof f);
    f[0][0]=0;
    f[1][0]=a[1];
    ans=inf;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=i-2;j++){
            f[i][j]=min(f[i][j],f[i-1][j]+abs(a[i]-a[i-1]));
            if(i==n)ans=min(ans,f[i][j]);
            //printf("%d %d:%d\n",i,j,f[i][j]);//
        }
        for(int j=0;j<i-1;j++)
            f[i][i-1]=min(f[i][i-1],f[i-1][j]+abs(a[i]-a[j]));  
        if(i==n)ans=min(ans,f[i][i-1]);
    }
    cout << ans;
}
/*
f[i][j]<-f[i-1][j]+s[i][i-1],i>j+1
f[i][j]<-f[j][j-k]+s[i][j-k],i=j+1,0<k<=j
*/