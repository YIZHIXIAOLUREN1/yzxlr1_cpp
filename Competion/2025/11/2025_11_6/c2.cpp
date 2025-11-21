#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,m;
int T;
int lsh[3*N];
pair<int,int> a[N];
pair<pair<int,int>,int> b[N];
int cnt;

void Solve(){
    cin>>n>>m;
    int res0=0,resc=0,ans=0;
    for(int i=1; i<=n; i++) {
		cin>>a[i].first;
        lsh[i]=a[i].first;
        a[i].second=0;
    }
    
    for(int i=1; i<=m; i++) {
		cin>>b[i].first.first;
        lsh[i+n]=b[i].first.first;
        b[i].second=0;
	}
    for(int i=1; i<=m; i++) {
		cin>>b[i].first.second;
        if(b[i].first.second)resc++;
        else res0++;
        lsh[i+n+m]=b[i].first.second;
	}
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>T;
    while(T--){
        Solve();
    }
}
