#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=1e5+7;
ll l,r;
int qp(int x,int q){
    int res=1;
    while(q){
        if(q&1)res=res*x;
        x=(ll)x*x;
        q>>=1;
    }
    return res;
}
void Solve(){
    cin>>l>>r;
    int len=0;
    for(int i=1;i<=r;i<<=1){
        if((l&i)==0&&(r&i)==i)len++;
        else break;
    }
    int nlen=0;
    for(int i=1;i<=r;i<<=1){
        if((l&i)==i&&(r&i)==0)nlen++;
        else break;
    }
    //cout<<len<<":";
    cout<<(1ll<<max(len,nlen))-1<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}
