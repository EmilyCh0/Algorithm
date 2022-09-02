//
// Created by Emily Cho on 2022/09/02.
// 2020 Kakao blind recruitment
// 괄호 변
#include <string>
#include <vector>

using namespace std;

bool check(string u) { // 올바른 괄호 확인
    int open = 0;
    for (int i = 0; i < u.length(); i++) {
        if (u[i] == '(') open++;
        else open--;
        if (open < 0) return false;
    }
    return true;
}

string solve(string str) {
    if (str == "") return str;
    int open = 0;
    int close = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') open++;
        else close++;
        if (open == close) {
            string u = str.substr(0, i + 1);
            string v = str.substr(i + 1);
            if (check(u)) {
                return u + solve(v);
            } else {
                string tmp = '(' + solve(v) + ')';
                string subu = "";
                for (int j = 1; j < u.length() - 1; j++) {
                    if (u[j] == '(') subu += ')';
                    else subu += '(';
                }
                tmp += subu;
                return tmp;
            }
        }
    }
}

string solution(string p) {
    string answer = solve(p);
    return answer;
}

