// Created by Emily Cho on 2022/09/08.
// 2018 카카오 블라인드
// lv1 다트 게임

#include <string>
#include <sstream>
#include <vector>

using namespace std;

int solution(string dartResult) {

    vector<int> vec(3, 0);
    int num;
    stringstream ss(dartResult);

    for (int i = 0; i < 3; i++) {
        ss >> num;
        char bonus, opt;

        bonus = ss.get();
        if (bonus == 'D') num *= num;
        else if (bonus == 'T') num *= num * num;
        vec[i] = num;

        opt = ss.get();
        if (opt == '*') {
            if (i > 0) vec[i - 1] *= 2;
            vec[i] *= 2;
        } else if (opt == '#') {
            vec[i] *= -1;
        } else ss.unget();
    }

    return vec[0] + vec[1] + vec[2];
}
