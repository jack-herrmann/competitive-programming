#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

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

			f1--;
			f2--;

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
					if (find(rem.begin(), rem.end(), u) != rem.end()) { continue; }
					cnt++;
					rem.push_back(u);
					for (int v : paths[u]) {
						if (find(rem.begin(), rem.end(), v) != rem.end()) { continue; }
						rem.push_back(v);
					}
				}
			}

			vector<int> partNotIn;
			vector<int> areOtherwiseIn;

			for (int u = edges.size() - 1; u >= 0; --u) {
				pair<int, int> p {edges[u]};
				int addToCnt {2};
				vector<int> partNotInHere;

				if (find(rem.begin(), rem.end(), p.first) != rem.end()) {
					addToCnt--;
				} else {
					partNotInHere.push_back(p.first);
				}

				if  (find(rem.begin(), rem.end(), p.second) != rem.end()) {
					addToCnt--;
				} else {
					partNotInHere.push_back(p.second);
				}

				if (addToCnt == 2) {areOtherwiseIn.push_back(p.first); areOtherwiseIn.push_back(p.second); }
				if (partNotInHere.size() == 1) { partNotIn.push_back(partNotInHere[0]); }
				if (addToCnt != 2) { edges.erase(next(edges.begin(), u)); }
			}

			set<int> s(partNotIn.begin(), partNotIn.end());
			for (auto u : s) {
				if (find(areOtherwiseIn.begin(), areOtherwiseIn.end(), u) == areOtherwiseIn.end()) {
					cnt++;
				}
			}
		}

		cout << "Case #" << j << ": " << cnt << endl;

	}

	return 0;
}