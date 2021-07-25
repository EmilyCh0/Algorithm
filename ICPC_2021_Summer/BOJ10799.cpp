#include <iostream>
#include <stack>
#include <string>
using namespace std;
int BOJ10799() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	int stack = 0;
	bool open = false;
	int sum = 0;
	char ch;
	for (int i = 0;i < str.length();i++) {
		ch = str.at(i);
		if (ch == '(') {
			open = true;
			stack++;
		}
		else {
			if (open) {
				stack--;
				sum += stack;
			}
			else {
				sum++;
				stack--;
			}
			open = false;
		}
	}
	cout << sum;
	return 0;
}