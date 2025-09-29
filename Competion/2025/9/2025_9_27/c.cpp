#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,L=1;
ll a[N],pre[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int Q;
    cin>>n>>Q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    while(Q--){
        int ty,c,l,r;
        cin>>ty;
        if(ty==1){
            cin>>c;
            L=(L+c-1)%n+1;
        }else{
            cin>>l>>r;
            l=(l+L-1-1)%n+1;
            r=(r+L-1-1)%n+1;
            if(l<=r)cout<<pre[r]-pre[l-1]<<"\n";
            else{
                cout<<pre[n]-pre[l-1]+pre[r]<<"\n";
            }
        }
    }

}
