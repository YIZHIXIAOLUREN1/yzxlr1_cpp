#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e7+7,mod=998244353;
int n,g,l;
bool vis[N];
int p[N/15],tot=0;

void getprime(){
    for(int i=2;i<N;i++){
        if(!vis[i])p[++tot]=i;
        for(int j=1;j<=tot&&(ll)p[j]*i<N;j++){
            vis[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}

ll qp(ll x,ll q){
    ll res=1;
    while(q){
        if(q&1)res=res*x%mod;
        x=x*x%mod;
        q>>=1;
    }
    return res;
}

ll so(ll x){

}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    getprime();
    int T;
    cin >> T;
    while(T--){
        cin >> n >> g >> l;
        
    }

}
