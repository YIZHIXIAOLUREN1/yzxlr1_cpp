#include<bits/stdc++.h>
using namespace std;
#define N 5005
const int mod=1e8;
int n,m;
int a[N],b[N];
int f[2][N],g[2][N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    for(int i=1;i<s.size();i++)a[i]=s[i-1]-'A';
    n=s.size()-1;
    cin >> s;
    for(int i=1;i<s.size();i++)b[i]=s[i-1]-'A';
    m=s.size()-1;
    
    for(int i=0;i<=m;i++)g[0][i]=1;
    g[1][0]=1;
    for(int l=1;l<=n;l++){
        int li=(l^1)&1,ni=l&1;
        for(int j=1;j<=m;j++){
            f[ni][j]=max(f[ni][j-1],f[li][j]);
            g[ni][j]=0;
            if(a[l]==b[j])f[ni][j]=max(f[ni][j],f[li][j-1]+1);
            if(f[ni][j]==f[li][j-1]+1&&a[l]==b[j])g[ni][j]+=g[li][j-1];
            if(f[ni][j]==f[ni][j-1])g[ni][j]+=g[ni][j-1];
            if(f[ni][j]==f[li][j])g[ni][j]+=g[li][j];
            if(f[ni][j]==f[li][j-1])g[ni][j]-=g[li][j-1];
            g[ni][j]=(g[ni][j]+mod)%mod;
        }
    }
    cout << f[n&1][m] << "\n" << g[n&1][m];
}