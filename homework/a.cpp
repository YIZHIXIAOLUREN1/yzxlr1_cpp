#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N = 1e5 + 7;

signed main()
{
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a,b;
    cin>>a>>b;
    cout<<__gcd(a,b)<<" "<<a/__gcd(a,b)*b;
}