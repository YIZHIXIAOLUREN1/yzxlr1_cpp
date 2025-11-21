#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;

ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int l;
        cin>>l;
        ll sum=0;
        for(int i=1;i<=l;i++){
            int x;
            cin>>x;
            sum+=x;
        }
        
        if(sum==1){
            cout<<"1\n";
            continue;
        }
        
        ll t=1;
        int L=0;
        while(t<sum){
            t<<=1;
            L++;
            L%=MOD;
        }
        
        cout<<ksm(2,L)<<"\n";
    }
    return 0;
}