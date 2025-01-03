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

// if minimax shortest path, then keep track of distance aswell, but use only if d is same
vector<ll> dijkstra(vector<vector<pair<ll, int>>>& adj, int start) {
	vector<ll> dist(adj.size(), INFLL);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	dist[start] = 0;
	pq.push({0, start});
	while (pq.size()) {
		auto [d, v] = pq.top();
		pq.pop();
		if (dist[v] < d) { continue; }
		for (auto p : adj[v]) {
			int newD;
			newD = max(dist[v], static_cast<long long>(p.second));
			if (newD < dist[p.first]) {
				dist[p.first] = newD;
				pq.push({newD, p.first});
			}
		}
	}
	return dist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	auto adj = constructAdjListFromIpt();
	auto dist = dijkstra(adj, 0);

	cout << dist[3] << "\n";

	return 0;
}
