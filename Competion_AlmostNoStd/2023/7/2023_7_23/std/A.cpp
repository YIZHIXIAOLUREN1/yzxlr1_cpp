#include <bits/stdc++.h>
using namespace std;
int main() {
using ll = long long;
ll p, ans = 1;
cin >> p;
--p;
for (ll i = 2; i * i <= p; i++)
if (p % i == 0) {
ll cnt = 1;
while (p % i == 0) ++cnt, p /= i;
ans *= cnt;
}
if (p > 1) ans *= 2;
cout << ans << endl;
return 0;
}