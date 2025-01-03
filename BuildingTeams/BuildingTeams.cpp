#include <bits/stdc++.h>

using namespace std;

bool bfs(int s, vector<vector<int>> friendships, vector<int>& teams) {
	teams[s] = 1;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : friendships[u]) {
			if (teams[v] == -1) {
				teams[v] = abs(teams[u] - 1);
				q.push(v);
			} else if (teams[v] == teams[u]) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	int m;

	cin >> n >> m;

	vector<vector<int>> friendships (n + 1, vector<int>());
	vector<int> teams (n + 1, -1);

	for (int i {0}; i < m; ++i) {
		int f1;
		int f2;

		cin >> f1 >> f2;

		friendships[f1].push_back(f2);
		friendships[f2].push_back(f1);
	}

	int idx {0};

	while (count(teams.begin(), teams.end(), -1) != 0) {
		if (!bfs(idx, friendships, teams)) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		for (int i {1}; i <= n; ++i) {
			if (teams[i] == -1) {
				idx = i;
				break;
			}
		}
	}

	for (int i {1}; i <= n; ++i) {
		cout << teams[i] << " ";
	}

	return 0;
}