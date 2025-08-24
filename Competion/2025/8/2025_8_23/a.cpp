#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=107;
int n,a[N],ans;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int res=a[n];
    for(int i=n;i>=1;i--){
        res=min(res,a[i]);
        ans+=res;
    }
    cout<<ans;
}
