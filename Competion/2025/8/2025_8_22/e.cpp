#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,p[N],j[N],s[N];
int ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=n;i++)cin>>j[i];
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++){
        ans+=max(0,s[i]-abs(p[i]-j[i]));
    }
    cout<<ans;
}
