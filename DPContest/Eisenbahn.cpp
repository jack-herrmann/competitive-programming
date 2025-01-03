#include <bits/stdc++.h>

#define tiii tuple<int, int, int>

using namespace std;

vector<int> init(int n) {
	vector<int> par(n);
	iota(par.begin(), par.end(), 0);
	return par;
}

int find(int i, vector<int>& par) {
	if (par[i] == i) return i;
	return (par[i] = find(par[i], par));
}

void unite(int i, int j, vector<int>& par) {
	i = find(i, par); j = find(j, par);
	par[i] = j;
}

int kruskal(vector<tiii> kanten, int n) {
	int res {0};

	sort(kanten.begin(), kanten.end());
	vector<int> uf = init(n);
	for (tiii kante : kanten) {
		int w, a, b;
		tie(w, a, b) = kante;
		if (find(a, uf) != find(b, uf)) {
			res += get<0>(kante);
			unite(a, b, uf);
		}
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int n; int m; int l;
	cin >> n >> m >> l;

	int track {0};

	vector<tiii> g;
	vector<vector<int>> g2(n);

	for (int i {0}; i < m; ++i) {

		int a; int b; int lng;
		cin >> a >> b >> lng;

		a--; b--;

		g2[a].push_back(b);
		g2[b].push_back(a);

		g.push_back({lng, a, b});
		g.push_back({lng, b, a});

		if (i < l) { track += lng; }
	}

	vector<bool> vis(n, false);
	stack<int> s;
	s.push(0);
	while (!s.empty()) {
		int u = s.top();
		s.pop();
		if (vis[u]) { continue; }
		vis[u] = true;
		for (int v : g2[u]) {
			if (!vis[v]) {
				s.push(v);
			}
		}
	}

	if (find(vis.begin(), vis.end(), false) != vis.end()) {
		cout << "impossible" << endl;
		return 0;
	}

	if (kruskal(g, n) > track) {
		cout << "impossible" << endl;
	} else {
		cout << "possible" << endl;
	}

	return 0;
}