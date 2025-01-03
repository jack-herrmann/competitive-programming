#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;

	for (int j {1}; j <= t; ++j) {

		int n;

		cin >> n;

		vector<pair<int, int>> edges;

		for (int i {0}; i < n - 1; ++i) {
			int f1;
			int f2;

			cin >> f1 >> f2;

			// f1--;
			// f2--;

			edges.emplace_back(f1, f2);

		}

		if (n <= 2) {
			cout << "Case #" << j << ": " << 1 << endl;
			continue;
		}

		int cnt {0};

		while (!edges.empty()) {

			vector<int> in(n, 0);
			vector<vector<int>> paths (n, vector<int>());
			int mx {0};

			for (auto [a, b] : edges) {
				paths[a].push_back(b);
				paths[b].push_back(a);
				in[a]++;
				in[b]++;
				if (a > mx) {
					mx = a;
				}
				if (b > mx) {
					mx = b;
				}
			}

			if (edges.size() == 1) {
				cnt++;
				break;
			}

			vector<int> rem;

			for (int u {0}; u <= mx; ++u) {
				if (in[u] == 1) {
					cnt++;
					rem.push_back(u);
				}
			}

			vector<int> addToRem;
			for (auto u : rem) {
				for (int v : paths[u]) {
					if (find(rem.begin(), rem.end(), v) != rem.end()) { continue; }
					addToRem.push_back(v);
				}
			}

			for (auto u : addToRem) {
				rem.push_back(u);
			}

			vector<int> toErase;
			vector<int> partNotIn;

			for (int u {0}; u < edges.size(); ++u) {
				pair<int, int> p {edges[u]};
				cout << p.first << " " << p.second << " " << u << endl;
				int addToCnt {2};

				if (find(rem.begin(), rem.end(), p.first) != rem.end()) {
					addToCnt--;
				} else {
					partNotIn.push_back(p.first);
				}

				if  (find(rem.begin(), rem.end(), p.second) != rem.end()) {
					addToCnt--;
				} else {
					partNotIn.push_back(p.second);
				}

				if (addToCnt != 2) { toErase.push_back(u); }
			}

			set<int> s(partNotIn.begin(), partNotIn.end());
			cnt += (partNotIn.size() - (partNotIn.size() - s.size()) * 2);

			sort(toErase.begin(), toErase.end());

			int cntErase {0};
			for (auto u : toErase) {
				edges.erase(next(edges.begin(), u - cntErase));
				cntErase++;
			}
		}

		cout << "Case #" << j << ": " << cnt << endl;

	}

	return 0;
}