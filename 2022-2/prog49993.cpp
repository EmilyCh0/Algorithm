//
// Created by Emily Cho on 2022/08/12.
//

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<bool> isSkill(26, false);
map<char, int> skillMap;

bool isLearnable(string str) {
    int idx = 0;
    for (char ch: str) {
        if (!isSkill[ch - 'A']) continue;
        if (skillMap[ch] == idx) {
            idx++;
            continue;
        } else return false;
    }
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int order = 0;
    for (char ch: skill) {
        isSkill[ch - 'A'] = true;
        skillMap[ch] = order++;
    }
    for (string str: skill_trees) {
        if (isLearnable(str)) answer++;
    }
    return answer;
}