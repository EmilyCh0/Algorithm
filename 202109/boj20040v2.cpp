#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> vec;

int find(int i) {
	if (vec[i] == i) {
		return i;
	}
	else {
		return vec[i] = find(vec[i]);
	}
}
bool isUnion(int a, int b) {
	int tmpa, tmpb;
	tmpa = find(a);
	tmpb = find(b);
	if (tmpa == tmpb) {
		return true;
	}
	else {
		vec[tmpa] = tmpb;
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vec.resize(n);
	for (int i = 0;i < n;i++) {
		vec[i] = i;
	}
	int ans=0;
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		if (isUnion(a, b)) {
			ans = i + 1;
			break;
		}
	}
	if (ans == 0) {
		cout << 0;
	}
	else {
		cout << ans;
	}
	return 0;
}

