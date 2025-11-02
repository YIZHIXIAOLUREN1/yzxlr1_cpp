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
    if(n%2){//n
        int ps=m%n,ds=m/n;
        if(ps==0)ps=n,ds=m/n-1;
        
        s=sum/ps*ds;
        sum%=ps;

        s-=(sum/n);
        sum%=n;

        cout<<(sum%m+m)%m<<"\n";
        cout<<(s%m+m)%m<<" "<<(d%m+m)%m<<"\n";
    }else{//n/2
        int p=0;
        int pp=m%(n/2),dp=m/(n/2);
        if(pp==0)pp=n/2,dp=m/(n/2)-1;

        p=sum/pp*dp;
        sum%=pp;

        p-=(sum/(n/2));
        sum%=n/2;

        if(p%2==0){
            s=p/2;
        }else{
            d=1;
            if(p>=n+1){
                s=(p-n-1)/2;
            }else{
                if(m%2==0){
                    s=(p+m-n-1)/2;
                }else{
                    d=0;
                    s=(p+m)/2;
                }
            }
        }
        cout<<(sum%m+m)%m<<"\n";
        cout<<(s%m+m)%m<<" "<<(d%m+m)%m<<"\n";
    }
}
