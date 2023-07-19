#include<bits/stdc++.h>
using namespace std;
#define N 1000050
#define int unsigned long long
int n;
int a[N];
int q[N];
int tot;
int ans;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        while(tot&&a[q[tot]]<=a[i]){ans^=q[tot];tot--;}
        q[++tot]=i;
        ans^=i;
        cout << ans << "\n";
    }
}