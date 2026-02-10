#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=107;
int n;
string ss,tt;
bool s[N],t[N];
int f[N][N];
bool check(int l,int r){
    if(l>=r)return 0;
    while(l<=r){
        if(s[l]!=s[r])return 0;
        l++;r--;
    }
    return 1;
}
void Solve(){
    cin>>n;
    cin>>ss>>tt;
    for(int i=1;i<=n;i++)s[i]=ss[i-1]-'0',t[i]=tt[i-1]-'0';
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){//j-i
            if(!f[j][i])continue;
            for(int k=j+1;k<=i;k++)s[k]=!s[k];
            for(int k=i;k<=n;k++){
                if(check(j+1,k)){
                    for(int l=i+1;l<=k;l++)s[k]=!s[k];
                    for(int l=)
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}
