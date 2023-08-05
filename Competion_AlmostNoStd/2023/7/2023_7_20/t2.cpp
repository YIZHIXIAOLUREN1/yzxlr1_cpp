#include<bits/stdc++.h>
using namespace std;
#define N 100050
const int mod=1e9+7;
int n;
int a[N],b[N],c[N];
int t1,t2,ty;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=0;i<n;i++)cin >> b[i];
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            c[i]=(c[i]+(a[i/j]*b[i%j]))%mod;
        cout << c[i] << "\n";
    }
}