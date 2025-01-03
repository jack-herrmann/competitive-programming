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

	int prev {0};
	int stocks {0};
	unsigned long long money {100};

	for (int i {0}; i < n; ++i) {

		int c;
		cin >> c;

		if ((stocks == 0) && (c <= money)) {
			stocks = floor(money / c);
			money = money % c;
		}

		if (prev > c) {
			money += prev * stocks;
			stocks = floor(money / c);
			money = money % c;
		}

		prev = c;
	}

	cout << money + (stocks * prev) << endl;

	return 0;
}