#include <string>
#include <vector>
#include <queue>

using namespace std;

struct person{
    int i; int j; int depth;
    person(int ii, int jj, int dd){
        i=ii; j=jj; depth=dd;
    }
};


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};
    for (vector<string> tc: places) {
        vector<vector<int>> map(5, vector<int>(5, 0));
        queue<person> que;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (tc[i][j] == 'P') {
                    map[i][j] = 1;
                    que.push(person(i, j, 0));
                } else if (tc[i][j] == 'X') {
                    map[i][j] = -1;
                }
            }
        }

        bool flag = false;

        while (!que.empty()) {
            queue<person> subque;
            subque.push(que.front());
            que.pop();
            flag = false;

            vector<vector<bool>> visit(5, vector<bool>(5, false));

            while (!subque.empty()) {
                auto p = subque.front();
                visit[p.i][p.j] = true;
                subque.pop();
                if (p.depth == 2) continue;
                for (int k = 0; k < 4; k++) {
                    int ni = p.i + di[k];
                    int nj = p.j + dj[k];
                    if (ni < 0 || nj < 0 || ni > 4 || nj > 4 || visit[ni][nj]) continue;
                    if (map[ni][nj] == 1) {
                        answer.push_back(0);
                        flag = true;
                        break;
                    } else if (map[ni][nj] == -1) {
                        visit[ni][nj] = true;
                        continue;
                    }
                    subque.push(person(ni, nj, p.depth + 1));
                }
                if (flag) break;
            }
            if (flag) break;
        }
        if (!flag) answer.push_back(1);
    }

    return answer;
}