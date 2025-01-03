#include <bits/stdc++.h>

using namespace std;

bool search(pair<int, int> s, pair<int, int> e, vector<vector<char>> a, vector<vector<bool>> vis) {
	if (vis[s.first][s.second]) {
		return 0;
	}
	vis[s.first][s.second] = 1;
	if (a[s.first][s.second] == '#') {
		return 0;
	}
	if (s == e) {
		return 1;
	}
	if (search(pair(s.first - 1, s.second), e, a, vis) || search(pair(s.first + 1, s.second), e, a, vis) || search(pair(s.first, s.second - 1), e, a, vis) || search(pair(s.first, s.second + 1), e, a, vis)) {
		return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int x;
	int y;
	cin >> x >> y;

	pair<int, int> s;
	pair<int, int> e;

	vector<vector<char>> a(x, vector<char>(y));

	for (int i {0}; i < y; ++i) {
		for (int j {0}; j < x; ++j) {
			char c;
			cin >> c;
			if (c == 'S') {
				s.first = j;
				s.second = i;
			} else if (c == 'E') {
				e.first = j;
				e.second = i;
			}
			a[j][i] = c;
		}
	}

	vector<vector<bool>> vis(x, vector<bool>(y));

	if (search(s, e, a, vis)) {
		cout << "possible";
	} else {
		cout << "impossible";
	}

	return 0;
}