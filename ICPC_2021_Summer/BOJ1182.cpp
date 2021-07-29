#include <iostream>
#include <vector>

using namespace std;
int Num, S, cnt=0;
vector<int> vec;

void solve(int sum, int idx);

int BOJ1182() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> Num >> S;
	int tmp;
	for (int i = 0;i < Num;i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}
	solve(0, 0);
	if (S == 0)
		cnt--;
	cout << cnt;
	return 0;
}

void solve(int sum, int idx) {
	if (idx == Num&&sum == S) {
		cnt++;
	}
	if (idx == Num)
		return;
	solve(sum + vec[idx], idx + 1);	// 다음 수 포함
	solve(sum, idx + 1);	// 다음 수 포함 X
}