#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,s;
int a[N],b[N];

ll solve(int l,int r){
    if(s<=l)return a[r]-s;
    if(s>=r)return s-a[l];
    if(b[l]>=b[r])return a[r]-a[l]+solve(l,r-1);
    else return a[r]-a[l]+solve(l+1,r);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>s;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
}
