#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,Q;
int a[N];

int g(int a,int b){
    if(a*b==0)return (a==0?b:a);
    if(a%b==0)return b;
    return g(b,a%b);
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a,b;
    cin>>a>>b;
    cout<<g(a,b);
}
