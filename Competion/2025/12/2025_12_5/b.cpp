#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,a[N],b[N];
ll mi,ma;
void Solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];

    mi=ma=0;
    for(int i=1;i<=n;i++){
        ll n[4]={mi-a[i],ma-a[i],b[i]-mi,b[i]-ma};
        sort(n,n+4);
        mi=n[0],ma=n[3];
    }
    cout<<ma<<"\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}
