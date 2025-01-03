#include <bits/stdc++.h>

using namespace std;

int minSumSub(int idx, vector<int>& nums, vector<int>& mem) {

	if (idx <= 3) { return nums[idx]; }

	if (mem[idx] != -1) { return mem[idx]; }

	mem[idx] = nums[idx] + min(min(minSumSub(idx - 1, nums, mem), minSumSub(idx - 2, nums, mem)), min(minSumSub(idx - 3, nums, mem), minSumSub(idx - 4, nums, mem)));
	return mem[idx];
}

int minSumSubBU(int idx, vector<int>& nums) {

	vector<int> mem(nums.size() + 1, -1);

	if (idx == 0) { return nums[0]; }
	if (idx == 1) { return min(nums[0], nums[1]); }
	if (idx == 2) { return min(nums[0], min(nums[1], nums[2])); }
	if (idx == 3) { return min(min(nums[0], nums[1]), min(nums[2], nums[3])); }

	mem[0] = nums[0];
	mem[1] = nums[1];
	mem[2] = nums[2];
	mem[3] = nums[3];

	for (int i {4}; i < nums.size(); ++i) {

		mem[i] = nums[i] + min(min(mem[i - 1], mem[i - 2]), min(mem[i - 3], mem[i - 4]));
	}

	return min(min(mem[idx - 1], mem[idx - 2]), min(mem[idx - 3], mem[idx - 4]));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> nums {{2, 7, 4, 7, 1}};

	vector<int> mem(nums.size() + 1, -1);

	cout << minSumSub(nums.size(), nums, mem) << endl;
	cout << minSumSubBU(nums.size(), nums) << endl;

	return 0;
}