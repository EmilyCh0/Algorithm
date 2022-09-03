//
// Created by Emily Cho on 2022/09/03.
// 2018 카카오 블라인드 채용
// lv2 뉴스 클러스터링

#include <string>
#include <map>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    for (int i = 0; i < str1.length(); i++) {
        str1[i] = tolower(str1[i]);
    }
    for (int i = 0; i < str2.length(); i++) {
        str2[i] = tolower(str2[i]);
    }
    map<string, int> substr1;
    vector<string> vec1;
    for (int i = 0; i < str1.length() - 1; i++) {
        string sub = str1.substr(i, 2);
        if (sub[0] < 'a' || sub[0] > 'z' || sub[1] < 'a' || sub[1] > 'z') continue;
        if (substr1.count(sub) != 0) substr1[sub]++;
        else substr1[sub] = 1;
        vec1.push_back(sub);
    }
    map<string, int> substr2;
    vector<string> vec2;
    for (int i = 0; i < str2.length() - 1; i++) {
        string sub = str2.substr(i, 2);
        if (sub[0] < 'a' || sub[0] > 'z' || sub[1] < 'a' || sub[1] > 'z') continue;
        if (substr2.count(sub) != 0) substr2[sub]++;
        else substr2[sub] = 1;
        vec2.push_back(sub);
    }

    int interCnt = 0;
    vector<string> tmp;
    for (auto i: substr1) {
        tmp.push_back(i.first);
    }
    for (auto i: tmp) {
        if (substr2.count(i) != 0) {
            interCnt += min(substr1[i], substr2[i]);
        }
    }
    int unionCnt = vec1.size() + vec2.size() - interCnt;
    if (unionCnt == 0) return 65536;
    answer = ((double) interCnt / (double) unionCnt) * 65536;

    return answer;
}
