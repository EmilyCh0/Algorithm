//
// Created by Emily Cho on 2022/09/02.
// 2017 카카오코드 예선
// 카카오프렌즈 컬러링북

#include <vector>
#include <queue>

using namespace std;

queue<pair<int, int>> que;
vector<vector<bool>> visit;
int di[] = {1,-1,0,0};
int dj[] = {0,0,1,-1};
int row, col;

int bfs(int i, int j, int c, vector<vector<int>> pic) {
    int cnt = 1;
    int color = c;
    que.push({i, j});
    visit[i][j] = true;
    while (!que.empty()) {
        int ii = que.front().first;
        int jj = que.front().second;
        que.pop();
        for (int k = 0; k < 4; k++) {
            int ni = ii + di[k];
            int nj = jj + dj[k];
            if (ni < 0 || nj < 0 || ni >= row || nj >= col || visit[ni][nj]) continue;
            if (pic[ni][nj] == color) {
                que.push({ni, nj});
                visit[ni][nj] = true;
                cnt++;
            }
        }
    }
    return cnt;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    row = m;
    col = n;

    que = queue<pair<int, int>>();
    visit.assign(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visit[i][j]) continue;
            if (picture[i][j] == 0) {
                visit[i][j] = true;
            } else {
                number_of_area++;
                int area = bfs(i, j, picture[i][j], picture);
                max_size_of_one_area = max(max_size_of_one_area, area);
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

