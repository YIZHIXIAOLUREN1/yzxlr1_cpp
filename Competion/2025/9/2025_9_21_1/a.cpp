#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7;
int n,a[N],b[N];
ll ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;b[a[i]]++,i--){
    	if(a[i]==a[i+1])continue;
        ans+=(n-i)-b[a[i]];
        
    }
    cout<<ans+1;
}