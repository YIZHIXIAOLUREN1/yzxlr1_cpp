#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7;
int n,a[N],b[N],c[N],d[N];
int lb[N],rb[N];
ll ans,res;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        b[i]=c[b[i]];
        d[b[i]]=i;
    }
    d[0]=0,d[n+1]=n+1;
    for(int i=1;i<=n;i++){
        lb[i]=d[b[i]-1];
        rb[i]=d[b[i]+1];
        if(lb[i]>i)lb[i]=0;
        if(rb[i]<i)rb[i]=n+1;
    }
    int len=0,j=1;
    for(int i=1;i<=n;i++){
        if(lb[i]==0){
            len=1,j=i;
            while(rb[j]<=n){len++,j=rb[j];}
            res=(ll)len*(len+1)/2;
            ans+=res;
        }
    }
    cout<<ans;
}
