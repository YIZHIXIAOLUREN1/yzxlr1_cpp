#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7;
int n,Q;
int a[N];
ll pre[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>Q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=a[i]+pre[i-1];
    }
    while(Q--){
        int l,r;
        cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<"\n";
    }
}
