#include <bits/stdc++.h>

using namespace std;

vector<long long> dijkstra(vector<vector<pair<int, long long>>>& adj, int start) {
	vector<long long> dist(adj.size(), 10e17);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({0, start});
	while (!pq.empty()) {
		long long d; int v;
		tie(d, v) = pq.top();
		pq.pop();
		if (dist[v] <= d) { continue; }
		dist[v] = d;
		for (auto p : adj[v]) {
			pq.push({d + p.second, p.first});
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

	for (int i {1}; i <= t; ++i) {

		int nodes; int paths; int stations;
		cin >> nodes >> paths >> stations;

		vector<vector<pair<int, long long>>> adj(nodes, vector<pair<int, long long>>());

		for (int j {0}; j < paths; ++j) {
			int a; int b; int c;
			cin >> a >> b >> c;
			a--; b--;
			adj[a].emplace_back(b, c);
			adj[b].emplace_back(a, c);
		}

		vector<int> stationsPos (nodes, 0);
		for (int j {0}; j < stations; ++j) {
			int s;
			cin >> s;
			s--;
			stationsPos[s] = 1;
		}

		vector<long long> dist;
		dist = dijkstra(adj, 0);

		int minCosts {numeric_limits<int>::max()};
		vector<int> stationsWith;
		for (int j {0}; j < dist.size(); ++j) {
			if ((dist[j] < minCosts) && (stationsPos[j] == 1)) {
				minCosts = dist[j];
				stationsWith.clear();
				stationsWith.push_back(j + 1);
			} else if ((dist[j] == minCosts) && (stationsPos[j] == 1)) {
				stationsWith.push_back(j + 1);
			}
		}

		cout << "Case #" << i << ": " << minCosts << " ";
		for (auto j : stationsWith) {
			cout << j << " ";
		}
		cout << "\n";
	}

	return 0;
}