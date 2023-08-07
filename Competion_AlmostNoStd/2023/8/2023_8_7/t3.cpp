#include<bits/stdc++.h>
using namespace std;
const int N=30000000;
int n,k;
int top=0;
int f[N];
int q[N];
int ans=0;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    memset(f,0x3f,sizeof f);
    q[++top]=1;
    f[1]=0;
    ans++;
    while(top){
        int u=q[top],w=f[u];
        top--;
        if(w>=k)continue;
        if((u-1)%3==0&&((u-1)/3)&1&&f[(u-1)/3]>w+1){
        	f[(u-1)/3]=w+1;
            q[++top]=(u-1)/3;
            ans++;
        }
        if(u*2<N&&f[2*u]>w+1){
        	f[u*2]=w+1;
            q[++top]=u*2;
            if(u*2<=n)ans++;
        }
    }
    cout << n-ans;
}