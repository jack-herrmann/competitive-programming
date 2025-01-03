#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; int k;
	cin >> n >> k;
	vector<int> rooms(k, 0);
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	for (int i {0}; i < n; ++i) {

		int a; int b;
		cin >> a >> b;
		pq.push({a, b});
	}

	while (!pq.empty()) {

		auto ele = pq.top();
		pq.pop();
		bool set {0};

		for (int i {0}; i < k; ++i) {
			if (rooms[i] <= ele.first) {
				rooms[i] = ele.second;
				set = 1;
				break;
			}
		}
		if (!set) {
			cout << "impossible" << endl;
			goto end;
		}
	}

	cout << "possible" << endl;

end:
	return 0;
}