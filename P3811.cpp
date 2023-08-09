#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e6+7;
int n,mod;
int qp(int x,int q){
    int res=1;
    while(q){
        if(q&1)res=(ll)res*x%mod;
        x=(ll)x*x%mod;
        q>>=1;
    }
    return res;
}

int inv(int x){return qp(x,mod-2);}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> mod;
    for(int i=1;i<=n;i++)cout << inv(i) << "\n";
}
