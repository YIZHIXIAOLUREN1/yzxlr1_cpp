#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll p;
ll ans;

int main(){
    cin >> p;
    p--;
    for(ll i=1;i*i<=p;i++){
        if(p%i==0){
            ans+=2;
            if(i*i==p)ans-=1;
        }
    }
    cout << ans;
}