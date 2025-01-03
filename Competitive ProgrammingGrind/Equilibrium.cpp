#include <bits/stdc++.h>

using namespace std;

int equilibrium(vector<int>& nums, int n) {

	int s1 {0}; int s2 {0};
	for (int x : nums) { s2 += x; }
	for (int i {1}; i <= n; ++i) {
		s2 -= nums[i - 1];
		if (s1 == s2) {
			return i;
		}
		s1 += nums[i - 1];
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> nums {{1, 2, 5, 3}};

	cout << equilibrium(nums, nums.size()) << "\n";

	return 0;
}