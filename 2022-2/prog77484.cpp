#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zeroCnt = 0;
    int winCnt = 0;
    for (int num: lottos) {
        if (num == 0) {
            zeroCnt++;
        } else {
            for (int winNum: win_nums) {
                if (num == winNum)
                    winCnt++;
            }
        }
    }
    int rank = 7 - (winCnt + zeroCnt);
    if (rank > 5) {
        answer.push_back(6);
    } else {
        answer.push_back(rank);
    }
    if (winCnt < 2) {
        answer.push_back(6);
    } else {
        answer.push_back(7 - winCnt);
    }
    return answer;
}