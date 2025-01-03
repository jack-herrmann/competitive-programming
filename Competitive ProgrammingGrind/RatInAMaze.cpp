#include <bits/stdc++.h>

using namespace std;

bool ratInAMaze(vector<vector<int>>& board, int i, int j, int n, vector<vector<int>>& sol) {

	if (i == n - 1 && j == n - 1) { return 1; }
	if (i < 0 || j < 0 || i >= n || j >= n) { return 0; }
	if (board[i][j] == 0) { return 0; }
	if (sol[i][j] == 1) { return 0; }

	sol[i][j] = 1;
	if (ratInAMaze(board, i + 1, j, n, sol)) { return 1; }
	if (ratInAMaze(board, i - 1, j, n, sol)) { return 1; }
	if (ratInAMaze(board, i, j + 1, n, sol)) { return 1; }
	if (ratInAMaze(board, i, j - 1, n, sol)) { return 1; }
	sol[i][j] = 0;

	return 0;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l {4};
	vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {0, 1, 0, 0}, {1, 1, 1, 1}};
	vector<vector<int>> sol(l, vector<int>(l, 0));

	if (ratInAMaze(maze, 0, 0, l, sol)) { cout << "True" << "\n"; }
	else { cout << "False" << "\n"; }

	return 0;
}