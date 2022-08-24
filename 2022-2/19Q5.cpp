#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1e9;
    vector<vector<int>> cost(n + 1, vector<int>(n + 1, 1e7 * 2));
    for (int i = 1; i <= n; i++) {
        cost[i][i] = 0;
    }
    for (int i = 0; i < fares.size(); i++) {
        int s = fares[i][0];
        int e = fares[i][1];
        int w = fares[i][2];
        cost[s][e] = cost[e][s] = w;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        answer = min(answer, cost[s][i] + cost[i][a] + cost[i][b]);
    }

    return answer;
}