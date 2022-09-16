// Created by Emily Cho on 2022/09/16.
// 2019 카카오 블라인드
// lv2 후보키

#include <string>
#include <vector>
#include <set>

using namespace std;

int answer = 0;
int relationCnt;
int tupleCnt;
vector<vector<string>> relCopy;
vector<bool> visit;
set<string> uniq;

bool check(string choice) {
    set<string> countUniq;
    // choice에 선택된 속성을 더하여 유일성 체크 ex) 첫 번째 튜플에서 choice: "01"이라면 tmp: "100ryan"
    for (int i = 0; i < tupleCnt; i++) {
        string tmp = "";
        for (int j = 0; j < choice.size(); j++) {
            int idx = choice[j] - '0';
            tmp += relCopy[i][idx];
        }
        countUniq.insert(tmp);
    }
    if (countUniq.size() == tupleCnt) { // 유일성 만족
        uniq.insert(choice);
        if (choice.size() == 1) return true;
        for (int i = 0; i < choice.size(); i++) {
            string tmpChoice = choice;
            tmpChoice.erase(tmpChoice.begin() + i);
            if (uniq.count(tmpChoice) == 1) return false; // 최소성 만족 X
        }
        return true; // 최소성 만족
    }
    return false;
}

void comb(int cnt, int idx, int n) {
    if (cnt == n) {
        string choice = ""; // 선택된 인덱스 나열
        for (int i = 0; i < visit.size(); i++) {
            if (visit[i]) choice += to_string(i);
        }
        if (check(choice)) { // 유일성 최소성을 모두 만족하면
            answer++;
            return;
        }
        return;
    }
    for (int i = idx; i < relationCnt; i++) {
        if (visit[i]) continue;
        visit[i] = true;
        comb(cnt + 1, i + 1, n);
        visit[i] = false;
    }
}

int solution(vector<vector<string>> relation) {
    relationCnt = relation[0].size();
    tupleCnt = relation.size();
    visit.assign(relationCnt, false);
    relCopy = relation;
    for (int i = 1; i <= relationCnt; i++) {
        comb(0, 0, i);
    }
    return answer;
}
