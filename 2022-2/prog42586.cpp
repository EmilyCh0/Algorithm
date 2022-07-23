#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    int n = progresses.size();
    for (int i = 0; i < n; i++) {
        int gap = 100 - progresses[i];
        int d = gap / speeds[i];
        if (gap % speeds[i] != 0) {
            d++;
        }
        days.push_back(d);
    }
    int cnt = 1;
    int maxNum = days[0];
    for (int i = 1; i < n; i++) {
        if (days[i] > maxNum) {
            answer.push_back(cnt);
            cnt = 1;
            maxNum = days[i];
        } else {
            cnt++;
        }
    }
    answer.push_back(cnt);

    return answer;
}