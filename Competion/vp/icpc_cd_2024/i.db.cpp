#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,Q;
int a[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<i<<":";
        for(int j=1;j<=n;j++){
            if(!((i+j-1)/j<=(i-2)/j+1))cout<<j<<" ";
        }
        cout<<"\n";
    }
}
