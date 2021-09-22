#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0;i < n;i++) {
		cin >> vec[i];
	}
	vector<int> dp(n);
	dp[0] = vec[0];
	for (int i = 1;i < n;i++) {
		dp[i] = max(dp[i - 1] + vec[i], vec[i]);
	}
	sort(dp.begin(), dp.end());
	cout << dp[n - 1];
	return 0;
}