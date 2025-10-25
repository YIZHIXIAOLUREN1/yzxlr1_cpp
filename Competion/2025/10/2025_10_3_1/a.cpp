#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,a[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        int cnt =unique(a+1,a+n+1)-a-1;
        cout<<cnt*2-1<<"\n";
    }
}
