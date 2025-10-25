#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int a[3];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if((a[0]==a[1]&&a[0]*2>a[2])||(a[1]==a[2])){
        cout<<"Yes\n";
    }else cout<<"No\n";
}
