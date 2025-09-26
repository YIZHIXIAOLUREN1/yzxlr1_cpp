#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=10;
int n,a[N];
int ans,tf;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        ans=tf=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==0)ans++;
            else if(a[i]==-1)tf++;
        }
        if(tf%2)ans+=2;
        cout<<ans<<"\n";
    }
}
