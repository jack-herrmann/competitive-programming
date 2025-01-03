#include <bits/stdc++.h>

using namespace std;

// detecting polygons... ceil(s/2)

struct comp {
	template <typename T>

	// Comparator function
	bool operator()(const T& l,
	                const T& r) const
	{
		if (l.second != r.second) {
			return l.second < r.second;
		}
		return l.first < r.first;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int numPeople;

	cin >> numPeople;

	if (numPeople % 2 != 0) {
		cout << -1 << "\n";
		return 0;
	}

	int arrowCnt {0};

	string name1;
	string name2;

	map<string, int> crushes;
	map<string, string> crushesP;

	for (int i {0}; i < numPeople; ++i) {

		cin >> name1 >> name2;

		crushesP[name1] = name2;

		if (name1 == name2) {
			++arrowCnt;
			continue;
		}

		++crushes[name2];
		crushes[name1] = (crushes[name1] != 0) ? crushes[name1] : 0;

	}

	set<pair<string, int>, comp> S(crushes.begin(), crushes.end());

	for (auto& it : S) {
		cout << it.first << " : " << it.second << endl;
		if (crushes[it.first] == 0) {
			++arrowCnt;
			--crushes[crushesP[crushesP[it.first]]];
		}
	}

	cout << arrowCnt;

	return 0;
}