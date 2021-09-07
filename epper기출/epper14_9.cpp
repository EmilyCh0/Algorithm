#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solution2(int N, vector<vector<long long>> money) {

	vector<vector<long long>> dp(N, vector<long long>(N, 0));
	dp[0][0] = money[0][0];
	for (int i = 1;i<N;i++) {
		dp[i][0] = money[i][0] + dp[i - 1][0];
		dp[i][i] = money[i][i] + dp[i - 1][i - 1];
	}
	for (int i = 2;i<N;i++) {
		for (int j = 1;j<i;j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + money[i][j];
		}
	}
	long long ans = 0;
	for (int i = 0;i<N;i++) {
		ans = max(ans, dp[N - 1][i]);
	}
	return ans;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	vector<vector<long long>> money;
	for (int i = 0; i < N; i++) {
		money.push_back(vector<long long>(i + 1, 0));
		for (int j = 0; j <= i; j++) {
			cin >> money[i][j];
		}
	}
	cout << solution2(N, money) << "\n";
	return 0;
}