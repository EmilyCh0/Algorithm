// Created by Emily Cho on 2022/09/10.
// 2018 카카오 블라인드
// lv2 압축

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 26; i++) {
        dict[alphabet.substr(i, 1)] = i + 1;
    }
    int dictIdx = 27;
    int idx = 0;
    while (true) {
        if (idx == msg.size()) break;
        string sub;
        sub.push_back(msg[idx]);
        while (true) {
            if (dict.count(sub) == 1) {
                idx++;
                sub.push_back(msg[idx]);
            } else {
                sub.pop_back();
                answer.push_back(dict[sub]);
                sub.push_back(msg[idx]);
                dict[sub] = dictIdx++;
                break;
            }
        }
    }
    return answer;
}
