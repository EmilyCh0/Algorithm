#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> vec(n+1);
	vector<int> dp(n+1);
	vec[0] = dp[0] = 0;
	for (int i = 1;i <= n;i++) {
		cin >> vec[i];
	}
	for (int i = 1;i <= n;i++) {
		int maxidx = 0, maxcnt = -1;
		for (int j = i - 1;j >= 0;j--) {
			if (vec[j] < vec[i]&& maxcnt<dp[j]) {
				maxcnt = dp[j];
				maxidx = j;
			}
		}
		dp[i] = maxcnt + 1;
	}
	sort(dp.begin(), dp.end());
	cout << dp[n];
	return 0;
}