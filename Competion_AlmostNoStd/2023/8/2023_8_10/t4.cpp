#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const int mod=998244353;
int qp(int x,int q){
    int res=1;
    while(q){
        if(q&1)res=(ll)res*x%mod;
        x=(ll)x*x%mod;
        q>>=1;
    }
    return res;
}

int main(){
    cin >> n;
    cout << qp(2,n-1);
}