#include <string>
#include <vector>

using namespace std;

// 수정 코드
string solution(string new_id) {
    string answer = "";

    for (char &ch: new_id) {
        if (ch >= 'A' && ch <= 'Z') ch = tolower(ch);
    }
    for (char &ch: new_id) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || ch == '-' || ch == '_' || ch == '.') answer += ch;
    }
    string tmp = "";

    for (int i = 0; i < answer.length(); i++) {
        if (i == answer.length() - 1) tmp += answer[i];
        else if (answer[i] == '.' && answer[i + 1] == '.') continue;
        else tmp += answer[i];
    }
    answer = tmp;
    tmp = "";

    if (!answer.empty() && answer.front() == '.') answer.erase(answer.begin());
    if (!answer.empty() && answer.back() == '.') answer.pop_back();
    if (answer.empty()) answer = "a";
    if (answer.length() > 15) {
        answer = new_id.substr(0, 15);
        if (!answer.empty() && answer.back() == '.') answer.pop_back();
    }
    while (answer.length() < 3) {
        answer += answer.back();
    }
    return answer;
}

// 처음 코드

//string solution(string new_id) {
//    string answer = "";
//
//    vector<bool> erase(new_id.length(), false);
//
//    for (int i = 0; i < new_id.length(); i++) {
//        char ch = new_id[i];
//        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || ch == '-' || ch == '_' || ch == '.')
//            continue;
//        if (ch >= 'A' && ch <= 'Z') {
//            new_id[i] = tolower(ch);
//            continue;
//        }
//        erase[i] = true;
//    }
//    string tmp_id = "";
//    for (int i = 0; i < new_id.length(); i++) {
//        if (!erase[i])
//            tmp_id += new_id[i];
//    }
//    new_id = tmp_id; //2
//
//    erase.assign(new_id.length(), false);
//
//    for (int i = 0; i < new_id.length() - 1; i++) {
//        if (new_id[i] == '.' && new_id[i + 1] == '.') {
//            erase[i] = true;
//        }
//    }
//    tmp_id = "";
//    for (int i = 0; i < new_id.length(); i++) {
//        if (!erase[i])
//            tmp_id += new_id[i];
//    }
//    new_id = tmp_id; //3
//
//    if (new_id[0] == '.') // 4
//        new_id.erase(0, 1);
//    if (new_id[new_id.length() - 1] == '.')
//        new_id.erase(new_id.length() - 1, 1);
//    if (new_id.length() == 0) // 5
//        new_id = "a";
//    if (new_id.length() > 15) { // 6
//        new_id = new_id.substr(0, 15);
//        if (new_id[new_id.length() - 1] == '.')
//            new_id.erase(new_id.length() - 1, 1);
//    }
//    if (new_id.length() == 1) { // 7
//        string letter = new_id.substr(0, 1);
//        new_id += letter + letter;
//    }
//    if (new_id.length() == 2) {
//        new_id += new_id[1];
//    }
//    answer = new_id;
//
//    return answer;
//}