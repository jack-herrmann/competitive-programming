#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int n;
	cin >> n;

	vector<int> bS;
	for (int i {0}; i < n; ++i) {
		int b;
		cin >> b;
		bS.push_back(b);
	}
	vector<int> c;
	for (int i {0}; i < n; ++i) {
		int b;
		cin >> b;
		c.push_back(b);
	}
	vector<vector<int>> paths (n, vector<int>());
	for (int i {0}; i < n; ++i) {
		int m;
		cin >> m;
		for (int j {0}; j < m; ++j) {
			int b;
			cin >> b;
			paths[i].push_back(b - 1);
		}
	}

	int cats {0};

	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		cats += c[u];
		int x = 0;
		for (int v : paths[u]) {
			if (bS[v] > bS[u]) {
				if (bS[v] > bS[x]) {
					x = v;
				}
			}
		}
		if (x != 0) {
			q.push(x);
		}
	}

	cout << cats;

	return 0;
}