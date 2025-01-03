#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int n;
	cin >> n;

	double res { floor(n / 3) * 84 };

	if (n % 3 == 1) { res += 42; }
	if (n % 3 == 2) { res += 63; }

	cout << (int) res << " Euro 0 Cent" << "\n";

	return 0;
}