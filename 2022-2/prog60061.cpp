#include <string>
#include <vector>

using namespace std;

vector<vector<bool>> zero; // 기둥
vector<vector<bool>> one; // 보
int num;

bool isValid(int x, int y, int a) {
    if (a == 0) { // 기둥 설치
        if (y == 0) return true; // 바닥
        if (x > 0 && one[x - 1][y]) return true; // 보 오른쪽 위
        if (one[x][y]) return true; // 보 왼쪽 위
        if (zero[x][y - 1]) return true; // 기둥 위
    } else { // 보 설치
        if (y > 0 && zero[x][y - 1]) return true; // 기둥 위 오른쪽
        if (x < num && y > 0 && zero[x + 1][y - 1]) return true; // 기둥 위 왼쪽
        if ((x > 0 && one[x - 1][y]) && (x < num && one[x + 1][y])) return true;
    }
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    zero.assign(n + 1, vector<bool>(n + 1, false));
    one.assign(n + 1, vector<bool>(n + 1, false));
    num = n;
    for (auto i: build_frame) {
        int x = i[0];
        int y = i[1];
        int a = i[2];
        int b = i[3];
        if (b == 1) { // 설치하기
            if (a == 0) {
                if (isValid(x, y, a)) zero[x][y] = true;
            } else {
                if (isValid(x, y, a)) one[x][y] = true;
            }
        } else { // 삭제하기
            if (a == 0) { // 기둥 삭제
                zero[x][y] = false;
                bool flag = true;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        flag = true;
                        int nx = x + dx;
                        int ny = y + dy;
                        if (nx < 0 || ny < 0 || nx > num || ny > num) continue;
                        if (zero[nx][ny]) {
                            flag = isValid(nx, ny, 0);
                            if (!flag) break;
                        }
                        if (one[nx][ny]) {
                            flag = isValid(nx, ny, 1);
                            if (!flag) break;
                        }
                    }
                    if (!flag) break;
                }
                if (!flag) {
                    zero[x][y] = true;
                }
            } else { // 보 삭제
                one[x][y] = false;
                bool flag = true;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        flag = true;
                        int nx = x + dx;
                        int ny = y + dy;
                        if (nx < 0 || ny < 0 || nx > num || ny > num) continue;
                        if (zero[nx][ny]) {
                            flag = isValid(nx, ny, 0);
                            if (!flag) break;
                        }
                        if (one[nx][ny]) {
                            flag = isValid(nx, ny, 1);
                            if (!flag) break;
                        }
                    }
                    if (!flag) break;
                }
                if (!flag) {
                    one[x][y] = true;
                }
            }
        }
    }

    for (int i = 0; i <= num; i++) {
        for (int j = 0; j <= num; j++) {
            if (zero[i][j]) {
                vector<int> tmp(3);
                tmp[0] = i;
                tmp[1] = j;
                tmp[2] = 0;
                answer.push_back(tmp);
            }
            if (one[i][j]) {
                vector<int> tmp(3);
                tmp[0] = i;
                tmp[1] = j;
                tmp[2] = 1;
                answer.push_back(tmp);
            }

        }
    }

    return answer;
}