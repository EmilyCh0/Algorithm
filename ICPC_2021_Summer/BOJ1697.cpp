#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool visit[100001];

int sol(int a, int b) {
	queue<pair<int, int>> que;
	que.push(make_pair(a, 0));
	visit[a] = true;
	while (!que.empty()) {
		int pos = que.front().first;
		int cnt = que.front().second;
		que.pop();
		if (pos == b) {
			return cnt;
		}
		if (pos + 1 < 100001&&!visit[pos + 1]) {
			visit[pos + 1] = true;
			que.push(make_pair(pos + 1, cnt + 1));
		}
		if (pos - 1 >= 0&&!visit[pos - 1] ) {
			visit[pos - 1] = true;
			que.push(make_pair(pos - 1, cnt + 1));
		}
		if (pos * 2 < 100001&&!visit[pos*2]) {
			visit[pos*2] = true;
			que.push(make_pair(pos*2, cnt + 1));
		}

	}
}

int BOJ1697() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	
	cout << sol(a,b);
	
	return 0;
}