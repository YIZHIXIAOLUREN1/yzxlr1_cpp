#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n=6,m=26,x=16,y=12,sum=16;
    cout<<(n*x+n*(n+1)/2*y+sum)%m;
}
