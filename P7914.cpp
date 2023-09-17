#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505,mod=1e9+7;
int n,K;
int a[N];//0->*,1->(,2->),3->?
int pa[N],pi[N];
int f[N][N][N];


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> K;
    string s;
    cin >> s;
    for(int i=1;i<=n;i++){
        switch(s[i-1]){
            case '*':a[i]=0;break;
            case '(':a[i]=1;break;
            case ')':a[i]=2;break;
            case '?':a[i]=3;break;
        }
    }
    for(int i=n;i>=1;i++){
        pa[i]=pa[i+1]+(a[i]==2)+(a[i]==3)-(a[i]==1);
        pi[i]=pi[i+1]+(a[i]==2)-(a[i]==3)-(a[i]==1);
    }
}
/*
pre[i]->maxj
f[i][j][k]->
f[i+1][j+1][0],
f[i+1][j-1][0],
f[i+1][j][k+1],
pi[i]<=j<=pa[i],k<=K
*/