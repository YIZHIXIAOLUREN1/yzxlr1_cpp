#include "testlib.h"

bool work(int testcase) {
	int n = inf.readInt();
	std::string s = inf.readToken();
	std::string token = ouf.readToken("[A-Za-z]{1,10}", "token");
	if (token == "Shuiniao") {
		printf("Test case %d: OK. Participant's answer is NO (Shuiniao).\n", testcase);
		return true;
	} else if (token != "Huoyu") {
		printf("Test case %d: Wrong answer. Unknown token: Expected Huoyu or Shuiniao, but found %s.\n", testcase, token.c_str());
		quitf(_wa, "Wrong output format.");
		return false;
	}
	int k = ouf.readInt(1, n, "k");
	std::vector<std::vector<int>> a(k + 1);
	std::vector<int> l(k + 1);
	std::vector<int> vis(n + 1);
	for (int i = 1; i <= k; i++) {
		l[i] = ouf.readInt(1, n, format("l[%d]", i));
		a[i].resize(l[i] + 1);
		for (int j = 1; j <= l[i]; j++) {
			a[i][j] = ouf.readInt(1, n, format("a[%d][%d]", i, j));
			vis[a[i][j]]++;
		}
		for (int j = 1; j < l[i]; j++) {
			if (!(a[i][j] < a[i][j + 1])) {
				printf("Test case %d: Wrong answer. a[%d][%d] < a[%d][%d] does not hold in the output.\n", testcase, i, j, i, j + 1);
				return false;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] >= 2) {
			printf("Test case %d: Wrong answer. Multiple pairs (p,q) satisfy that a[p][q]=%d.\n", testcase, i);
			return false;
		}
		if (vis[i] == 0) {
			printf("Test case %d: Wrong answer. No pair (p,q) satisfies that a[p][q]=%d.\n", testcase, i);
			return false;
		}
	}
	for (int i = 1; i <= k; i++) {
		std::string t;
		for (int j = 1; j <= l[i]; j++) {
			t += s[a[i][j] - 1];
		}
		bool flag = false;
		for (int j = 1; j <= l[i]; j++) {
			if (t[j - 1] != t[l[i] - j]) {
				flag = true;
				break;
			}
		}
		if (flag == false) {
			printf("Test case %d: Wrong answer. The string t obtained in the subsequence a[%d] is palindrome.\n", testcase, i);
			return false;
		}
	}
	printf("Test case %d: OK. Participant's answer is YES (Huoyu), and k=%d.\n", testcase, k);
	return true;
}

int main(int argc, char **argv) {
	char *_argv[4] = { argv[0], argv[1], argv[2], argv[2] };
	registerTestlibCmd(4, _argv);
	int c = inf.readInt(), t = inf.readInt();
	int count = 0;
	for (int _ = 1; _ <= t; _++) {
		setTestCase(_);
		count += work(_);
	}
	if (count == t) {
		quitf(_ok, "%d / %d test cases passed. ", count, t);
	} else {
		unsetTestCase();
		quitf(_wa, "%d / %d test cases passed. ", count, t);
	}
	return 0;
}