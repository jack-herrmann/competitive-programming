#include <bits/stdc++.h>

#define INFLL numeric_limits<long long>::max()/2
#define ll long long

using namespace std;

int n; int m; int l;

pair<vector<vector<int>>, set<pair<int, int>>> constructAdjListFromIpt() {
	cin >> n >> m >> l;

	vector<vector<int>> adj(n, vector<int>());
	set<pair<int, int>> doubleWay;

	for (int i {0}; i < m; ++i) {
		int a; int b;
		cin >> a >> b;

		a--; b--;

		adj[a].push_back(b);
	}
	for (int i {0}; i < l; ++i) {
		int a; int b;
		cin >> a >> b;

		a--; b--;

		adj[a].push_back(b);
		adj[b].push_back(a);

		doubleWay.insert({a, b});
	}

	return {adj, doubleWay};
}

vector<pair<int, int>> dijkstraNot(vector<vector<int>>& adj, int start, set<pair<int, int>>& doubleWay) {
	vector<pair<int, int>> newWays;
	vector<bool> vis(n, 0);
	queue<int> s;
	s.push(start);
	while (s.size()) {
		auto v = s.front();
		s.pop();
		// if (vis[v]) { continue; }
		// vis[v] = 1;
		for (auto p : adj[v]) {
			if (doubleWay.find({p, v}) != doubleWay.end()) {
				newWays.push_back({v, p});
				adj[p].erase(remove(adj[p].begin(), adj[p].end(), v), adj[p].end());
			} else if (doubleWay.find({v, p}) != doubleWay.end()) {
				newWays.push_back({v, p});
				adj[p].erase(remove(adj[p].begin(), adj[p].end(), v), adj[p].end());
			}
			if (!vis[p]) {
				s.push(p);
				vis[p] = 1;
			}
		}
	}
	return newWays;
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

		auto [adj, doubleWay] = constructAdjListFromIpt();

		for (auto x : dijkstraNot(adj, 0, doubleWay)) {
			cout << x.first << " " << x.second << "\n";
		}

		// cal dijkstraNot

		// cout << "Case #" << i + 1 << ": " << wholeSm * 2 << "\n";
	}

	return 0;
}