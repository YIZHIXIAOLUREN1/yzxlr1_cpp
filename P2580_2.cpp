#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
const int N=1e4+7;
int n,m;
__gnu_pbds::gp_hash_table<string,int> mp;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        mp[s]=1;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        string s;
        cin>>s;
        if(mp[s]==1)cout<<"OK\n",mp[s]=2;
        else if(mp[s]==2)cout<<"REPEAT\n";
        else cout<<"WRONG\n";
    }
}
