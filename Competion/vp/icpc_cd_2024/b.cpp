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
const int MOD=1e9+7,mod=998244353;
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
void solve()
{
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    s=' '+s;
    vector<vector<vector<vector<LL>>>> f(n+1,vector<vector<vector<LL>>>(3,vector<vector<LL>>(310,vector<LL>(310,0))));
    for(int a=0;a<=300;a++)
    {
        for(int b=0;b<=300;b++)
        {
            int c=300-a-b;
            if(c<0)continue;
            if(s[1]=='?')
            {
                f[1][0][a][b]=1;
                f[1][1][a][b]=1;
                f[1][2][a][b]=1;
            }
            else
            {
                if(s[1]=='a')
                {
                    f[1][0][a][b]=1;
                    f[1][1][a][b]=0;
                    f[1][2][a][b]=0;
                }
                else if(s[1]=='b')
                {
                    f[1][0][a][b]=0;
                    f[1][1][a][b]=1;
                    f[1][2][a][b]=0;
                }
                else
                {
                    f[1][0][a][b]=0;
                    f[1][1][a][b]=0;
                    f[1][2][a][b]=1;
                }
            }
            for(int i=2;i<=n;i++)
            {
                if(s[i-1]=='?')
                {
                    f[i][0][a][b]=(f[i-1][1][a][b]+f[i-1][2][a][b]+f[i][0][a][b])%MOD;
                    f[i][1][a][b]=(f[i-1][0][a][b]+f[i-1][2][a][b]+f[i][1][a][b])%MOD;
                    f[i][2][a][b]=(f[i-1][0][a][b]+f[i-1][1][a][b]+f[i][2][a][b])%MOD;
                }
                else
                {
                    if(s[i-1]=='a')
                    {
                        f[i][1][a][b]=(f[i-1][0][a][b]+f[i][1][a][b])%MOD;
                        f[i][2][a][b]=(f[i-1][0][a][b]+f[i][2][a][b])%MOD;
                    }
                    else if(s[i-1]=='b')
                    {
                        f[i][0][a][b]=(f[i-1][1][a][b]+f[i][0][a][b])%MOD;
                        f[i][2][a][b]=(f[i-1][1][a][b]+f[i][2][a][b])%MOD;
                    }
                    else
                    {
                        f[i][0][a][b]=(f[i-1][2][a][b]+f[i][0][a][b])%MOD;
                        f[i][1][a][b]=(f[i-1][2][a][b]+f[i][1][a][b])%MOD;
                    }
                }
            }
        }
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