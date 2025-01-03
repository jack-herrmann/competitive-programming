#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int n;
	cin >> n;

	vector<double> costs(n);

	for (int i {0}; i < n; ++i) { cin >> costs[i]; }

	sort(costs.begin(), costs.end());

	vector<double> b;
	b.push_back(0);

	for (int i {0}; i < n; ++i) {

		double d2 {numeric_limits<double>::max()}; double d3 {numeric_limits<double>::max()};

		double d1 {costs[i] + b[i]};
		if (i == 0) { goto after; }
		d2 = costs[i] + (costs[i - 1] / 2) + b[i - 1];
		if (i == 1) { goto after; }
		d3 = costs[i] + costs[i - 1] + b[i - 2];

after:

		b.push_back(min(d1, min(d2, d3)));
	}

	cout << (int) floor(b[n]) << " Euro " << fmod(b[n], 1) * 100 << " Cent" << "\n";

	return 0;
}