#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=507;
int n,m,L;
int a[N],s[N],q[N],t[N],ans;

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>L;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=L;i<=n;i++){
        q[i]=(m-(s[i]-s[i-L]+m)%m)%m;
        t[i]=q[i]-q[i-1];
        ans+=t[i];
        printf("%d %d %d\n",q[i],t[i],ans);//
    }
    cout<<ans;
}