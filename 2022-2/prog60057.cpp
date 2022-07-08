#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    for (int i = 0; i < s.length(); i++) {
        int unit = i + 1;
        string ziped = "";
        string sub = "";
        int cnt = 1;
        for (int j = 0; j < s.size(); j += unit) {
            string tmp = s.substr(j, unit);
            if (j == 0) {
                sub = tmp;
                continue;
            }
            if (sub.compare(tmp) == 0) {
                cnt++;
            } else {
                if (cnt > 1) {
                    ziped = ziped + to_string(cnt) + sub;
                } else {
                    ziped = ziped + sub;
                }
                sub = tmp;
                cnt = 1;
            }
        }
        if (cnt > 1) {
            ziped = ziped + to_string(cnt) + sub;
        } else {
            ziped = ziped + sub;
        }
        if (answer > ziped.size() || answer == 0) {
            answer = ziped.size();
        }
    }
    return answer;
}