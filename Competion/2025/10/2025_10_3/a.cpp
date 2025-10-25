#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e9+7;
int n,k;
ll mia=N,maa;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    
    for(int i=1;i<=n;i++){
        ll a;
        cin>>a;
        mia=min(mia,a);
        maa=max(maa,a);
    }
    if(k==1)cout<<"0";
    else cout<<(maa-mia)*(maa-mia);
}
