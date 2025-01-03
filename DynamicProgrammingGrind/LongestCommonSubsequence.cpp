#include <bits/stdc++.h>

using namespace std;

int longestCommonSubsequence(string str1, string str2, int idx1, int idx2, vector<vector<int>>& mem) {

	if (str1.substr(idx1) == str2.substr(idx2)) { return str1.size() - idx1; }
	if (str1.size() - idx1 == 0 || str2.size() - idx2 == 0) { return 0; }

	if (mem[idx1][idx2] != -1) { return mem[idx1][idx2]; }

	if (str1[idx1] == str2[idx2]) { mem[idx1][idx2] = 1 + longestCommonSubsequence(str1, str2, idx1 + 1, idx2 + 1, mem); return mem[idx1][idx2]; }
	mem[idx1][idx2] = max(longestCommonSubsequence(str1, str2, idx1 + 1, idx2, mem), longestCommonSubsequence(str1, str2, idx1, idx2 + 1, mem));
	return mem[idx1][idx2];
}

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

void lcsWithLetters(char* X, char* Y, int m, int n)
{
	int L[m + 1][n + 1];

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	int index = L[m][n];

	char lcs[index + 1];
	lcs[index] = '\0';
	int i = m, j = n;
	while (i > 0 && j > 0) {
		if (X[i - 1] == Y[j - 1]) {
			lcs[index - 1]
			    = X[i - 1];
			i--;
			j--;
			index--;
		}

		else if (L[i - 1][j] > L[i][j - 1])
			i--;
		else
			j--;
	}

	cout << "LCS of " << X << " and " << Y << " is " << lcs << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	char X[] = "dghjzgbnhd";
	char Y[] = "vbhtzfdhjh";
	int m = strlen(X);
	int n = strlen(Y);
	lcsWithLetters(X, Y, m, n);

	string str1 = "dghjzgbnhd";
	string str2 = "fvbhtzfdhjh";

	vector<vector<int>> mem(str1.size(), vector<int>(str2.size(), -1));
	cout << longestCommonSubsequence(str1, str2, 0, 0, mem) << endl;
	cout << longestCommonSubsequenceBU(str1, str2) << endl;

	return 0;
}