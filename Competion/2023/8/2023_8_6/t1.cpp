#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7;
int T;
int n,mod,q;
int f[N],lcg[N],inf[N];

int qp(int x,int p){
	//printf("%d %d:",x,p);//
    int res=1;
    while(p){
        if(p&1)res=(ll)res*x%mod;
        x=(ll)x*x%mod;
        p>>=1;
    }
    //printf("%d\n",res);//
    return res;
}
int inv(int x){return qp(x,mod-2);}

void pre(){
    f[0]=1;
    lcg[0]=1;
    inf[0]=1;
    for(int i=1;i<=n;i++){
        f[i]=(ll)f[i-1]*lcg[i-1]%mod*i%mod;
        lcg[i]=(ll)lcg[i-1]*i%mod;
        //inf[i]=inv(f[i]);
        //printf("%d:%d %d %d\n",i,f[i],lcg[i],inf[i]);//
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n >> mod >> q;
        //mod=1145141;
        pre();
        while(q--){
            int r;
            cin >> r;
            cout << (ll)f[n]*inv(f[r])%mod*inv(f[n-r])%mod << "\n";
        }
    }
}
