#include <bits/stdc++.h>

using namespace std;

vector<int> pay(vector<int> values, int c, vector<int> used) {
	if (c == 0) {
		return used;
	}
	vector<int> minLenPay;
	int minLen = 10e6;
	for (int x {0}; x < values.size(); ++x) {
		int v;
		v = values[x];
		if (c - v >= 0) {
			vector<int> newUsed;
			newUsed = used;
			++newUsed[x];
			// for (auto y : newUsed) {
			// 	cout << y << endl;
			// }
			vector<int>::const_iterator first = values.begin() + x + 1;
			vector<int> newVals(first, values.end());
			auto res = pay(newVals, c - v, newUsed);
			int resSize = accumulate(res.begin(), res.end(), 0);
			if (resSize < minLen) {
				minLenPay = res;
				minLen = resSize;
			}
		}
	}
	return minLenPay;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;

	cin >> t;
	vector<int> values;

	for (int i {0}; i < t; ++i) {
		int n; int c;
		cin >> n >> c;
		for (int j {0}; j < n; ++j) {
			int v;
			cin >> v;
			values.push_back(v);
		}
		auto res = pay(values, c, vector<int>(n, 0));
		for (auto x : res) {
			cout << x << endl;
		}
	}

	return 0;
}