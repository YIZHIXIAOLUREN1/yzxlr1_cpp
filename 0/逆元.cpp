#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod;
int qp(int x,int q){
    int res=1;
    while(q){
        if(q&1)res=(ll)res*x%mod;
        x=(ll)x*x%mod;
        q>>=1;
    }
    return res;
}
int inv(int x){return qp(x,mod-2);}//费马小定理


