#include <bits/stdc++.h>

using namespace std;

int subsetSum(int val, int n, vector<int>& nums, vector<int>& mem) {

	if (val == 0) { return 1; }
	if (val <= 0) { return 0; }
	if (n <= 0) { return 0; }

	if (mem[val] != -1) { return mem[val]; }
	bool set {0};

	if (subsetSum(val - nums[n - 1], n - 1, nums, mem)) { set = 1; }
	if (subsetSum(val, n - 1, nums, mem)) { set = 1; }

	mem[val] = set;
	return mem[val];
}

int subsetSumBU(int val, vector<int>& nums) {

	vector<vector<bool>> mem(nums.size() + 1, vector<bool>(val + 1, 0));
	for (int i {0}; i <= nums.size(); ++i) {
		mem[i][0] = 1;
	}

	for (int j {1}; j <= nums.size(); ++j) {
		for (int i {1}; i <= val; ++i) {
			if (i < nums[j - 1]) { mem[j][i] = mem[j - 1][i]; continue; }
			mem[j][i] = mem[j - 1][i] || mem[j - 1][i - nums[j - 1]];
		}
	}

	return mem[nums.size()][val];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> nums {{2, 5, 4, 7, 32, 12, 20}};
	int val {44};

	vector<int> mem(val + 1, -1);

	cout << subsetSum(val, nums.size(), nums, mem) << endl;
	cout << subsetSumBU(val, nums) << endl;

	return 0;
}