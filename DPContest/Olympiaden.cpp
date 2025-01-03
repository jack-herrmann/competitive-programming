#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int tests;
	cin >> tests;

	for (int t {1}; t <= tests; ++t) {
		int n; int b; int h; int w;
		cin >> n >> b >> h >> w;

		int mn { numeric_limits<int>::max() };

		for (int i {0}; i < h; ++i) {

			int c;
			cin >> c;

			for (int j {0}; j < w; ++j) {

				int p;
				cin >> p;
				if ((p >= n) && (n * c < mn)) { mn = n * c; }
			}
		}

		if (mn <= b) { cout << "Case #" << t << ": " << mn << endl; }
		else { cout << "Case #" << t << ": " << "stay home" << endl; }
	}

	return 0;
}