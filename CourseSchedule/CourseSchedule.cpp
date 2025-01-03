#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	int m;

	cin >> n >> m;

	vector<vector<int>> bef (n + 1, vector<int>());
	vector<pair<int, int>> edges (m);

	for (int i {0}; i < m; ++i) {
		int c1;
		int c2;

		cin >> c1 >> c2;

		bef[c1].push_back(c2);
		edges.push_back(pair(c1, c2));
	}

	vector<int> in(n + 1);
	for (auto [u, v] : edges) {
		in[v]++;
	}
	stack<int> s;
	for (int i {1}; i <= n; ++i) {
		if (in[i] == 0) {
			s.push(i);
		}
	}
	vector<int> topOrder;
	while (!s.empty()) {
		int u = s.top();
		s.pop();
		topOrder.push_back(u);
		for (int v : bef[u]) {
			if (--in[v] == 0) {
				s.push(v);
			}
		}
	}

	if (topOrder.size() != n) {
		cout << "IMPOSSIBLE";
		return 0;
	}

	for (auto i : topOrder) {
		cout << i << " ";
	}

	return 0;
}