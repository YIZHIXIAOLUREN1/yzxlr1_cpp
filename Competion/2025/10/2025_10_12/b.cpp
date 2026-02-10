#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7,mod=1000000007;
ll n,x,y;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    cin>>x>>y;
    for(int i=2;i<=n;i++){
        ll c,d;
        cin>>c>>d;
        ll nx=(x*c-y*d+mod)%mod,ny=(x*d+y*c)%mod;
        x=nx,y=ny;
    }
    cout<<(x+mod)%mod<<" "<<(y+mod)%mod;
}
//a+bi,c+di=ac-bd,ad+bc