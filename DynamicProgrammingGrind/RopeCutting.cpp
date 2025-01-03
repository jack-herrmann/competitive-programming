#include <bits/stdc++.h>

using namespace std;

int max(int a, int b, int c) { return max(a, max(b, c));}

// O(n) using trick
int maxProd(int n)
{
	if (n == 2 || n == 3) return (n - 1);

	int res = 1;
	while (n > 4)
	{
		n -= 3;
		res *= 3;
	}
	return (n * res);
}

int maxProduct(int len, vector<int>& mem) {

	if (len <= 1) { return 0; }

	if (mem[len] != -1) { return mem[len]; }

	int mx {0};

	for (int i {1}; i < len; ++i) {

		mx = max(mx, i * (len - i), i * maxProduct(len - i, mem));
	}

	mem[len] = mx;
	return mem[len];
}

int maxProductBU(int len) {

	vector<int> mem(len + 1, 0);
	mem[0] = 0;
	mem[1] = 0;

	for (int j {2}; j <= len; ++j) {

		for (int i {1}; i < j; ++i) {

			mem[j] = max(mem[j], i * (j - i), i * mem[j - i]);
		}
	}
	return mem[len];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int len {7};

	vector<int> mem(len + 1, -1);

	cout << maxProduct(len, mem) << endl;
	cout << maxProductBU(len) << endl;

	return 0;
}