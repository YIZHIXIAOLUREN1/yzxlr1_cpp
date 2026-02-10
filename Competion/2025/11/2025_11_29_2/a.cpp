#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;

void Solve(){
    int n,y,r;
    cin>>n>>y>>r;
    cout<<min(n,r+y/2)<<"\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}
