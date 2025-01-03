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

	for (int i = 1; i <= t; ++i) {
		int n1; int n2; double w;
		cin >> n1 >> n2 >> w;

		vector<double> l;
		for (int j = 1; j <= n1; ++j) {
			double x; cin >> x;
			l.push_back(x);
		}
		vector<double> b;
		for (int j = 1; j <= n2; ++j) {
			double x; cin >> x;
			b.push_back(x);
		}
		sort(l.begin(), l.end());
		sort(b.begin(), b.end());

		double end {0};
		for (auto it : l) {
			if (it == 0) {
				end += (w / 2);
				continue;
			}
			if (end < (it - (w / 2))) {
				cout << "Case #" << i << ": NO" << "\n";
				goto endLabel;
			}
			end = (it + (w / 2));
		}
		if (end < 75) {
			cout << "Case #" << i << ": NO" << "\n";
			continue;
		}

		end = 0;
		for (auto it : b) {
			if (it == 0) {
				end += (w / 2);
				continue;
			}
			if (end < (it - (w / 2))) {
				cout << "Case #" << i << ": NO" << "\n";
				goto endLabel;
			}
			end = (it + (w / 2));
		}
		if (end < 100) {
			cout << "Case #" << i << ": NO" << "\n";
			continue;
		}

		cout << "Case #" << i << ": YES" << "\n";
endLabel:
		continue;
	}

	return 0;
}