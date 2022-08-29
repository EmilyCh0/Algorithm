#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int timeToInt(string str) {
    int hr = stoi(str.substr(0, 2));
    int min = stoi(str.substr(3, 2));
    return hr * 60 + min;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<string> carNumbers;
    map<string, bool> isIn;
    map<string, pair<int, int>> map;
    for (string str: records) {
        int time = timeToInt(str.substr(0, 5));
        string num = str.substr(6, 4);
        int opt = str[11] == 'I' ? 0 : 1;
        if (opt == 0) { // IN
            isIn[num] = true;
            if (map.count(num) == 0) {
                map[num] = {time, 0};
                carNumbers.push_back(num);
            } else {
                map[num].first = time;
            }
        } else { // OUT
            map[num].second += time - map[num].first;
            isIn[num] = false;
        }
    }
    for (string num: carNumbers) {
        if (isIn[num]) {
            int endTime = 23 * 60 + 59;
            map[num].second += endTime - map[num].first;
        }
    }
    sort(carNumbers.begin(), carNumbers.end());
    for (string num: carNumbers) {
        int totalTime = map[num].second;
        int sum = 0;
        if (totalTime <= fees[0]) answer.push_back(fees[1]);
        else {
            totalTime -= fees[0];
            sum += fees[1];
            sum += (totalTime / fees[2]) * fees[3];
            if (totalTime % fees[2] != 0) sum += fees[3];
            answer.push_back(sum);
        }
    }
    return answer;
}