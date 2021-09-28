#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int N, M;

vector<vector<char>> v;
vector<vector<int>> maze2;
vector<vector<bool>> visit;
int di2[] = { 1,-1,0,0 };
int dj2[] = { 0,0,1,-1 };

void bfs2(int i, int j) {
	visit[i][j] = 1;
	queue<pair<int, int>> que;
	que.push(make_pair(i, j));
	while (!que.empty()) {
		int ii = que.front().first;
		int jj = que.front().second;
		que.pop();
		for (int k = 0;k < 4;k++) {
			int nexti = ii + di2[k];
			int nextj = jj + dj2[k];
			if (nexti >= 0 && nextj >= 0 && nexti < N&&nextj < M) {
				if (v[nexti][nextj] == '1'&& visit[nexti][nextj] == 0) {
					maze2[nexti][nextj] = maze2[ii][jj] + 1;
					visit[nexti][nextj] = 1;
					que.push(make_pair(nexti, nextj));
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	v.resize(N, vector<char>(M));
	maze2.resize(N, vector<int>(M));
	visit.resize(N, vector<bool>(M,0));
	for (int i = 0;i < N;i++) {
		string str;
		cin >> str;
		for (int j = 0;j < M;j++) {
			v[i][j] = str[j];
		}
	}

	bfs2(0, 0);
	cout << maze2[N - 1][M - 1] + 1;
	return 0;
}