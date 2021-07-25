// 고쳐야함
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;
int BOJ9012() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	for (int i = 0;i < N;i++) {
		stack<int> stack;
		string str;
		cin >> str;

		bool done = false;
		for (int j = 0;j < str.length();j++) {
			if (str.at(j) == '(') {
				stack.push(0);
			}
			else {
				if (stack.empty()) {
					break;
				}
				else {
					stack.pop();
				}
			}
			if (j == str.length() - 1)
				done == true;
		}
		if (done) {
			if (stack.empty()) {
				cout << "YES";
			}
			else {
				cout << "NO";
			}
		}
		else {
			cout << "NO";
		}

	}
	return 0;
}