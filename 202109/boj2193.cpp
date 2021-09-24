#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<long long> vec(n);
	vec[0] = vec[1] = 1;
	for (int i = 2;i < n;i++) {
		vec[i] = vec[i - 1] + vec[i - 2];
	}
	cout << vec[n - 1];
	return 0;
}