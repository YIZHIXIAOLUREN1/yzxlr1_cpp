#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int x,a[N],len;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>x;
    int s0=0;
    while(x){
        a[++len]=x%10;
        x/=10;
        if(!a[len])s0++;
    }
    sort(a+1,a+len+1);
    int ans=0;
    ans=a[s0+1];
    for(int i=1;i<=s0;i++)ans*=10;
    for(int i=s0+2;i<=len;i++){
        ans*=10;
        ans+=a[i];
    }
    cout<<ans;
}
