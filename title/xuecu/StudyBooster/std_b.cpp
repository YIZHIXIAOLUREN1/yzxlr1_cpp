#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7;
int n,Q;
int a[N];

int main(){
    cin>>n>>Q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(Q--){
        int l,r;
        cin>>l>>r;
        ll ans=0;
        for(int i=l;i<=r;i++){
            ans+=a[i];
        }
        cout<<ans<<"\n";
    }
}
