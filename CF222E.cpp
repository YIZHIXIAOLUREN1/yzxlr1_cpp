#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=55,l=52,mod=1e9+7;
ll n;
int m,k;

struct gj{
    int a[M][M];
    void clear(){memset(a,0,sizeof a);}
    void dw(){
        for(int i=1;i<=m;i++){
            a[i][i]=1;
        }
    }
    void one(){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                a[i][j]=1;
            }
        }
    }
    friend gj operator * (gj x,gj y){
        gj res;
        for(int k=1;k<=m;k++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=m;j++){
                    res.a[i][j]=x.a[i][k]+y.a[k][j];
                    res.a[i][j]%=mod;
                }
            }
        }
        return res;
    }
};

gj operator ^ (gj x,ll y){
    gj res;
    res.clear();res.dw();
    while(y){
        if(y&1ll*1)res=res*x;
        x=x*x;
        y>>=1;
    }
    return res;
}
gj zy;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    zy.clear();
    zy.one();
    for(int i=1;i<=k;i++){
        char u[2];
        cin >> u;
        
    }
    
    return 0;
}
