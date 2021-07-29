#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<vector<int>> vec(N, vector<int>(N));
	vector<vector<int>> dp(N, vector<int>(N,0));

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < i + 1;j++) {
			cin >> vec[i][j];
			if (j == 0 && i == 0) {
				dp[i][j] = vec[i][j];
			}
			else if (j == 0) {
				dp[i][j] = vec[i][j] + dp[i - 1][j];
			}
			else if (j == i) {
				dp[i][j] = vec[i][j] + dp[i - 1][j-1];
			}
			else {
				dp[i][j] = max(vec[i][j] + dp[i - 1][j-1], vec[i][j] + dp[i - 1][j]);
			}
		}
	}
	int max = 0;
	for (int i = 0;i < N;i++) {
		if (dp[N - 1][i] > max) {
			max = dp[N - 1][i];
		}
	}
	cout << max;

	return 0;

}