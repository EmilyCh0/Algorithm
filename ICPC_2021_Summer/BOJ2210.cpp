#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> box;
vector<vector<char>> vec;
string s;

void sol2(int i, int j, string str) {
	if (str.length() == 6) {
		box.push_back(str);
		return;
	}
	if (i > 0) {
		s = str+vec[i - 1][j];
		sol2(i - 1, j, s);
	}
	if (j > 0) {
		s = str + vec[i][j-1];
		sol2(i , j-1, s);
	}
	if (i < 4) {
		s = str+ vec[i + 1][j];
		sol2(i + 1, j, s);
	}
	if (j < 4) {
		s = str + vec[i][j + 1];
		sol2(i, j + 1, s);
	}
}

int BOJ2210() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vec.resize(5, vector<char>(5));
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			cin >> vec[i][j];
		}
	}
	string tmp;
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			tmp = vec[i][j];
			sol2(i, j, tmp);
		}
	}
	// vector 중복 제거
	sort(box.begin(), box.end());
	box.erase(unique(box.begin(), box.end()), box.end());
	cout << box.size();

	return 0;
}