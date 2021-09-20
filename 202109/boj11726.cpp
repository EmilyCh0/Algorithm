#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	for (int i = 2;i < n;i++) {
		int tmp = vec[i - 1] + vec[i - 2];
		tmp %= 10007;
		vec.push_back(tmp);
	}
	cout << vec[n-1];

	return 0;
}