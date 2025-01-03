#include <bits/stdc++.h>

using namespace std;

int zeroDouble {0};
int oneDouble {0};

bool bfs(int s, vector<vector<int>> paths, vector<int>& teams) {
	teams[s] = 1;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : paths[u]) {
			if (teams[v] == -1) {
				teams[v] = abs(teams[u] - 1);
				q.push(v);
			} else if (teams[v] == teams[u]) {
				if (teams[v] == 0) {
					zeroDouble += 1;
				} else {
					oneDouble += 1;
				}
			}
		}
	}
	return 1;
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

	for (int j {1}; j <= t; ++j) {

		int n;

		cin >> n;

		vector<vector<int>> paths (n + 1, vector<int>());
		vector<int> teams (n + 1, -1);
		teams[0] = 3;

		for (int i {0}; i < n - 1; ++i) {
			int f1;
			int f2;

			cin >> f1 >> f2;

			paths[f1].push_back(f2);
			paths[f2].push_back(f1);
		}

		int idx {0};

		while (count(teams.begin(), teams.end(), -1) != 0) {
			if (!bfs(idx, paths, teams)) {
				cout << "IMPOSSIBLE\n";
				return 0;
			}
			for (int i {1}; i <= n; ++i) {
				if (teams[i] == -1) {
					idx = i;
					break;
				}
			}
		}

		int one {0};
		int zero {0};

		teams[0] = 3;

		for (auto i : teams) {
			if (i == 0) {
				zero += 1;
			} else if (i == 1) {
				one += 1;
			}
		}

		one -= oneDouble;
		zero -= zeroDouble;

		cout << "Case #" << j << ": " << max(zero, one) << "\n";

	}

	return 0;
}