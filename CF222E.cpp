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
        res.clear();
        for(int k=1;k<=m;k++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=m;j++){
                    res.a[i][j]=(res.a[i][j]+1ll*x.a[i][k]*y.a[k][j])%mod;
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

int rd(char x);

gj zy;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    zy.clear();
    zy.one();
    for(int i=1;i<=k;i++){
        string u;
        cin >> u;
        zy.a[rd(u[1])][rd(u[0])]=0;
    }
    
    zy=zy^(n-1);

    int ans=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            ans=(ans+zy.a[i][j])%mod;
        }
    }
    cout << ans;
    return 0;
}

int rd(char x){
    return (x>='a')?(x-'a'+1):(x-'A'+27);
}