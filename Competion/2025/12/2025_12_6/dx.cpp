#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=107;
int n;
bool vis[N];
vector<pair<int,int>> ans;
void Solve(){
    cin>>n;
    if(n>=7&&n%4==3){
        cout<<n-1<<"\n";
        for(int i=2;i<=n;i++)cout<<"1 "<<i<<"\n";
        return;
    }
    cout<<"1\n1 100\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}
/*
*/