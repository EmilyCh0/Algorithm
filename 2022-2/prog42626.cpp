#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i: scoville) pq.push(i);
    while (true) {
        if (pq.top() >= K) {
            break;
        }
        answer++;
        if (pq.empty() || pq.size() == 1) return -1;
        int res = pq.top();
        pq.pop();
        res += pq.top() * 2;
        pq.pop();
        pq.push(res);
    }

    return answer;
}