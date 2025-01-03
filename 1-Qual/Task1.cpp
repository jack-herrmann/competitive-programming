#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int>>& g, int start, int n, vector<int>& vis) {
	int zero {1};
	int one {0};
	vis[start] = 0;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : g[u]) {
			if (vis[v] == -1) {
				vis[v] = abs(vis[u] - 1);
				if (abs(vis[u] - 1) == 0) { zero += 1; } else { one += 1; }
				q.push(v);
			} else if (vis[v] == vis[u]) {
				return -1;
			}
		}
	}
	return max(zero, one);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int n; int m;

	cin >> n >> m;

	vector<vector<int>> g(n);

	for (int i {0}; i < m; ++i) {

		int a; int b;
		cin >> a >> b;
		a--; b--;

		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<int> vis(n, -1);
	int blue {0};

	for (int i {0}; i < n; ++i) {
		if (vis[i] == -1) {
			int res = bfs(g, i, n, vis);
			if (res == -1) {
				cout << "NEIN\n";
				return 0;
			} else { blue += res; }
		}
	}

	cout << "JA\n";
	cout << blue << "\n";

	return 0;
}