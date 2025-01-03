#include <bits/stdc++.h>

#define INFLL numeric_limits<long long>::max()/2
#define ll long long

using namespace std;

int n; int m;

vector<vector<pair<long long, int>>> constructAdjListFromIpt() {
	cin >> n >> m;

	vector<vector<pair<long long, int>>> adj (n, vector<pair<long long, int>>());

	for (int i {0}; i < m; ++i) {
		int a; int b; int c;
		cin >> a >> b >> c;

		a--; b--;

		adj[a].push_back({c, b});
		adj[b].push_back({c, a});
	}
	return adj;
}

vector<long long> dijkstra(vector<vector<pair<long long, int>>>& adj, int start) {
	vector<long long> dist(adj.size(), INFLL);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({0, start});
	while (pq.size()) {
		auto [d, v] = pq.top();
		pq.pop();
		if (dist[v] <= d) { continue; }
		dist[v] = d;
		for (auto p : adj[v]) {
			pq.push({d + p.first, p.second});
		}
	}
	return dist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t;

	cin >> t;

	for (int i = {0}; i < t; ++i) {

		auto adj = constructAdjListFromIpt();

		long long wholeSm {0};

		for (int j {0}; j < n; ++j) {
			auto dist = dijkstra(adj, j);
			long long sm = accumulate(dist.begin(), dist.end(), 0);
			wholeSm += sm;
		}

		cout << "Case #" << i + 1 << ": " << wholeSm * 2 << "\n";
	}

	return 0;
}