#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int BOJ11048() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<vector<int>> maze, dp;
	maze.resize(N, vector<int>(M, 0));
	dp.resize(N, vector<int>(M, 0));
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> maze[i][j];
		}
	}
	dp[0][0] = maze[0][0];
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (i == 0 && j == 0)
				continue;
			if (j == 0) {
				dp[i][j] = maze[i][j] + dp[i - 1][j];
			}
			else if (i == 0) {
				dp[i][j] = maze[i][j] + dp[i][j - 1];
			}
			else {
				dp[i][j] = max(maze[i][j] + dp[i - 1][j], max(maze[i][j] + dp[i][j - 1], maze[i][j] + dp[i - 1][j - 1]));
			}
		}
	}
	cout << dp[N-1][M-1];
	return 0;
}