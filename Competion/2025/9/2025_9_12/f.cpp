#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+7;
int n;
int a[N],b[N];
int ans=0;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);


    int j=1;
    for(int i=1;i<=n;i++){
        while(j<n&&b[j+1]<=a[i])j++;
        int res=N;
        if(b[j]<=a[i])res=a[i]-b[j];
        else res=b[j]-a[i];
        if(j<n&&b[j+1]>=a[i])res=min(res,b[j+1]-a[i]);
        ans=max(ans,res);
    }
    // for(int i=1;i<=n;i++){
    //     int res=0;
    //     if(a[i]>b[1])res=a[i]-b[1];
    //     if(a[i]<b[n])res=max(res,b[n]-a[i]);
    //     ans=min(ans,res);
    // }
    cout<<ans;
}
