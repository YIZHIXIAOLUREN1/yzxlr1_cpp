#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+7;
int n,w;
int a[N];
int f[2][N];
int d[N];
vector<int> dw[N];

void pre(){
    d[1]=1;
    dw[1].push_back(1);
    for(int i=2;i<=10005;i++){
        int res=0;
        for(int j=1;j*j<=i;j++){
            if(i%j)continue;
            dw[i].push_back(j);
            res++;
            if(j*j<i){
                dw[i].push_back(i/j);
                res++;
            }
        }
        d[i]=res;
    }
}

int dd(int x){
    if(x<=10005)return d[x];
    int res=0;
    for(int j=1;j*j<=x;j++){
        if(x%j==0)res+=2;
        if(j*j==x)res--;
    }
    return res;
}

int main(){
    pre();
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> w;
    for(int i=1;i<=n;i++)cin >> a[i];
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=w;j++){
             f[i&1][j]=max(f[(i&1)^1][j]*dd(a[i]),f[(i&1)^1][0]*dd(a[i]*j));
            for(auto k:dw[j])
                f[i&1][j]=max(f[i&1][j],f[(i&1)^1][k]*dd(a[i]*((k>0)?(j/k):j)));
        }
    }
    cout<<f[n&1][w]<<"\n";
}

/*
f[i][j]=f[i-1][k]+d(a[i]*j/k),j|w,k|j

*/