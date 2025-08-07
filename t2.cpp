#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
ll S,n,ans;
struct T{
    ll a;
    int b,t;
}tt[N];

bool cmp(T x,T y){
    if(x.b>y.b)return 1;
    else if(x.b<y.b)return 1;
    else if(x.t<y.t)return 1;
    else return 0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
}
