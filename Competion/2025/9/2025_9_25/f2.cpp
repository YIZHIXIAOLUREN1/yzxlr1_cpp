#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int h,d;

bool check(int k){
    ll n=d/(k-d+1),rn=(d%(k-d+1));
    //ll res1=1ll*rn*(n+2)*(n+1)/2+1ll*(k-d+1-rn)*(n+1)*(n)/2;
    ll res1=1ll*rn*(n+1)+1ll*(k-d+1)*(n+1)*(n)/2;
    return 1ll*h+k-d>res1;
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>h>>d;
        if(h==1){
        	cout<<2*d<<"\n";
        	continue;
        }else if(h>1ll*d*(d+1)/2){
        	cout<<d<<"\n";
        	continue;
        }
        int l=d+1,r=2*d+1;
        while(l<r){
            int mid=(l+r)/2;
            if(check(mid))r=mid;
            else l=mid+1;
        }
        //l=max(l,d);l=min(l,2*d);
        cout<<l<<"\n";
    }
}
