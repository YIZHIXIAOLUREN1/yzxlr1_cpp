#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=350,mod=1e9+7;
int n;
int a[N],b[N];
int lsh[N],cnt,num[N];
int f[N][N],g[N],h[N][N][N];

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=1;i<=n*2;i++){
		cin >> num[i];
		lsh[i]=num[i];
	}
	sort(lsh+1,lsh+2*n+1);
	cnt=unique(lsh+1,lsh+n*2+1)-lsh-1;
	for(int i=1;i<=2*n;i++)
    	num[i]=lower_bound(lsh+1,lsh+cnt+1,num[i])-lsh;
    
    for(int i=1;i<=n;i++)a[i]=num[i];//printf("a%d:%d\n",i,a[i]);//
    for(int i=1;i<=n;i++)b[i]=num[i+n];//printf("b%d:%d\n",i,b[i]);//

    for(int i=1;i<=cnt;i++)f[n][i]=((a[n]!=i)+(b[n]!=i));
    for(int i=1;i<=cnt;i++)
    for(int j=i+1;j<=cnt;j++){
        h[n][i][j]=h[n][j][i]=(a[n]!=j||a[n]!=i)+(b[n]!=i||b[n]!=j);
    }
    g[n]=(a[n]!=b[n])+1;

    for(int i=n-1;i>=1;i--){
        g[i]=f[i+1][a[i]]+f[i+1][b[i]];
        if(a[i]==b[i])g[i]/=2;
        g[i]%=mod;
        for(int j=1;j<=cnt;j++){
            f[i][j]=(a[i]!=j)*(f[i+1][a[i]]+f[i+1][j]-h[i+1][a[i]][j])+
            (b[i]!=j)*(f[i+1][b[i]]+f[i+1][j]-h[i+1][b[i]][j]);
            if(a[i]==b[i])f[i][j]/=2;
            f[i][j]%=mod;
            printf("f%d %d:%d\n",i,j,f[i][j]);//
        }
        for(int j=1;j<=cnt;j++){
            for(int k=j+1;k<=cnt;k++){
                //h[i][j][k]=(a[i]!=j)*f[i+1][j];
                h[i][k][j]=h[i][j][k]%=mod;
                printf("h%d %d %d:%d\n",i,j,k,h[i][j][k]);//
            }
        }
    }

    for(int i=1;i<=n;i++)cout << g[i] << " \n"[i==n];
}