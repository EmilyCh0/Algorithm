#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
    return a > b;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int n = priorities.size();
    vector<int> copyForSorting(n);
    vector<bool> visit(n, false);
    copy(priorities.begin(), priorities.end(), copyForSorting.begin());
    sort(copyForSorting.begin(), copyForSorting.end(), desc);
    int idx = 0;
    for (int i = 0; i < n; i++) {
        int rank = copyForSorting[i];
        while (true) {
            if (visit[i]) {
                continue;
            }
            if (priorities[idx] == rank) {
                visit[i] = true;
                answer++;
                if (idx == location) {
                    return answer;
                }
                idx++;
                if (idx == n)
                    idx = 0;
                break;
            }
            idx++;
            if (idx == n)
                idx = 0;
        }
    }
    return answer;
}