#include <bits/stdc++.h>

// dp presentation: output trick

using namespace std;

int lcs(string a, string b, int n, int m) {

	if ((n == 0) || (m == 0)) { return 0; }
	if (a[n - 1] == b[m - 1]) { return lcs(a, b, n - 1, m - 1) + 1; }
	else { return max(lcs(a, b, n - 1, m), lcs(a, b, n, m - 1)); }
}

int lcsMem(string a, string b, int n, int m, vector<vector<int>>& mem) {

	if (mem[n][m] != -1) { return mem[n][m]; }
	if ((n == 0) || (m == 0)) { mem[n][m] = 0; return mem[n][m]; }
	if (a[n - 1] == b[m - 1]) { mem[n][m] = lcs(a, b, n - 1, m - 1) + 1; return mem[n][m]; }
	else { mem[n][m] = max(lcs(a, b, n - 1, m), lcs(a, b, n, m - 1)); return mem[n][m]; }
}

int lcsBU(string a, string b, int n, int m) {

	vector<vector<int>> mem(n + 1, vector<int>(m + 1, -1));

	for (int i {0}; i <= n; ++i) {

		for (int j {0}; j <= m; ++j) {

			if ((i == 0) || (j == 0)) { mem[i][j] = 0; }
			if (a[i - 1] == b[j - 1]) { mem[i][j] = mem[i - 1][j - 1] + 1; }
			else { mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]); }
		}
	}

	return mem[n][m];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<int>> mem(8, vector<int>(9, -1));

	cout << lcs("bdcabac", "bcabdcac", 7, 8) << endl;
	cout << lcsMem("bdcabac", "bcabdcac", 7, 8, mem) << endl;
	cout << lcsBU("bdcabac", "bcabdcac", 7, 8) << endl;

	return 0;
}