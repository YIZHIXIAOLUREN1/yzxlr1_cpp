#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7;
int n,Q;
int a[N];
ll pre[N];
//prefix

int main(){
    cin>>n>>Q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=a[i]+pre[i-1];
    }
    while(Q--){
        int l,r;
        cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<"\n";
    }
}
/*
pre[1]=a[1]+pre[0]


*/