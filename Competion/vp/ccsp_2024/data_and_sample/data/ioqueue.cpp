#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n;
int a[N];
int sa,sb;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(sa>sb)swap(sa,sb);
        sa=max(a[i],sa)+10;
    }
    if(sa>sb)swap(sa,sb);
    cout<<sa<<" "<<sb;
}
