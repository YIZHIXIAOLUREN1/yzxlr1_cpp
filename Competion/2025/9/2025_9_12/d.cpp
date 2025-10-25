#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n=10,ans;
int a[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(ans+a[i]<=100)ans+=a[i];
        else{
            if(ans+a[i]-100<100-ans)ans+=a[i];
            break;
        }
    }
    cout<<ans;
}
