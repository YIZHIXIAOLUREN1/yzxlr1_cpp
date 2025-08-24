#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,a[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<n;i++){
            cout<<((i%2)?-1:3)<<" ";
        }
        cout<<((n%2)?-1:2)<<"\n";
    }
}
