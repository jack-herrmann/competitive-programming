#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(int s, vector<vector<int>> g, int n) {
	vector<bool> vis(n, false);
	vector<int> pred(n, 0);
	vis[s] = true;
	// int d {1};
	queue<int> q;
	q.push(s);
	int last {0};
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : g[u]) {
			if (!vis[v]) {
				vis[v] = true;
				q.push(v);
				pred[v] = u;
			}
		}
		last = u;
	}
	// while (last != s) {
	// 	last = pred[last];
	// 	d++;
	// }
	// return d;
	vector<int> path;
	path.push_back(last);
	while (last != s) {
		last = pred[last];
		path.push_back(last);
	}
	return path;
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

		vector<vector<int>> g (n, vector<int>(0));

		for (int i {0}; i < n - 1; ++i) {
			int s;
			int e;

			cin >> s >> e;

			if ((g[s].size() == 0) || (g[e].size() == 0)) {
				g[s].push_back(e);
				g[e].push_back(s);
			}

		}
		vector<int> l; vector<int> x;
		l = bfs(0, g, n);
		x = bfs(l[0], g, n);

		int leng;
		leng = ceil(x.size() / 2);
		int with;
		with = x[leng];


		// int minMax {999};
		// int with {0};
		// for (int i {0}; i < n; ++i) {
		// 	int m;
		// 	m = bfs(i, g, n);
		// 	if (m < minMax) {
		// 		minMax = m;
		// 		with = i;
		// 	}
		// }

		cout << "Case #" << j << ": " << with << "\n";

	}

	return 0;
}