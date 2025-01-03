#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {

		int n, c;
		cin >> n >> c;
		vector<int> best(c + 1, c); //lowest amount of coins to acheive this value
		vector<int> used(c + 1); //last coin used to acheive this
		vector<int> coins(n);
		for (int i = 0; i < n; i++)
			cin >> coins[i];

		//fill dynamic programming arrays
		best[0] = 0;
		for (int i = 0; i <= c; i++) {
			for (int coin : coins) {
				if (i - coin < 0)
					continue;
				if (best[i - coin] < best[i]) {
					best[i] = best[i - coin] + 1;
					used[i] = coin;
				}
			}
		}

		//collect amounts
		int current = c;
		map<int, int> amount;
		while (current != 0) {
			amount[used[current]]++;
			current -= used[current];
		}

		//output
		cout << "Case #" << t << ": ";
		for (int coin : coins)
			cout << " " << amount[coin];
		cout << "\n";
	}
}
