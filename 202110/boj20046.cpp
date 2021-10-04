#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
queue<pair<int, int>> que;
vector<vector<int>> map;
vector<vector<bool>> visit;
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };
struct Road
{
	int i;
	int j;
	int cost;

};
struct comp {
	bool operator()(Road a, Road b) {
		return a.cost > b.cost;
	}
};
priority_queue<Road, vector<Road>, comp> pq;
int bfs() {
	while (!pq.empty()) {
		Road r = pq.top();
		int i = r.i;
		int j = r.j;
		int c = r.cost;
		if (i == n - 1 && j == m - 1) {
			return c;
		}
		pq.pop();
		visit[i][j] = true;
		for (int k = 0;k < 4;k++) {
			int nexti = i + di[k];
			int nextj = j + dj[k];
			if (nexti >= 0 && nextj >= 0 && nexti < n&&nextj < m) {
				if (map[nexti][nextj] != -1 && !visit[nexti][nextj]) {
					pq.push({ nexti,nextj,c + map[nexti][nextj] });
				}
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	map.resize(n, vector<int>(m, 0));
	visit.resize(n, vector<bool>(m, false));
	
	
	//que.push(make_pair(0, 0));
	
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> map[i][j];
		}
	}


	if (map[0][0] == -1) {
		cout << -1;
	}
	else {
		pq.push({ 0,0,map[0][0] });
		cout << bfs();
	}
	

	return 0;
}

