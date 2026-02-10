#include <bits/stdc++.h>
#define db double
#define ll long long
#define pc putchar
#define gc getchar
#define sz(x) ((int)x.size())
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
#define D(i, a, b) for (int i = (a); i >= (b); --i)
#define TM cerr<<fabs(&Med-&Mbe)/1048576.0<<"MB "<<1.0*clock()/CLOCKS_PER_SEC*1000<<"ms\n"
using namespace std;
int n = 10, m = 10; // 自己改
int p[10];
string s = ".#";
string t = "CQ";
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	srand(time(0));
	F(i, 1, n) p[i] = i;
	random_shuffle(p + 1, p + 1 + n);
	cout << n << ' ' << m << '\n';
	F(i, 1, n-1) cout << p[i] << ' ' << p[i+1] << '\n';
	F(i, 1, n) cout << s[rand()%2] << s[rand()%2] << '\n';
	F(i, 1, m) {
		char ch = t[rand()%2];
		cout << ch << ' ';
		if (ch == 'C') cout << rand()%n+1 << ' ' << s[rand()%2] << s[rand()%2] << '\n';
		else cout << rand()%n+1 << ' ' << rand()%n+1 << '\n';
	}
	return 0;
}
