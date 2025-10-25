#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,res;
int a[N],b[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>0)b[a[i]]++;
        else res++;
    }
    bool fl=1;
    int j=1;
    for(int i=1;i<=n;i++){
        if(b[i]>1){fl=0;break;}
        while(j<n&&a[j]>0)j++;
        if(!b[i])a[j]=i;
    }
    if(!fl)cout<<"No\n";
    else{
        cout<<"Yes\n";
        for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];
    }
}
