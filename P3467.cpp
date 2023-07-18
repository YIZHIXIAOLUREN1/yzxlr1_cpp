#include<bits/stdc++.h>
using namespace std;
#define N 250500
#define inf 1000001000
#define ll long long
int n;
ll q[N];
int l=1,r;
int ans;

int main(){
    scanf("%d",&n);
    ans=n;
    for(int i=1;i<=n;i++){
        ll d,w;
        scanf("%lld%lld",&d,&w);
        while(l<=r&&q[r]>w)r--;
        while(l<=r&&q[r]==w){r--,ans--;}
        q[++r]=w;
    }
    printf("%d",ans);

}
