// Created by Emily Cho on 2022/09/18.
// lv2 방금그곡
// 2018 카카오 블라인드

#include <string>
#include <vector>
#include <sstream>

using namespace std;

string removeSharp(string str){
    for(int i=0;i<str.size();i++){
        if(str[i]=='#'){
            str[i-1] = tolower(str[i-1]);
            str.erase(str.begin()+i);
        }
    }
    return str;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    m = removeSharp(m);
    int maxLen = 0;
    for (string info: musicinfos) {

        stringstream ss(info);
        int sh, sm, eh, em;
        sh = stoi(info.substr(0, 2)) * 60;
        sm = stoi(info.substr(3, 2));
        eh = stoi(info.substr(6, 2)) * 60;
        em = stoi(info.substr(9, 2));
        int time = abs(eh + em) - abs(sh + sm);
        string subinfo = info.substr(12);
        string title = subinfo.substr(0, subinfo.find(','));
        string lyrics = subinfo.substr(subinfo.find(',') + 1);
        lyrics = removeSharp(lyrics);

        string play = lyrics;
        while (play.size() < time) play += lyrics;
        play = play.substr(0, time);
        if (play.find(m) != -1 && play.length() > maxLen) {
            maxLen = play.length();
            answer = title;
        }
    }
    return answer;
}