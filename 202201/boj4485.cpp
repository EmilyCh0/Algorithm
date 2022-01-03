#include <iostream>
#include "vector"
#include "queue"

using namespace std;
int n;
vector<vector<int>> map;
vector<vector<int>> cost;

struct node{
    node(int i, int j, int c): i(i), j(j), cost(c){ }
    int i;
    int j;
    int cost;
};
struct comp{
    bool operator()(node n1, node n2){
        return n1.cost > n2.cost;
    }
};

void dijkstra(int i, int j) {
    priority_queue<node, vector<node>, comp> pq;
    pq.push(node(i, j, map[i][j]));
    cost[i][j] = map[i][j];
    while (!pq.empty()) {
        int curcost = pq.top().cost;
        int curi = pq.top().i;
        int curj = pq.top().j;
        pq.pop();
        if (curi < n - 1) {
            int ncost = curcost + map[curi + 1][curj];
            if (cost[curi + 1][curj] > ncost) {
                cost[curi + 1][curj] = ncost;
                pq.push(node(curi + 1, curj, ncost));
            }
        }
        if (curj < n - 1) {
            int ncost = curcost + map[curi][curj + 1];
            if (cost[curi][curj + 1] > ncost) {
                cost[curi][curj + 1] = ncost;
                pq.push(node(curi, curj + 1, ncost));
            }
        }
        if (curi > 0) {
            int ncost = curcost + map[curi - 1][curj];
            if (cost[curi - 1][curj] > ncost) {
                cost[curi - 1][curj] = ncost;
                pq.push(node(curi - 1, curj, ncost));
            }
        }
        if (curj > 0) {
            int ncost = curcost + map[curi][curj - 1];
            if (cost[curi][curj - 1] > ncost) {
                cost[curi][curj - 1] = ncost;
                pq.push(node(curi, curj - 1, ncost));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int idx = 1;
    while (true) {

        cin >> n;
        if (n == 0) {
            break;
        }
        map.assign(n, vector<int>(n, 0));
        cost.assign(n, vector<int>(n, 987654321));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
            }
        }
        dijkstra(0, 0);
        cout << "Problem " << idx << ": " << cost[n - 1][n - 1] << "\n";
        idx++;
    }

    return 0;
}

