#include <bits/stdc++.h>

// SEE IPAD FOR IDEA

#define intMax numeric_limits<int>::max()

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

	for (int i {1}; i <= tests; ++i) {
		int h; int n;
		cin >> h >> n;

		vector<vector<int>> boxes;

		for (int j {0}; j < n; ++j) {

			int x; int y; int z;
			cin >> x >> y >> z;
			boxes.push_back({x, y, z});
		}

		vector<pair<int, int>> top(h + 1, pair<int, int>());
		vector<vector<int>> left(h + 1, vector<int>());
		top[0] = {intMax, intMax};
		left[0] = vector<int>(n, 5);

		for (int j {0}; j < h; ++j) {

			for (int k {0}; k < left[j].size(); ++k) {

				if (left[k] == 0) { continue; }
				vector<int> box = boxes[k];

			}
		}

	}

	return 0;
}