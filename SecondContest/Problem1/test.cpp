#include <bits/stdc++.h>

#define INFLL numeric_limits<long long>::max()/2
#define ll long long

using namespace std;

vector<vector<pair<long long, int>>> constructAdjListFromIpt() {
	int n; int m;
	cin >> n >> m;

	vector<vector<pair<long long, int>>> adj (n, vector<pair<long long, int>>());

	for (int i {0}; i < m; ++i) {
		int a; int b; int c;
		cin >> a >> b >> c;

		a--; b--;

		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	return adj;
}

vector<vector<ll>> floydWarshall() {
	int n; int m;
	cin >> n >> m;
	vector<vector<ll>> adj(n, vector<ll>(n, INFLL));

	for (int i {0}; i < m; ++i) {
		int a; int b; int c;
		cin >> a >> b >> c;
		a--; b--;

		if (c < adj[a][b]) {
			adj[a][b] = c;
		}
		if (c < adj[b][a]) {
			adj[b][a] = c;
		}
		if (adj[a][a] == INFLL) {
			adj[a][a] = 0;
		}
		if (adj[b][b] == INFLL) {
			adj[b][b] = 0;
		}
	}

	for (int k {0}; k < adj.size(); ++k) {
		for (int i {0}; i < adj.size(); ++i) {
			for (int j {0}; j < adj.size(); ++j) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
	return adj;
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

	for (int i = {0}; i < t; ++i) {

		auto adj = floydWarshall();
		int sm {0};

		for (auto j : adj) {
			for (auto k : j) {
				sm += k;
			}
		}
		cout << "Case #" << i + 1 << ": " << sm * 2 << "\n";
	}

	return 0;
}