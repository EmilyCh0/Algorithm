#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(char ch1, char ch2) {
	return ch1 > ch2;
}
int BOJ10610() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	int sum = 0;
	bool flag = false;
	vector<char> vec;
	for (int i = 0;i < str.length();i++) {
		sum += (str[i] - '0');
		vec.push_back(str[i]);
		if (str[i] == '0'&&!flag) {
			flag = true;
		}
	}
	if (sum % 3 == 0 && flag) {
		sort(vec.begin(), vec.end(), comp);
		for (int j = 0;j < vec.size();j++) {
			cout << vec[j];
		}
	}
	else {
		cout << -1;
	}

	return 0;
}