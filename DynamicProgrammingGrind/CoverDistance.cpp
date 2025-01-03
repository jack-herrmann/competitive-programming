#include <bits/stdc++.h>

using namespace std;

int differentWays(int val, vector<int>& mem) {

	if (val == 0) { return 1; }
	if (val < 0) { return 0; }

	if (mem[val] != -1) { return mem[val]; }

	int mx {0};

	mx += differentWays(val - 1, mem);
	mx += differentWays(val - 2, mem);
	mx += differentWays(val - 3, mem);

	mem[val] = mx;
	return mem[val];
}

int differentWaysBU(int val) {

	vector<int> mem(val + 1, 0);
	mem[0] = 1;

	for (int j {1}; j <= val; ++j) {

		mem[j] = mem[j - 1] + mem[j - 2] + mem[j - 3];
	}

	return mem[val];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int val {4};

	vector<int> mem(val + 1, -1);

	cout << differentWays(val, mem) << endl;
	cout << differentWaysBU(val) << endl;

	return 0;
}