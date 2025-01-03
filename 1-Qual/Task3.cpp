#include <bits/stdc++.h>

using namespace std;

void expand(vector<vector<bool>>& mp, int x, int y) {

	queue<pair<int, int>> toGrow;
	toGrow.push({x, y});

	while (!toGrow.empty()) {

		pair<int, int> top = toGrow.front();
		toGrow.pop();

		cout << "1 " << top.first << " " << top.second << flush;
		int a;
		cin >> a;

		if (a == 0) {
			mp[top.first][top.second] = 0;
			continue;
		}

		if (x != 0) { toGrow.push({x - 1, y}); }
		if (y != 0) { toGrow.push({x, y - 1}); }
		if (x != mp.size() - 1) { toGrow.push({x + 1, y}); }
		if (y != mp.size() - 1) { toGrow.push({x, y + 1}); }
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int n; int m;
	cin >> m >> n;

	int x; int y;
	cin >> x >> y;

	vector<vector<bool>> mp(n, vector<bool>(m, 1));

	for (int i {1}; i <= n; ++i) {
		cout << "1 " << i << " " << 1 << flush;
		int a;
		cin >> a;
		if (a == 0) {
			mp[i][0] = 0;
			expand(mp, i, 0);
		}
	}

	for (int i {1}; i <= n; ++i) {
		cout << "1 " << 1 << " " << i << flush;
		int a;
		cin >> a;
		if (a == 0) { mp[i][0] = 0; expand(mp, i, 0); }
	}

	for (int i {1}; i <= m; ++i) {
		cout << "1 " << i << " " << 1 << flush;
		int a;
		cin >> a;
		if (a == 0) { mp[i][0] = 0; expand(mp, i, 0); }
	}

	for (int i {1}; i <= m; ++i) {
		cout << "1 " << 1 << " " << i << flush;
		int a;
		cin >> a;
		if (a == 0) { mp[i][0] = 0; expand(mp, i, 0); }
	}

	cout << "2" << endl;
	for (auto x : mp) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	cout << flush;

	return 0;
}