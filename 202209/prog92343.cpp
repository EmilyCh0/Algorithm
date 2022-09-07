// Created by Emily Cho on 2022/09/06.
// 2022 kakao blind recruitment
// lv3 양과 늑대

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> graph;
int answer = 0;

void navigate(vector<int> info, int idx, vector<int> nextN, int sheep, int wolf) {
    int s = sheep;
    int w = wolf;
    if (info[idx] == 0) s++;
    else w++;
    answer = max(answer, s);
    if (s <= w) return;

    for (int i = 0; i < nextN.size(); i++) {
        vector<int> tmp = nextN;
        tmp.erase(tmp.begin() + i);
        for (auto j: graph[nextN[i]]) tmp.push_back(j);
        navigate(info, nextN[i], tmp, s, w);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {

    int n = info.size();
    graph.assign(n, vector<int>());

    for (auto i: edges) {
        graph[i[0]].push_back(i[1]);
    }
    vector<int> nextN;
    for (auto i: graph[0]) {
        nextN.push_back(i); // 0과 연결된 노드 담기
    }

    navigate(info, 0, nextN, 0, 0);

    return answer;
}
