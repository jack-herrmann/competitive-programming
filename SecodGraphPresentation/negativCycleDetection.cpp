#define INF numeric_limits<int>::max()/2
#define INFLL numeric_limits<long long>::max()/2
#define ll long long

#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<long long, int>>> constructAdjListFromIpt() {
	int n;
	cin >> n;

	vector<vector<pair<long long, int>>> adj (n, vector<pair<long long, int>>());

	for (int i {0}; i < n; ++i) {
		int a; int b; int c;
		cin >> a >> b >> c;

		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	return adj;
}

bool bellmanFord(vector<vector<pair<ll, int>>>& adj, int start) {
	vector<ll> dist(adj.size(), INFLL);
	vector<ll> prev(adj.size(), -1);
	dist[start] = 0;
	prev[start] = start;
	for (int i {0}; i < adj.size() - 1; ++i) {
		for (int v {0}; v < adj.size(); ++v) {
			for (auto p : adj[v]) {
				if (dist[v] + p.second < dist[p.first]) {
					dist[p.first] = dist[v] + p.second;
					prev[p.first] = v;
				}
			}
		}
	}
	for (int i {0}; i < adj.size() - 1; ++i) {
		for (int v {0}; v < adj.size(); ++v) {
			for (auto p : adj[v]) {
				if (dist[v] + p.second < dist[p.first]) {
					dist[p.first] = dist[v] + p.second;
					cout << p.first << "\n";
				}
			}
		}
	}
	return 0;
}

bool floydWarshall() {
	int n;
	cin >> n;
	vector<vector<ll>> adj(n, vector<ll>(n, INFLL));
	vector<vector<ll>> next(n, vector<ll>(n, INFLL));

	for (int i {0}; i < n; ++i) {
		int a; int b; int c;
		cin >> a >> b >> c;
		adj[a][b] = c;
		adj[b][a] = c;
		next[a][b] = b;
		next[b][a] = a;
		if (adj[a][a] == INFLL) {
			adj[a][a] = 0;
		}
		if (adj[b][b] == INFLL) {
			adj[b][b] = 0;
		}
		if (next[a][a] == INFLL) {
			next[a][a] = a;
		}
		if (next[b][b] == INFLL) {
			next[b][b] = b;
		}
	}

	for (int k {0}; k < adj.size(); ++k) {
		for (int i {0}; i < adj.size(); ++i) {
			for (int j {0}; j < adj.size(); ++j) {
				if (adj[i][j] > adj[i][k] + adj[k][j]) {
					adj[i][j] = adj[i][k] + adj[k][j];
					next[i][j] = next[i][k];
				}
			}
		}
	}

	for (int i {0}; i < n; ++i) {
		if (adj[i][i] < 0) {
			return 1;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	auto adj = constructAdjListFromIpt();
	cout << bellmanFord(adj, 0) << "\n";
	// cout << floydWarshall() << "\n";

	return 0;
}
