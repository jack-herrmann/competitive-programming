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

	for (int i = 1; i <= t; ++i) {
		int m; int n;
		cin >> m >> n;
		vector<int> points;
		vector<vector<int>> g(m, vector<int>());
		vector<int> in(m, 0);

		for (int j = 0; j < m; ++j) {
			int val;
			cin >> val;
			points.push_back(val);
		}

		for (int j = 0; j < n; ++j) {
			int a; int b;
			cin >> a >> b;
			a--; b--;
			g[a].push_back(b);
			in[b]++;
		}

		stack<int> s;
		for (int u {0}; u < m; ++u) {
			if (in[u] == 0) {
				s.push(u);
			}
		}

		vector<int> topOrder;
		while (!s.empty()) {
			int u = s.top();
			s.pop();
			topOrder.push_back(u);
			for (int v : g[u]) {
				in[v]--;
				if (in[v] == 0) {
					s.push(v);
				}
			}
		}

		int pointsTotal {0};
		for (auto ele : topOrder) {
			pointsTotal += points[ele];
		}
		cout << "Case #" << i << ": " << pointsTotal << endl;


	}

	return 0;
}