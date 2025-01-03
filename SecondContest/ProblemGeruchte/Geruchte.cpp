#include <bits/stdc++.h>

#define INFLL numeric_limits<long long>::max()/2
#define ll long long

using namespace std;

int n;

vector<vector<pair<long long, int>>> constructAdjListFromIpt() {
	cin >> n;

	vector<vector<pair<long long, int>>> adj (n, vector<pair<long long, int>>());

	for (int i {0}; i < n; ++i) {
		for (int j {0}; j < n; ++j) {
			int a; cin >> a;
			if (i == 0) { continue; }
			if (i == j) { continue; } // maybe?
			if (a == 0) { continue; }
			adj[j].push_back({a, i});
		}
	}
	return adj;
}

long long dijkstraNot(vector<vector<pair<long long, int>>>& adj, int start) {
	vector<bool> vis(n, 0);
	vector<int> maxVal(n, 0);
	stack<int> s;
	long long d {0};
	s.push(start);
	while (!s.empty()) {
		auto v = s.top();
		s.pop();
		vis[v] = 1;
		for (auto p : adj[v]) {
			if (p.first > maxVal[p.second]) {
				maxVal[p.second] = p.first;
			}
			if (!vis[p.second]) {
				s.push(p.second);
			}
		}
	}
	for (int x {1}; x < n; ++x) {
		d += maxVal[x];
	}
	return d;
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
		auto d = dijkstraNot(adj, 0);

		cout << "Case #" << i + 1 << ": " << d << "\n";
	}

	return 0;
}