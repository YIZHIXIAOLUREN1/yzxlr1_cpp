#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
ll p,q;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>p>>q;
        q=q*180;
        cout<<q/gcd(q,p)-1<<"\n";
    }
}
