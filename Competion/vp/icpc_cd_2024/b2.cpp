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
LL pp[N][N];
LL pk[N];
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
        pp[a][0]=(f[n][0][a][0]+f[n][1][a][0]+f[n][2][a][0])%mod;
        for(int b=1;b<=n-pre[n];b++){
            pp[a][b]=(f[n][0][a][b]+f[n][1][a][b]+f[n][2][a][b]+pp[a][b-1])%mod;
            //printf("%d %d:%lld\n",a,b,pp[a][b]);//
        }
    }
    for(int b=0;b<=n-pre[n];b++){
        for(int a=1;a<=n-pre[n];a++){
            pp[a][b]=(pp[a][b]+pp[a-1][b])%mod;
            
        }
    }
    // for(int a=0;a<=n-pre[n];a++)
    // for(int b=0;b<=n-pre[n];b++)
    // printf("%d %d:%lld\n",a,b,(f[n][0][a][b]+f[n][1][a][b]+f[n][2][a][b])%mod);//
    // cout<<"E\n";//
    // for(int a=0;a<=n-pre[n];a++)
    // for(int b=0;b<=n-pre[n];b++)
    // printf("%d %d:%lld\n",a,b,pp[a][b]);//
    for(int k=0;k<=n-pre[n];k++){
        if(k)pk[k]=pk[k-1];
        for(int a=0;a<=k;a++){
            int b=k-a;
            pk[k]=(pk[k]+f[n][0][a][b]+f[n][1][a][b]+f[n][2][a][b])%mod;
        }
        //printf("%d:%lld\n",k,pk[k]);//
    }

    while(q--){
        int qa,qb,qc;
        cin>>qa>>qb>>qc;
        qa=min(qa,n-pre[n]);
        qb=min(qb,n-pre[n]);
        qc=max(0,n-pre[n]-qc-1);
        LL ans=((pp[qa][qb]-pk[qc])%mod+mod)%mod;
        for(int a=0;a<=qc;a++){
        	for(int b=(a<=qa)?qb+1:0;b<=qc-a;b++){
        		ans=(ans+(f[n][0][a][b]+f[n][1][a][b]+f[n][2][a][b]))%mod;
        	}
        }
        cout<<ans%mod<<"\n";
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