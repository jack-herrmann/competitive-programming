#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	long long n;
	long long m {0};
	cin >> n;

	for (int i {0}; i < n; ++i) {
		long long j;
		cin >> j;
		if (j > m) {
			m = j;
		}
	}

	cout << m * m * m << "\n";

	return 0;
}