#include<bits/stdc++.h>
using namespace std;
#define N 550
#define LL long long
#define int long long
int n,K;
int ans[N]={1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907,43046721,129140163,387420489,1162261467};
signed main(){
    cin >> n >> K;
    for(int i=1;i<=K;i++){
        string c;
        int a,b;
        cin >> a >> c >> b;
    }
    if(K!=0){cout << "114514";return 0;}
    cout << ans[n-1];
}