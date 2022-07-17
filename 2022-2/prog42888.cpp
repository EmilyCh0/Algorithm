#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    string opt, id, name;
    for (auto str : record) {
        stringstream sstream(str);
        string word;
        vector<string> words;
        while (getline(sstream, word, ' ')) {
            words.push_back(word);
        }
        opt = words[0];

        if (opt.compare("Enter") == 0) {
            id = words[1];
            name = words[2];
            if (m.count(id) == 0) {
                m.insert(make_pair(id, name));
            } else {
                m[id] = name;
            }
        } else if (opt.compare("Change") == 0) {
            id = words[1];
            name = words[2];
            m[id] = name;
        }
    }
    for (auto str : record) {
        stringstream sstream(str);
        vector<string> words;
        string word;
        while (getline(sstream, word, ' ')) {
            words.push_back(word);
        }
        opt = words[0];
        if (opt.compare("Enter") == 0) {
            id = words[1];
            name = m[id];
            answer.push_back(name + "님이 들어왔습니다.");
        } else if (opt.compare("Leave") == 0) {
            id = words[1];
            name = m[id];
            answer.push_back(name + "님이 나갔습니다.");
        }
    }

    return answer;
}

