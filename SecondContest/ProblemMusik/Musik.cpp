#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t;

	cin >> t;

	double lengOfWhole = 0.0;

	for (int i {0}; i < t; ++i) {
		double l;
		cin >> l;

		if (l == 0.0) {
			lengOfWhole += 2.0;
		} else {
			lengOfWhole += (double)(1 / l);
		}
	}

	cout << lengOfWhole << endl;

	return 0;
}