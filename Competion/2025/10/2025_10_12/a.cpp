#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a,b=0;
    cin>>a;
    for(int i=1;i<=5;i++){
        b+=a%10;
        a/=10;
    }
    cout<<b%9;
}
