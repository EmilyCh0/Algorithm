// queue 사용하지 않고 주소값으로 풀기

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1 = 0;
    long long sum2 = 0;

    int tmp = queue1.size();

    for (int i: queue1) {
        sum1 += (long long) i;
    }
    for (int i: queue2) {
        sum2 += (long long) i;
    }
    queue1.insert(queue1.end(), queue2.begin(), queue2.end());
    auto s1 = queue1.begin();
    auto s2 = s1+tmp;

    if((sum1+sum2)%2==1) return -1;

    bool flag = false;
    while (true) {
        if(answer>300000) return -1;
        if (s1 == s2) {
            break;
        }
        if (sum1 == sum2) {
            flag = true;
            break;
        } else if (sum1 > sum2) {
            answer++;
            sum1 -= *s1;
            sum2 += *s1;
            s1++;
            if (s1 == queue1.end()) s1 = queue1.begin();
        } else if (sum1 < sum2) {
            answer++;
            sum2 -= *s2;
            sum1 += *s2;
            s2++;
            if (s2 == queue1.end()) s2 = queue1.begin();
        }
    }
    if (!flag) answer = -1;

    return answer;
}