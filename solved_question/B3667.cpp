#include<bits/stdc++.h>
using namespace std;
#define N 1000050
#define ull unsigned long long
#define pr pair<int,ull>
int n,k;
pr a[N];
int l=1;int r;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        while(l<=r&&a[l].first<i-k+1)l++;
        ull x;
        cin >> x;
        while(l<=r&&a[r].second<=x)r--;
        a[++r]={i,x};
        //cout << l << " " << r << ":\n";
        if(i>=k)cout << (r-l+1) << "\n";
    }
}