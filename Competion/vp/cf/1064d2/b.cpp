#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        ll a,b,n;
        cin>>a>>b>>n;
        cout<<min(n,1ll*1+(a<b*n&&a>b))<<"\n";
    }
}
/*
b 1
a/m a/m-1 a/m-2 ... b
k*(a/m-i)=l*(a/m-j)
*/