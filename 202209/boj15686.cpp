// Created by Emily Cho on 2022/09/23.
// 백준 15686 치킨 배달 (골5)

#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> vec;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<bool> selected;
int minChickenDist = 1e9;
int n, m;

void func(int idx, int cnt) {
    if (cnt == m) {
        // 도시의 치킨 거리
        int sum = 0;
        vector<pair<int, int>> selectedChic;
        for (int i = 0; i < chicken.size(); i++) if (selected[i]) selectedChic.push_back(chicken[i]);
        for (auto h: house) {
            int minDist = 101;
            for (auto c: selectedChic) {
                minDist = min(minDist, abs(h.first - c.first) + abs(h.second - c.second));
            }
            sum += minDist;
        }
        minChickenDist = min(minChickenDist, sum);
        return;
    }
    for(int i=idx;i<chicken.size();i++){
        selected[i] = true;
        func(i+1, cnt+1);
        selected[i] = false;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vec.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vec[i][j];
            if (vec[i][j] == 1) house.push_back({i, j});
            else if (vec[i][j] == 2) chicken.push_back({i, j});
        }
    }
    selected.assign(chicken.size(), false);
    func(0, 0);
    cout << minChickenDist;
    return 0;
}