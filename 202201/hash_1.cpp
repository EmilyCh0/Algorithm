#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;
    for (int i = 0; i < participant.size(); i++) {
        if (m.find(participant[i]) == m.end()) {
            m[participant[i]] = 1;
        } else {
            m[participant[i]]++;
        }
    }
    for (int i = 0; i < completion.size(); i++) {
        m[completion[i]]--;
    }
    string answer = "";
    for (auto i: m) {
        if (i.second == 1) {
            answer = i.first;
        }
    }
    return answer;
}
