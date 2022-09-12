// Created by Emily Cho on 2022/09/12.
// 2018 카카오 블라인드
// lv2 n진수 게임

#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string arr[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

    int lv = 2;
    int res = n * (n - 1);
    while (res < t * m) {
        lv++;
        res *= n;
    }
    vector<string> vec; // 4진수라면 vec = {0,1,2,3}
    vector<string> tmp;
    vector<string> tmp2;
    string str = "";
    for (int i = 0; i < n; i++) {
        vec.push_back(arr[i]);
        tmp.push_back(arr[i]);
        str += arr[i];
    }
    tmp.erase(tmp.begin()); // 0으로 시작하는 숫자 제외하므로 한자리 0 제거
    for (int i = 0; i < lv; i++) {
        tmp2.clear();
        for (auto j: tmp) {
            for (int k = 0; k < n; k++) {
                str += j + vec[k];
                tmp2.push_back(j + vec[k]);
            }
        }
        tmp.clear();
        tmp = tmp2;
    }
    p--;
    for (int i = 0; i < t; i++) {
        answer += str[p];
        p += m;
    }

    return answer;
}
