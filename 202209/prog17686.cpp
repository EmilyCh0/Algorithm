// Created by Emily Cho on 2022/09/11.
// 2018 카카오 블라인드
// lv2 파일명 정렬

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct OneFile{
    OneFile(string head, int num, string tail, int id): head(head), num(num), tail(tail), id(id){}
    string head;
    int num;
    string tail;
    int id;
};

bool comp(OneFile a, OneFile b) {
    if (a.head == b.head && a.num == b.num) {
        return a.id < b.id;
    } else if (a.head == b.head) {
        return a.num < b.num;
    } else {
        return a.head < b.head;
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<OneFile> vec;
    map<int, string> originalValue;
    int id = 0;
    for (string file: files) {
        string head, number, tail;
        int idx = 0;
        while (true) {
            if (idx == file.size()) break;
            char ch = file[idx++];
            if (ch >= '0' && ch <= '9') {
                number.push_back(ch);
                break;
            } else head.push_back(ch);
        }
        while (true) {
            if (idx == file.size()) break;
            char ch = file[idx++];
            if (ch >= '0' && ch <= '9') number.push_back(ch);
            else {
                tail.push_back(ch);
                break;
            }
        }
        tail += file.substr(idx);
        for (int i = 0; i < head.size(); i++) {
            head[i] = tolower(head[i]);
        }
        OneFile tmp = OneFile(head, stoi(number), tail, id++);
        vec.push_back(tmp);
        originalValue[tmp.id] = file;
    }
    sort(vec.begin(), vec.end(), comp);
    for (auto i: vec) {
        answer.push_back(originalValue[i.id]);
    }

    return answer;
}