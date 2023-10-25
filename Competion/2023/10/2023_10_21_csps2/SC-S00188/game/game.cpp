#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=8007;
int n;
int a[N];
bool f[N][N];
ll ans;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    string s;
    cin >> s;
    for(int i=0;i<n;i++){
        a[i+1]=s[i]-'a';
    }
    for(int len=2;len<=n;len+=2){
        for(int i=1;i<=n-len+1;i++){
            int j=len+i-1;
            if(a[i]==a[j]&&(f[i+1][j-1]||j==i+1)){
                f[i][j]=1;
                ans++;
                continue;
            }
            for(int k=i+2;k<=j;k+=2){
                if(f[i][k-1]&&f[k][j]){
                    f[i][j]=1;
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans;
}
