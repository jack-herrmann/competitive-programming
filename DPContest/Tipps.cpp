#include <bits/stdc++.h>

// SEE IPAD FOR IDEA - see if memoization ist good

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int c; int m;
	cin >> c >> m;

	vector<vector<int>> hs;

	for (int i {0}; i < m; ++i) {

		vector<int> happiness;
		for (int j {0}; j < c; ++j) {

			int p;
			cin >> p;

			happiness.push_back(p)
		}
		hs.push_back(happiness);
	}

	map<vector<int>, int> mem;


	return 0;
}