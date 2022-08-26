// queue 사용

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1 = 0;
    long long sum2 = 0;

    queue<int> que1;
    queue<int> que2;

    for (int i: queue1) {
        sum1 += (long long) i;
        que1.push(i);
    }
    for (int i: queue2) {
        sum2 += (long long) i;
        que2.push(i);
    }

    if ((sum1 + sum2) % 2 == 1) return -1;

    bool flag = false;
    while (true) {
        if (answer > 300000) return -1;

        if (sum1 == sum2) {
            flag = true;
            break;
        } else if (sum1 > sum2) {
            answer++;
            sum1 -= que1.front();
            sum2 += que1.front();
            que2.push(que1.front());
            que1.pop();
        } else if (sum1 < sum2) {
            answer++;
            sum2 -= que2.front();
            sum1 += que2.front();
            que1.push(que2.front());
            que2.pop();
        }
    }
    if (!flag) answer = -1;

    return answer;
}