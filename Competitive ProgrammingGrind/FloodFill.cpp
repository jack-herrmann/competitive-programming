// solution to practice recursion
// better version iteratively with stack

#include <bits/stdc++.h>

using namespace std;

void floodFill(vector<vector<int>>& pic, int newColor, int x, int y, int startColor) {

	if (x < 0 || x >= pic.size() || y < 0 || y >= pic.size()) { return; }

	if (pic[x][y] == startColor) {
		pic[x][y] = newColor;
		floodFill(pic, newColor, x + 1, y, startColor);
		floodFill(pic, newColor, x - 1, y, startColor);
		floodFill(pic, newColor, x, y + 1, startColor);
		floodFill(pic, newColor, x, y - 1, startColor);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<int>> pic {{1, 1, 0}, {1, 1, 0}, {1, 0, 1}};
	int newColor {2};
	int x {1}; int y {1};

	floodFill(pic, newColor, x, y, pic[x][y]);

	for (auto a : pic) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << "\n";
	}

	return 0;
}