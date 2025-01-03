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

	for (int i {1}; i <= t; ++i) {

		int n;
		cin >> n;

		vector<vector<int>> schools;
		for (int j {0}; j < n; ++j) {
			vector<int> values;
			for (int k {0}; k < 5; ++k) {
				int s;
				cin >> s;
				values.push_back(s);
			}
			sort(values.begin(), values.end(), greater<int>());
			schools.push_back(values);
		}

		vector<int> wins (n, 0);
		vector<vector<int>> order (n, vector<int>());

		for (int j {0}; j < n - 1; ++j) {
			for (int k {j + 1}; k < n; ++k) {
				int winner = n + 2;
				for (int l {0}; l < 5; ++l) {
					if (schools[j][l] > schools[k][l]) {
						winner = j;
						break;
					} else if (schools[j][l] < schools[k][l]) {
						winner = k;
						break;
					}
				}
				if (winner == n + 2) { // check
					winner = j;
				}
				wins[winner]++;
			}
		}
		for (int j {0}; j < n; ++j) {
			order[n - 1 - wins[j]] = schools[j];
		}
		cout << "Case #" << i << ": \n";
		for (int j {0}; j < n; ++j) {
			for (int k {0}; k < 5; ++k) {
				cout << order[j][k] << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}