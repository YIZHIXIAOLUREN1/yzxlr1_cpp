#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <array>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cctype>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
// #define int long long
#define endl '\n'
const int mod=1e9+7,N=307;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
LL qmi(LL m,LL k,int p)
{
    LL ans=1LL%p;
    while(k)
    {
        if(k&1)ans=ans*m%p;
        m=m*m%p;
        k>>=1;
    }
    return ans;
}
int pre[N];
LL pp[N][N][N];
void solve()
{
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    s='?'+s;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+(s[i]!='?');
    }
    vector<vector<vector<vector<LL>>>> f(n+1,vector<vector<vector<LL>>>(3,vector<vector<LL>>(310,vector<LL>(310,0))));
    if(s[1]=='a'){
        f[1][0][0][0]=1;
    }else if(s[1]=='b'){
        f[1][1][0][0]=1;
    }else if(s[1]=='c'){
        f[1][2][0][0]=1;
    }else{
        f[1][0][1][0]=1;
        f[1][1][0][1]=1;
        f[1][2][0][0]=1;
    }
    for(int i=2;i<=n;i++){
    for(int a=0;a<=i-pre[i];a++){
        for(int b=0;b<=i-pre[i]-a;b++){
                int c=i-a-b-pre[i];
                if(s[i]=='a'){
                    f[i][0][a][b]=(f[i-1][1][a][b]+f[i-1][2][a][b])%mod;
                }else if(s[i]=='b'){
                    f[i][1][a][b]=(f[i-1][0][a][b]+f[i-1][2][a][b])%mod;
                }else if(s[i]=='c'){
                    f[i][2][a][b]=(f[i-1][1][a][b]+f[i-1][0][a][b])%mod;
                }else{
                    if(a)f[i][0][a][b]=(f[i-1][1][a-1][b]+f[i-1][2][a-1][b])%mod;
                    if(b)f[i][1][a][b]=(f[i-1][0][a][b-1]+f[i-1][2][a][b-1])%mod;
                    if(c)f[i][2][a][b]=(f[i-1][1][a][b]+f[i-1][0][a][b])%mod;
                }
            }
        }
    }

    for(int a=0;a<=n-pre[n];a++){
        for(int b=0;b<=n-pre[n]-a;b++){
                pp[a][b][n-pre[n]-a-b]=(f[n][0][a][b]+f[n][1][a][b]+f[n][2][a][b])%mod;
        }
    }
    for(int a=0;a<=n-pre[n];a++){
        for(int b=0;b<=n-pre[n];b++){
            for(int c=1;c<=n-pre[n];c++){
                pp[a][b][c]=(pp[a][b][c]+pp[a][b][c-1])%mod;
            }
        }
    }
    for(int a=0;a<=n-pre[n];a++){
        for(int c=0;c<=n-pre[n];c++){
            for(int b=1;b<=n-pre[n];b++){
                pp[a][b][c]=(pp[a][b][c]+pp[a][b-1][c])%mod;
            }
        }
    }
    for(int b=0;b<=n-pre[n];b++){
        for(int c=0;c<=n-pre[n];c++){
            for(int a=1;a<=n-pre[n];a++){
                pp[a][b][c]=(pp[a][b][c]+pp[a-1][b][c])%mod;
            }
        }
    }
    for(int a=0;a<=n-pre[n];a++){
        for(int b=0;b<=n-pre[n];b++){
            for(int c=0;c<=n-pre[n];c++){
                //printf("%d %d %d:%lld %lld\n",a,b,c,(f[n][0][a][b]+f[n][1][a][b]+f[n][2][a][b])%mod,pp[a][b][c]);//
            }
        }
    }

    while(q--){
        int qa,qb,qc;
        cin>>qa>>qb>>qc;
        qa=min(qa,n-pre[n]);
        qb=min(qb,n-pre[n]);
        qc=min(qc,n-pre[n]);
        cout<<pp[qa][qb][qc]%mod<<"\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}