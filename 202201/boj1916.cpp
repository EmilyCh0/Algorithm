#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> vec[1001];
vector<int> dist;

void dijkstra(int src) {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (dist[now] < cost) {
            continue;
        }
        for (int i = 0; i < vec[now].size(); i++) {
            int next = vec[now][i].first;
            int nCost = vec[now][i].second + dist[now];
            if (dist[next] > nCost) {
                dist[next] = nCost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    dist.resize(n + 1, 987654321);

    for (int i = 0; i < m; i++) {
        int s, d, c;
        cin >> s >> d >> c;
        vec[s].push_back(make_pair(d, c));
    }
    int src, dst;
    cin >> src >> dst;

    dijkstra(src);

    cout << dist[dst];

    return 0;
}