#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using i64 = long long;
using les = less <i64>;
using ntp = null_type;
tree <i64, ntp, les, rb_tree_tag, 
    tree_order_statistics_node_update> RbTr;
int n, op; i64 k, ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    auto PrintAns = []() {cout << (ans >> 20) << '\n';};
    for (int i = 1; i <= n; i ++) {
        cin >> op >> k;
        if (op == 1) RbTr.insert((k << 20) + i);
        if (op == 2) RbTr.erase(RbTr.lower_bound(k << 20));
        if (op == 3) cout << RbTr.order_of_key(k << 20) + 1 << '\n';
        if (op == 4) ans = * RbTr.find_by_order(k - 1), PrintAns();
        if (op == 5) ans = * -- RbTr.lower_bound(k << 20), PrintAns();
        if (op == 6) ans = * RbTr.upper_bound((k << 20) + n), PrintAns();
    }
    return 0;
}