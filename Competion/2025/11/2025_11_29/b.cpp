#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,m,a[N],b[N];
int sum[N],tot[N];

void Solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        tot[a[i]]++;
        sum[a[i]]+=b[i];
    }
    for(int i=1;i<=m;i++)cout<<(double)sum[i]/tot[i]<<"\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
        Solve();
    }
}
