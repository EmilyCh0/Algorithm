#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	set<int> s;
	int tmp;
	for (int i = 0;i < n;i++) {
		cin >> tmp;
		s.insert(tmp);
	}
	int f, m;
	cin >> m;
	for (int i = 0;i < m;i++) {
		cin >> f;
		auto iter = s.find(f);
		if (iter != s.end()) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
	return 0;
}