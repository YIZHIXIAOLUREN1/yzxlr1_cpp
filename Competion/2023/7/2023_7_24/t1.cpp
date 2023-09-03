#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
#define ll long long
int n;
int a[N],b[N];
ll ana,anb;


int main(){
    ios::sync_with_stdio(0);cin.tie();cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=n;i++)cin >> b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);

    int rw=0,rp=0;
    for(int l=1;l<=n;l++){
        while(rw<n&&a[l]>b[rw+1])rw++;
        while(rp<n&&a[l]>=b[rp+1])rp++;
        ana+=rw;
        anb+=n-rp;
    }

    cout << ana << "\n" << anb;
}