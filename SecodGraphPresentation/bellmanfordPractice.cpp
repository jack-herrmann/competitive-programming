#define INF numeric_limits<int>::max()/2
#define ll long long

vector<ll> bellmanFord(vector<vector<pair<ll, int>>>& adj, int start) {
	vector<ll> dist(adj.size(), INF);
	dist[start] = 0;
	for (int i {0}; i < adj.size() - 1; ++i) {
		for (int v {0}; v < adj.size(); ++v) {
			for (auto p : adj[v]) {
				dist[p.first] = min(dist[p.first], dist[v] + p.second);
			}
		}
	}
	return dist;
}


vector<ll> bellmanFord(vector<vector<pair<ll, int>>>& adj, int start) {
	vector<ll> dist(adj.size(), INF);
	dist[start] = 0;
	for (int i {0}; i < adj.size() - 1; ++i) {
		for (int v {0}; v < adj.size(); ++v) {
			for (auto p : adj[v]) {
				dist[p.first] = min(dist[p.first], dist[v] + p.second);
			}
		}
	}
	return dist;
}


vector<ll> bellmanFord(vector<vector<pair<ll, int>>>& adj, int start) {
	vector<ll> dist(adj.size(), INF);
	dist[start] = 0;
	for (int i {0}; i < adj, size() - 1; ++i) {
		for (int v {0}; v < adj.size(); ++v) {
			for (auto p : adj[v]) {
				dist[p.first] = min(dist[p.first], dist[v] + p.second);
			}
		}
	}
	return dist;
}

