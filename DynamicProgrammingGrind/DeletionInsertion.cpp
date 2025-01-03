#include <bits/stdc++.h>

using namespace std;

int longestCommonSubsequenceBU(string str1, string str2) {

	vector<vector<int>> mem(str1.size() + 1, vector<int>(str2.size() + 1, 0));

	for (int i = str1.size() - 1; i >= 0; --i) {
		for (int j = str2.size() - 1; j >= 0; --j) {

			if (str1[i] == str2[j]) { mem[i][j] = 1 + mem[i + 1][j + 1]; continue; }
			mem[i][j] = max(mem[i + 1][j], mem[i][j + 1]);
		}
	}
	return mem[0][0];
}

void minDelIn(string str1, string str2) {

	int res = longestCommonSubsequenceBU(str1, str2);
	cout << "Deletions: " << str1.size() - res << endl;
	cout << "Insertions: " << str2.size() - res << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string str1 = "dghjzgbnhd";
	string str2 = "fvbhtzfdhjh";

	minDelIn(str1, str2);

	return 0;
}