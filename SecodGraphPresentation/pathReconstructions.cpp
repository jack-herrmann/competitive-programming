#define INF numeric_limits<int>::max()/2
#define INFLL numeric_limits<long long>::max()/2
#define ll long long

#include <bits/stdc++.h>

using namespace std;

/*
vector<vector<ll>> constructAdjMatrixFromIpt() {
	int n;
	cin >> n;
	vector<vector<ll>> adj(n, vector<ll>(n, INF));
	for (int i {0}; i < n; ++i) {
		int a; int b; int c;
		cin >> a >> b >> c;
		adj[a][b] = c;
		adj[b][a] = c;
		if (adj[a][a] == INF) {
			adj[a][a] = 0;
		}
		if (adj[b][b] == INF) {
			adj[b][b] = 0;
		}
	}
	return adj;
}
*/

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

pair<vector<ll>, vector<ll>> dijkstra(vector<vector<pair<ll, int>>>& adj, int start) {
	vector<ll> dist(adj.size(), INFLL);
	vector<ll> prev(adj.size(), -1);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	dist[start] = 0;
	prev[start] = start;
	pq.push({0, start});
	while (pq.size()) {
		auto [d, v] = pq.top();
		pq.pop();
		if (dist[v] < d) { continue; }
		for (auto p : adj[v]) {
			int newD;
			newD = p.second + d;
			if (newD < dist[p.first]) {
				dist[p.first] = newD;
				prev[p.first] = v;
				pq.push({newD, p.first});
			}
		}
	}
	return {dist, prev};
}

pair<vector<ll>, vector<ll>> bellmanFord(vector<vector<pair<ll, int>>>& adj, int start) {
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
	return {dist, prev};
}

pair<vector<vector<ll>>, vector<vector<ll>>> floydWarshall() {
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
	return {adj, next};
}

vector<int> pathDBF(vector<ll>& prev, int u, int v) {
	vector<int> path;
	path.push_back(v);
	while (u != v) {
		v = prev[v];
		path.push_back(v);
	}
	return path;
}

vector<int> pathFW(vector<vector<ll>>& next, int u, int v) {
	vector<int> path;
	if (next[u][v] == INFLL) {
		return vector<int>();
	}
	path.push_back(u);
	while (u != v) {
		u = next[u][v];
		path.push_back(u);
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

	auto adj = constructAdjListFromIpt();
	auto [dist, prev] = bellmanFord(adj, 0);
	// auto [adj, next] = floydWarshall();

	for (auto p : pathDBF(prev, 0, 4)) { // pathFW
		cout << p << "\n";
	}

	cout << dist[adj.size() - 1] << "\n";
	// cout << adj[0][adj.size() - 1] << "\n";

	return 0;
}
