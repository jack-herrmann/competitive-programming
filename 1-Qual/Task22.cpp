#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	vector<int> eta;
	for (int i {0}; i < n; ++i) {
		int a; cin >> a;
		eta.push_back(a);
	}

	vector<int> wp;
	for (int i {0}; i < n; ++i) {
		int a; cin >> a;
		wp.push_back(a);
	}

	vector<vector<bool>> dp(n, vector<int>(n));

	for (int i {0}; i < n; ++i) {
		for (int j {0}; j < n; ++j) {
			dp[i][j] = (eta[i] < wp[j]);
		}
	}

	return 0;
}