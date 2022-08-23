#include <string>
#include <vector>

using namespace std;

vector<int> ryan(11);
int num;
vector<int> apeach;
vector<int> answer(11);
int mxDiff = 0;
int scoreDiff() {
    int r = 0;
    int a = 0;
    for (int i = 0; i < 11; i++) {
        if (ryan[i] == 0 && apeach[i] == 0) continue;
        if (ryan[i] > apeach[i]) r += (10 - i);
        else a += (10 - i);
    }
    return r - a;
}

void comb(int idx, int cnt) {
    if (cnt == num) {
        int diff = scoreDiff();
        if (diff > mxDiff) {
            mxDiff = diff;
            for (int i = 0; i < 11; i++) {
                answer[i] = ryan[i];
            }
            return;
        }
        if (diff == mxDiff) {
            bool flag = false;
            for (int i = 10; i >= 0; i--) {
                if (ryan[i] > answer[i]) {
                    flag = true;
                    break;
                } else if (ryan[i] < answer[i]) break;
            }
            if (flag) {
                for (int i = 0; i < 11; i++) {
                    answer[i] = ryan[i];
                }
            }
        }
        return;
    }
    if (idx > 10) return;
    ryan[idx]++;
    comb(idx, cnt + 1);
    ryan[idx]--;
    comb(idx + 1, cnt);
}

vector<int> solution(int n, vector<int> info) {
    num = n;
    for (int i: info) apeach.push_back(i);
    comb(0, 0);
    bool flag = false;
    for (int i = 0; i < 11; i++) {
        if (answer[i] != 0) {
            flag = true;
            break;
        }
    }
    if (!flag || mxDiff == 0) return {-1};
    return answer;
}