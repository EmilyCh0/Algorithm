#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int n;
vector<vector<char>> map;
queue<pair<int,int>> que;
vector<vector<bool>> visit;
int di[] = { 1,-1,0,0 };
int dj[] = { 0,0,1,-1 };

int func(int i, int j) {
	queue<pair<int, int>> tmpQue;
	tmpQue.push(make_pair(i, j));
	visit[i][j] = 1;
	int cnt = 1;
	while (!tmpQue.empty()) {
		int tmpi = tmpQue.front().first;
		int tmpj = tmpQue.front().second;
		tmpQue.pop();
		for (int k = 0;k < 4;k++) {
			int nexti = tmpi + di[k];
			int nextj = tmpj + dj[k];
			if (nexti >= 0 && nextj >= 0 && nexti < n&&nextj < n) {
				if (visit[nexti][nextj] == 0&&map[nexti][nextj]=='1') {
					tmpQue.push(make_pair(nexti, nextj));
					visit[nexti][nextj] = 1;
					cnt++;
				}
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	map.resize(n, vector<char>(n));
	visit.resize(n, vector<bool>(n,0));
	for (int i = 0;i < n;i++) {
		string str;
		cin >> str;
		for (int j = 0;j < n;j++) {
			map[i][j] = str[j];
			if (str[j] == '1') {
				que.push(make_pair(i, j));
			}
		}
	}
	vector<int> ans;
	int cnt = 0;
	while (!que.empty()) {
		if (visit[que.front().first][que.front().second] == 1) {
			que.pop();
			continue;
		}
		else {
			ans.push_back(func(que.front().first, que.front().second));
			cnt++;
		}
	}
	cout << cnt << '\n';
	sort(ans.begin(), ans.end());
	for (int i = 0;i < cnt;i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}