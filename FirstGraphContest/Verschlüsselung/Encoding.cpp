#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int numK;
	int numM;

	cin >> numK >> numM;

	vector<int> keys;
	for (int i {0}; i < numK; ++i) {
		int k;
		cin >> k;
		keys.push_back(k);
	}

	sort(keys.begin(), keys.end());

	for (int i {0}; i < numM; ++i) {
		int x; int y;
		cin >> x >> y;
		cout << x - keys[y - 1] << "\n";
	}

	return 0;
}