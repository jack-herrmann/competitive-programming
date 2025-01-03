// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>

#define intMax numeric_limits<int>::max()

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;

	for (int k {1}; k <= t; ++k) {
		int n; int c;
		cin >> n >> c;

		vector<int> coins(n);
		for (int j {0}; j < n; ++j) { cin >> coins[j]; }

		vector<int> mem(c + 1, numeric_limits<int>::max());
		mem[0] = 0;
		vector<int> u(c + 1);

		for (int i {0}; i <= c; ++i) {

			for (auto x : coins) {
				if (i + x <= c) {
					if (mem[i] + 1 < mem[i + x]) {
						mem[i + x] = mem[i] + 1;
						u[i + x] = x;
					}
				}
			}
		}

		int current = c;
		map<int, int> amount;
		while (current != 0) {
			amount[u[current]]++;
			current -= u[current];
		}

		cout << "Case #" << k << ": "; // check if k/t was the issue
		for (int coin : coins)
			cout << " " << amount[coin];
		cout << "\n";
	}

	return 0;
}