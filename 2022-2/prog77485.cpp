#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> vec(rows, vector<int>(columns));
    int idx = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            vec[i][j] = idx++;
        }
    }
    int n = queries.size();
    for (int i = 0; i < n; i++) {
        int r1 = queries[i][0] - 1;
        int r2 = queries[i][2] - 1;
        int c1 = queries[i][1] - 1;
        int c2 = queries[i][3] - 1;
        int save = vec[r1][c1];
        int minNum = save;
        for (int j = c1 + 1; j <= c2; j++) {
            int tmp = save;
            save = vec[r1][j];
            minNum = min(minNum, save);
            vec[r1][j] = tmp;
        }
        for (int j = r1 + 1; j <= r2; j++) {
            int tmp = save;
            save = vec[j][c2];
            minNum = min(minNum, save);
            vec[j][c2] = tmp;
        }
        for (int j = c2 - 1; j >= c1; j--) {
            int tmp = save;
            save = vec[r2][j];
            minNum = min(minNum, save);
            vec[r2][j] = tmp;
        }
        for (int j = r2 - 1; j >= r1; j--) {
            int tmp = save;
            save = vec[j][c1];
            minNum = min(minNum, save);
            vec[j][c1] = tmp;
        }
        answer.push_back(minNum);
    }

    return answer;
}