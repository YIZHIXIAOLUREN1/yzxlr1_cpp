#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
const int N=1e4+7;
int n,m;
__gnu_pbds::gp_hash_table<string,pair<int,int>> mp;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        mp[s]={1,0};
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        string s;
        cin>>s;
        pair<int,int> ns=mp[s];
        if(ns.first==0)cout<<"WRONG\n";
        else if(ns.second==0)cout<<"OK\n",mp[s]={1,1};
        else cout<<"REPEAT\n";
    }
}
