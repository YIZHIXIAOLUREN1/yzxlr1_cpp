#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
ll ans=0;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    for(int n=1;n<=T;n++){
        ans=0;
        for(int i=1;i<=n;i++){
            //cout<<i<<":"<<i*i/n<<" "<<(ll)sqrt(i*n)<<"\n";
            ans+=i*i/n+(ll)sqrt(i*n);
        }
        if(n*n+1!=ans)
        cout<<n<<":"<<ans-n*n<<":"<<n/(ans-n*n)/(ans-n*n)<<"\n";
    }
}
