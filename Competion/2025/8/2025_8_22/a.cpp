#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int x,a,b,t;
    cin>>x>>a>>b>>t;
    if(x<60)cout<<0;
    else if(x<120)cout<<a;
    else if(x<240)cout<<b;
    else cout<<t;
}
