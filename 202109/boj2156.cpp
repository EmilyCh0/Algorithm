#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> vec(n), dp(n);
	
	for (int i = 0;i <n;i++) {
		cin >> vec[i];
	}
	vec.insert(vec.begin(), 0);
	dp.insert(dp.begin(), 0);
	dp[1] = vec[1];
	dp[2] = vec[1] + vec[2];
	for (int i = 3;i <= n;i++) {
		dp[i] = max(dp[i - 2] + vec[i], max(dp[i - 3] + vec[i - 1] + vec[i],dp[i-1]));
	}

	sort(dp.begin(), dp.end());
	cout << dp[n];
	return 0;
}