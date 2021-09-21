#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> vec(N+1);
	vector<int> dp(N+1);
	vec[0] = 0; dp[0] = 0;
	for (int i = 1;i <= N;i++) {
		cin >> vec[i];
	}
	dp[1] = vec[1];
	dp[2] = vec[1] + vec[2];
	for (int i = 3;i <= N;i++) {
		dp[i] = max(dp[i - 2] + vec[i], dp[i - 3] + vec[i] + vec[i - 1]);
	}
	cout << dp[N];

	return 0;
}