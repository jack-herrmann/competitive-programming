#include <bits/stdc++.h>

using namespace std;

bool eligible (int u, vector<vector<int>>& paths, vector<int>& rem) {
	if (find(rem.begin(), rem.end(), u) != rem.end()) {
		return 0;
	}
	for (int v : paths[u]) {
		if (find(rem.begin(), rem.end(), v) != rem.end()) {
			return 0;
		}
	}
	return 1;
}

bool shouldBeColored (int u, vector<vector<int>>& paths, vector<int>& rem) {
	if (!eligible(u, paths, rem)) { return 0; }
	int vCount {0};
	int wCount {1};
	for (int v : paths[u]) {
		if (!eligible(v, paths, rem)) { continue; }
		vCount++;
		for (int w : paths[v]) {
			if (!eligible(w, paths, rem)) { continue; }
			wCount++;
		}
		wCount--;
	}
	return (vCount <= wCount);
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

	for (int j {1}; j <= t; ++j) {

		int n;

		cin >> n;

		vector<vector<int>> paths (n, vector<int>());
		vector<int> in(n, 0);


		for (int i {0}; i < n - 1; ++i) {
			int f1;
			int f2;

			cin >> f1 >> f2;

			// f1--;
			// f2--;

			// cout << f1 << " - " << f2 << " ";

			paths[f1].push_back(f2);
			paths[f2].push_back(f1);
			in[f1]++;
			in[f2]++;

			if ((f1 == 0) || (f2 == 0)) {
				cout << "hä" << endl;
			}

		}

		// cout << endl;

		if (n <= 2) {
			cout << "Case #" << j << ": " << 1 << endl;
			continue;
		}

		int cnt {0};

		vector<int> rem;

		queue<int> q;
		for (int u {0}; u < n; ++u) {
			if (in[u] <= 1) {
				q.push(u);
				cnt++;
				rem.push_back(u);
			}
		}

		vector<bool> vis (n, false);
		vis[q.front()] = 1;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int v : paths[u]) {
				if (vis[v]) { continue; }
				vis[v] = 1;
				q.push(v);
			}
			if (shouldBeColored(u, paths, rem)) {
				cnt++;
				rem.push_back(u);
			}
		}

		for (auto i : rem) {
			cout << i << " "; // ++
		}

		cout << "Case #" << j << ": " << cnt << endl;

	}

	return 0;
}