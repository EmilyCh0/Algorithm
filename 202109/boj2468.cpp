#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visit;

int ans=0, n;
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };

void dfs(int i, int j) {
	visit[i][j] = 1;
	for (int k = 0;k < 4;k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		if (ni >= 0 && nj >= 0 && ni < n&&nj < n) {
			if (visit[ni][nj] == 0) {
				dfs(ni, nj);
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	map.resize(n, vector<int>(n));
	int maxH = -1;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> map[i][j];
			maxH = max(maxH, map[i][j]);
		}
	}
	int h = 0;
	while (true) {
		if (h == maxH) {
			break;
		}
		visit.assign(n, vector<bool>(n, false));
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (map[i][j] <= h) {
					map[i][j] = -1;
					visit[i][j] = 1;
				}
			}
		}
		int cnt = 0;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (visit[i][j] == 0) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		if (ans < cnt) {
			ans = cnt;
		}
		h++;
	}
	cout << ans;

	return 0;
}
/*
3
3 2 1
3 1 3
1 3 2
*/