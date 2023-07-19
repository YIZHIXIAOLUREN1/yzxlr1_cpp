#include<bits/stdc++.h>
using namespace std;
#define N 5005
int n,k;
int a[N];
int f[N][N];
int ans=0x6f6f6f6f;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k >> a[0];
    n--;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=n;i>=1;i--){
    	a[i]-=a[i-1];
    	//printf("%d:%d\n",i,a[i]);//
    }
    memset(f,0x6f,sizeof f);
    f[1][0]=0;f[1][1]=a[1];
    for(int i=1;i<=n;i++){
        for(int j=k;j>=0;j--){
        	if(i>1)f[i][j]=min(f[i][j],f[i-1][j]);
            if(j>0&&i>2)f[i][j]=min(f[i][j],f[i-2][j-1]+a[i]);
            //printf("%d %d:%d\n",i,j,f[i][j]);//
        }
        ans=min(ans,f[i][k]);
    }

    cout << ans;
}