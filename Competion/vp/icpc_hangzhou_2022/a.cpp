#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int N=1e5+7;
ll n,m,a;
ll sum,s,d;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
        sum+=a;
    }
    sum%=m;
    int pd=0,dd=0;
    if((n*(n+1)/2)%m)pd=m%((n*(n+1)/2)%m),dd=m/((n*(n+1)/2)%m);
    int ps=m%n,ds=m/n;
    if(!(n%2)){
        if(pd&&sum>pd){
            d=sum/pd*dd;
            sum%=pd;
        }
    }
    if(ps&&sum>ps){
        sum%=ps;
        s=sum/ps*ds;
    }
    cout<<sum<<"\n";
    cout<<s%m<<" "<<d%m<<"\n";
}
