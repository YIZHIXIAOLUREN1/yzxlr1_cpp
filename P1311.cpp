#include<bits/stdc++.h>
using namespace std;
#define N 200100
#define ll long long
int n,K,P;
int a[N],b[N];
int ls[N][60],lp[N];
ll ans;

int main(){
    scanf("%d%d%d",&n,&K,&P);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
        for(int j=0;j<K;j++){
            ls[i][j]=ls[i-1][j];
            if(j==a[i])ls[i][j]++;
        }
        if(b[i]<=P)lp[i]=i;
        else lp[i]=lp[i-1];
    }

    for(int i=2;i<=n;i++){
        ans+=ls[lp[i]==i?i-1:lp[i]][a[i]];
    }
    printf("%lld",ans);
}