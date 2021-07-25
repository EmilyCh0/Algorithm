#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;
int BOJ1935() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, tmp;
	cin >> N;
	string str;
	cin >> str;
	vector<int> vec;
	for (int i = 0;i < N;i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}
	stack<double> stack;
	char ch;
	double a, b;
	for (int i = 0;i < str.length();i++) {
		ch = str.at(i);
		if (!(ch == '*' || ch == '+' || ch == '/' || ch == '-')) {
			stack.push((double)vec[ch - 'A']);
		}
		else if (ch == '*') {
			b = stack.top();
			stack.pop();
			a = stack.top();
			stack.pop();
			stack.push(a*b);
		}
		else if (ch == '+') {
			b = stack.top();
			stack.pop();
			a = stack.top();
			stack.pop();
			stack.push(a+b);
		}
		else if (ch == '/') {
			b = stack.top();
			stack.pop();
			a = stack.top();
			stack.pop();
			stack.push(a/b);
		}
		else if (ch == '-') {
			b = stack.top();
			stack.pop();
			a = stack.top();
			stack.pop();
			stack.push(a-b);
		}
	}
	cout.setf(ios::showpoint);	// 소수점 0까지 출력
	cout << fixed;	// 소수점 자리 고정
	cout.precision(2);	// fixed와 함께 쓰면 소수점자리 개수, fixed 없이 쓰면 정수부분 포함한 전체 자리수
	cout << stack.top();

	return 0;
}