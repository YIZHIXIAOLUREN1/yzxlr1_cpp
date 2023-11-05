#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
ll n,a[N],ans;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans^=i+a[i];
    }
    cout << ans;
}
