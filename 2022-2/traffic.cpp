#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<int> start;
    vector<int> end;
    for (int i = 0; i < lines.size(); i++) {
        string l = lines[i];
        l.pop_back();

        int hh, mm, ss, ms, time;
        hh = stoi(l.substr(11, 2)) * 60 * 60 * 1000;
        mm = stoi(l.substr(14, 2)) * 60 * 1000;
        ss = stoi(l.substr(17, 2)) * 1000;
        ms = stoi(l.substr(20, 3));
        time = stof(l.substr(24, 5)) * 1000;

        int e = hh + mm + ss + ms;
        int s = e - time + 1;

        start.push_back(s);
        end.push_back(e);
    }
    for (int i = 0; i < lines.size(); i++) {
        int rangeE = end[i] + 1000;
        int cnt = 1;
        for (int j = i + 1; j < lines.size() - i; j++) {
            if (start[j] < rangeE) {
                cnt++;
            }
        }
        answer = max(answer, cnt);
    }

    return answer;
}