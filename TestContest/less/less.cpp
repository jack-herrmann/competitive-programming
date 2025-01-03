#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int top {10}; int bottom {0};
	int query = floor(top / 2);
	string otpt {"n"};

	while (true) {

		cout << "Q " << query << flush;
		cin >> otpt;
		if (otpt == "y") {
			if (query - bottom == 1) {
				cout << "A " << bottom << flush;
				break;
			}
			top = query;
			query = bottom + floor((top - bottom) / 2);
		} else {
			if (top - query == 1) {
				cout << "A " << query << flush;
				break;
			}
			bottom = query;
			query = bottom + floor((top - bottom) / 2);
		}
	}

	return 0;
}