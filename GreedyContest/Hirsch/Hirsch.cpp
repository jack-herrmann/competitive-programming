#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int a;
	int b;

	cin >> a >> b;

	if (a + b == 0) {
		cout << "Not a moose" << "\n";
	} else if (a == b) {
		cout << "Even " << a + b << "\n";
	} else {
		cout << "Odd " << 2 * max(a, b) << "\n";
	}

	// int s {a + b};

	// if (s == 0) {
	// 	cout << "Not a moose" << "\n";
	// } else if (s % 2 == 0) {
	// 	cout << "Even " << s << "\n";
	// } else {
	// 	cout << "Odd " << s + 1 << "\n";
	// }

	return 0;
}