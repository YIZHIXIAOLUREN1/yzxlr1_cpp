#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005+5;
int n,q,d[N];
void Solve(){
    cin>>n>>q;
    for(int i=0;i<=n+2;i++)d[i]=0;
    for(int i=1;i<=n;i++){
        int a,b;cin>>a>>b;
        if(a>b)swap(a,b);
        if(b-a<=2){
            int l=max(1,a-1),r=min(n,b+1);
            if(l<=r){d[l]++;d[r+1]--;}
        }else{
            int l1=max(1,a-1),r1=min(n,a+1);
            if(l1<=r1){d[l1]++;d[r1+1]--;}
            int l2=max(1,b-1),r2=min(n,b+1);
            if(l2<=r2){d[l2]++;d[r2+1]--;}
        }
    }
    for(int i=1;i<=n;i++)d[i]+=d[i-1];
    for(int i=0;i<q;i++){
        int x;cin>>x;
        cout<<n-d[x]<<(i==q-1?'\n':' ');
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--)Solve();
    return 0;
}