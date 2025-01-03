#include <bits/stdc++.h>

using namespace std;

void generateIP(vector<string>& sol, string s, int blocks, int p, string address) {

	if (blocks == 4 && p == s.size()) { address.pop_back(); sol.push_back(address); return; }

	if (s.size() < p + 1) { return; }
	address = address + s.substr(p, 1) + '.';
	generateIP(sol, s, blocks + 1, p + 1, address);
	address.erase(address.end() - 2, address.end());

	if (s.size() < p + 2 || s[p] == '0') { return; }
	address = address + s.substr(p, 2) + '.';
	generateIP(sol, s, blocks + 1, p + 2, address);
	address.erase(address.end() - 3, address.end());

	if (s.size() < p + 3 || stoi(s.substr(p, 3)) > 255) { return; }
	address = address + s.substr(p, 3) + '.';
	generateIP(sol, s, blocks + 1, p + 3, address);
	address.erase(address.end() - 4, address.end());
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s {"2583933"};
	vector<string> sol;

	generateIP(sol, s, 0, 0, "");

	for (string x : sol) { cout << x << "\n"; }

	return 0;
}