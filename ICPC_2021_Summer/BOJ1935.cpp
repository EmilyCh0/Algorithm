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
	cout.setf(ios::showpoint);	// �Ҽ��� 0���� ���
	cout << fixed;	// �Ҽ��� �ڸ� ����
	cout.precision(2);	// fixed�� �Բ� ���� �Ҽ����ڸ� ����, fixed ���� ���� �����κ� ������ ��ü �ڸ���
	cout << stack.top();

	return 0;
}