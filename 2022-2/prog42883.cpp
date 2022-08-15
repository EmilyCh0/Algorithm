//
// Created by Emily Cho on 2022/08/15.
//

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.size();
    int left = 0;
    int right = k;
    while (true) {
        if (answer.size() == len - k) break;
        char mx = number[left];
        int mxIdx = left;
        for (int i = left + 1; i <= right; i++) {
            if (mx < number[i]) {
                mx = number[i];
                mxIdx = i;
            }
        }
        answer += mx;
        left = mxIdx + 1;
        right++;
    }
    return answer;
}