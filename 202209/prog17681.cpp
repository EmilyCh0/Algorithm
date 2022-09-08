// Created by Emily Cho on 2022/09/08.
// 2018 카카오 블라인드
// lv1 비밀지도

#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<vector<bool>> vec(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        int num = arr1[i];
        for (int j = n - 1; j >= 0; j--) {
            if (num > 0) {
                if (num % 2 == 1) vec[i][j] = true;
                num /= 2;
            } else continue;
        }
    }
    for (int i = 0; i < n; i++) {
        int num = arr2[i];
        for (int j = n - 1; j >= 0; j--) {
            if (num > 0) {
                if (num % 2 == 1) vec[i][j] = true;
                num /= 2;
            } else continue;
        }
    }
    vector<string> answer;
    for (int i = 0; i < n; i++) {
        string tmp = "";
        for (int j = 0; j < n; j++) {
            if (vec[i][j]) tmp += '#';
            else tmp += ' ';
        }
        answer.push_back(tmp);
    }

    return answer;
}