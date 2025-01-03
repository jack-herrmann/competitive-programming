#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> smaller;
map<string, int> seen;
bool c {0};

void dfs(string s) {
	seen[s] = 1;
	for (string v : smaller[s]) {
		if (seen[v] == 0) {
			dfs(v);
		}
		if (seen[v] == 1) {
			c = 1;
		}
	}
	seen[s] = 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int statements;
	cin >> statements;

	for (int i {0}; i < statements; ++i) {
		string name1;
		string name2;
		char op;

		cin >> name1 >> op >> name2;

		if (op == '<') {
			swap(name1, name2);
		}

		smaller[name1].push_back(name2);
	}

	for (auto& i : smaller) {

		if (seen[i.first] == 0) {
			dfs(i.first);
		}
		if (c) {
			cout << "impossible";
			return 0;
		}
	}

	cout << "possible";
	return 0;
}