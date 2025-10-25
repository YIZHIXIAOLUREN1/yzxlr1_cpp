#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
ll ans,n;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        ans+=((i%2)?(-1):1)*i*i*i;
    }
    cout<<ans;
}
