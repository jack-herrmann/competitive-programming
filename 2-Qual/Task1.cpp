// see Ipad

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	int maxVal {0};
	int val {0};

	vector<int> query;
	vector<int> bestQuery;

	for (int i {1}; i <= n; ++i) {
		query.push_back(i);
	}

	do {
		cout << "Q";
		for (int i {0}; i < n; ++i) {
			cout << " " << query[i];
		}
		cout << "\n" << flush;

		val = 0;

		for (int i {0}; i < n; ++i) {
			int r;
			cin >> r;
			val += r;
		}

		if (val > maxVal) { bestQuery = query; maxVal = val; }
	} while (next_permutation(query.begin(), query.begin() + n) && val != n);

	cout << "A";
	for (int i {0}; i < n; ++i) {
		cout << " " << bestQuery[i];
	}
	cout << "\n" << flush;



	// vector<int> lamps(n, 0);
	// vector<int> sockets(n, 0);
	// int r; bool s {0};

	// for (int i {0}; i < n; ++i) {
	// 	cin >> r;
	// 	if (r) {
	// 		s = {1};
	// 		lamps[i] = 2;
	// 		sockets[i] = 2;
	// 	}
	// }

	// if (!s) {
	// 	vector<int> query2;
	// 	cout << "Q";
	// 	cout << " " << query[-1];
	// 	query2[2] = query[-1];
	// 	for (int i {0}; i < n - 1; ++i) {
	// 		cout << " " << query[i];
	// 		query2[i + 1] = query[i];
	// 	}
	// 	cout << flush;
	// 	query = query2;

	// 	for (int i {0}; i < n; ++i) {
	// 		cin >> r;
	// 		if (r) {
	// 			s = {1};
	// 			lamps[] = 2;
	// 			sockets[i] = 2;
	// 		}
	// 	}
	// } else {

	// }

	return 0;
}