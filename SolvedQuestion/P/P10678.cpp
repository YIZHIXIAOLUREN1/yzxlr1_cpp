#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n;
pair<int,int> a[N];

void Solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+n+1,[](pair<int,int> x,pair<int,int> y){return x.first>y.first;});
    for(int i=2,j=1;i<=n;i++){
        if(!a[j].first)j++;
        cout<<a[j].second<<" "<<a[i].second<<"\n";
        a[j].first--;
        a[i].first--;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}
