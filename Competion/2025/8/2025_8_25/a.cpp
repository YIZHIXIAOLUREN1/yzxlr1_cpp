#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,a,b;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>a>>b;
        int ans=0;
        if(a%2==n%2&&b%2==n%2)ans=1;
        if(a<=b&&b%2==n%2)ans=1;
        if(ans)cout<<"yes\n";
        else cout<<"no\n";

    }
}
