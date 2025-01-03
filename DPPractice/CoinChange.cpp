#include <bits/stdc++.h>

// dp presentation: output trick

using namespace std;

int coinChange(vector<int>& coins, int n) {

	if (n < 0) { return numeric_limits<int>::max() - 1; }
	if (n == 0) { return 0; }

	int mn {numeric_limits<int>::max()};
	for (auto x : coins) {
		int res;
		res = coinChange(coins, n - x) + 1;
		if (res < mn) {
			mn = res;
		}
	}
	return mn;
}

int coinChangeMem(vector<int>& coins, int n, vector<int>& mem) { // if track, just return [] and do + {x} instead +1

	if (n == 0) { return 0; }
	if (n < 0) { return numeric_limits<int>::max() - 1; }

	if (mem[n] != -1) { return mem[n]; }

	int mn {numeric_limits<int>::max()};
	for (auto x : coins) {
		int res;
		res = coinChangeMem(coins, n - x, mem) + 1; // if limited just change pass-by up top and remove coin from vec here
		if (res < mn) {
			mn = res;
		}
	}
	mem[n] = mn;
	return mem[n];
}

int coinChangeBU(vector<int>& coins, int n) {

	vector<int> mem(n + 1, numeric_limits<int>::max());
	mem[0] = 0;

	for (int i {0}; i <= n; ++i) {

		for (auto x : coins) {
			if (i + x <= n) {
				mem[i + x] = min(mem[i + x], mem[i] + 1);
			}
		}
	}
	return mem[n];
}

int coinChangeBULtm(vector<int>& coins, int n) {

	vector<vector<int>> left(n + 1, vector<int>());
	vector<int> mem(n + 1, numeric_limits<int>::max());
	mem[0] = 0;
	left[0] = coins;

	for (int i {0}; i <= n; ++i) {

		for (int j {0}; j < left[i].size(); ++j) {
			auto x = left[i][j];
			if (i + x <= n) {
				if (mem[i] + 1 < mem[i + x]) {
					mem[i + x] = mem[i] + 1;
					vector<int> temp = left[i];
					temp.erase(temp.begin() + j);
					left[i + x] = temp;
				}
			}
		}
	}
	if (mem[n] == numeric_limits<int>::max()) { return 0; }
	// cout coins used
	return mem[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> mem(1201, -1);
	vector<int> coins;
	coins.push_back(1);
	coins.push_back(3);
	coins.push_back(5);
	coins.push_back(6);

	// cout << coinChange(coins, 1200) << endl; // to slow for 1200
	// cout << coinChangeMem(coins, 1200, mem) << endl;
	// cout << coinChangeBU(coins, 1200) << endl;
	cout << coinChangeBULtm(coins, 12) << endl;

	return 0;
}