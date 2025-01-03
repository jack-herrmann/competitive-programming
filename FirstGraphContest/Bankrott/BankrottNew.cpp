#include <bits/stdc++.h>

using namespace std;

int stationsR {0};
vector<int> rem;

void bfs(int s, vector<vector<int>> paths, int n) {
	vector<bool> vis(n + 1, false);
	vis[s] = true;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (find(rem.begin(), rem.end(), u) != rem.end()) {

		} else {
			bool in {0};
			for (int v : paths[u]) {
				if (find(rem.begin(), rem.end(), v) != rem.end()) {
					in = 1;
				}
			}
			if (!in) {
				stationsR++;
				rem.push_back(u);
			}
		}
		for (int v : paths[u]) {
			if (!vis[v]) {
				vis[v] = true;
				q.push(v);
			}
		}
	}
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
		vector<int> cnt (n + 1, 0);

		for (int i {0}; i < n - 1; ++i) {
			int f1;
			int f2;

			cin >> f1 >> f2;

			paths[f1].push_back(f2);
			paths[f2].push_back(f1);

			cnt[f1]++;
			cnt[f2]++;
		}

		for (int i {1}; i <= n; ++i) {
			// cout << cnt[i] << endl;
			if (cnt[i] <= 1) {
				stationsR++;
				rem.push_back(i);
			}
		}
		cout << "bef" << stationsR << endl;

		bfs(1, paths, n);

		cout << stationsR << endl;
		stationsR = 0;

	}

	return 0;
}