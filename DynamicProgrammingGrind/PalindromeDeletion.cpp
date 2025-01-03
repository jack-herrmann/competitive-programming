#include <bits/stdc++.h>

using namespace std;

int palindromeDel(string n, int start, int end, vector<vector<int>>& mem) {

	if (start > end) { return 0; }
	if (end == start) { return 1; }

	if (mem[start][end] != -1) { return mem[start][end]; }

	int mn {numeric_limits<int>::max()};
	mn = min(mn, palindromeDel(n, start + 1, end, mem) + 1);

	if (n[start] == n[start + 1]) {
		mn = min(mn, palindromeDel(n, start + 2, end, mem) + 1);
	}

	for (int i {start + 2}; i <= end; ++i) {
		if (n[start] == n[i]) {
			mn = min(mn, palindromeDel(n, start + 1, i - 1, mem) + palindromeDel(n, i + 1, end, mem));
		}
	}
	mem[start][end] = mn;
	return mem[start][end];
}

int palindromeDelBU(string n) {

	vector<vector<int>> mem(n.size() + 1, vector<int>(n.size() + 1, 0));

	for (int len {1}; len <= n.size(); ++len) {
		for (int start {0}, end {len - 1}; end < n.size(); ++start, ++end) {

			if (len == 1) { mem[start][end] = 1; } else {

				mem[start][end] = mem[start + 1][end] + 1;

				if (n[start] == n[start + 1]) {
					mem[start][end] = min(mem[start][end], mem[start + 2][end] + 1);
				}

				for (int i {start + 2}; i <= end; ++i) {
					if (n[start] == n[i]) {
						mem[start][end] = min(mem[start][end], mem[start + 1][i - 1] + mem[i + 1][end]);
					}
				}
			}
		}
	}

	return mem[0][n.size() - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string n = "aabcgdz";

	vector<vector<int>> mem(n.size(), vector<int>(n.size(), -1));

	cout << palindromeDel(n, 0, n.size() - 1, mem) << endl;
	cout << palindromeDelBU(n) << endl;

	return 0;
}