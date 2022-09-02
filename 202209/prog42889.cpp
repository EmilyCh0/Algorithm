//
// Created by Emily Cho on 2022/09/02.
// 2019 Kakao Blind Recruitment
// 실패율

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, double> a, pair<int, double> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    } else return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> onStageCnt(N + 1, 0);
    for (int i: stages) {
        onStageCnt[i - 1]++;
    }
    vector<double> reachedCnt(N, 0);
    int cnt = onStageCnt[N];
    for (int i = N - 1; i >= 0; i--) {
        cnt += onStageCnt[i];
        reachedCnt[i] = cnt;
    }

    vector<pair<int, double>> vec;
    for (int i = 0; i < N; i++) {
        if (onStageCnt[i] == 0) vec.push_back({i + 1, 0.0});
        else {
            double res = onStageCnt[i] / reachedCnt[i];
            vec.push_back({i + 1, res});
        }
    }
    sort(vec.begin(), vec.end(), comp);
    for (auto v: vec) {
        answer.push_back(v.first);
    }

    return answer;
}