// Created by Emily Cho on 2022/09/09.
// 2018 카카오 블라인드
// lv2 프렌즈4블록

#include <string>
#include <vector>

using namespace std;

int di[] = {0,1,1};
int dj[] = {1,1,0};

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<char>> vec(n);
    for (int i = m - 1; i >= 0; i--) {
        string str = board[i];
        for (int j = 0; j < n; j++) {
            vec[j].push_back(str[j]);
        }
    }
    while (true) {
        bool flag = false;
        vector<vector<bool>> eraseList(n, vector<bool>(m, false));
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                for (int k = 0; k < 3; k++) {
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if (vec[ni][nj] != vec[i][j] || vec[ni][nj] == '0') {
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    flag = false;
                    continue;
                } else {
                    eraseList[i][j] = true;
                    eraseList[i + 1][j] = true;
                }
            }
        }
        bool isDone = true;
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (eraseList[i][j]) {
                    isDone = false;
                    answer++;
                    vec[i].erase(vec[i].begin() + j);
                    vec[i].push_back('0');
                    if (j < m - 1 && eraseList[i][j + 1]) continue;
                    answer++;
                    vec[i].erase(vec[i].begin() + j);
                    vec[i].push_back('0');
                }
            }
        }
        if (isDone) break;
    }
    return answer;
}
