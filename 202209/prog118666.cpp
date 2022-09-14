// Created by Emily Cho on 2022/09/14.
// lv1 성격 유형 검사하기

#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> mm;
    mm['R'] = 0; mm['C'] = 0; mm['J'] = 0; mm['A'] = 0;
    mm['T'] = 0; mm['F'] = 0; mm['M'] = 0; mm['N'] = 0;
    for(int i=0;i<survey.size();i++){
        char a = survey[i][0];
        char b = survey[i][1];
        int choice = choices[i];
        if(choice==4) continue;
        else if(choice<4){
            mm[a]+=4-choice;
        }else{
            mm[b]+=choice-4;
        }
    }
    if(mm['R']<mm['T']) answer+='T';
    else answer+='R';
    if(mm['C']<mm['F']) answer+='F';
    else answer+='C';
    if(mm['J']<mm['M']) answer+='M';
    else answer+='J';
    if(mm['A']<mm['N']) answer+='N';
    else answer+='A';

    return answer;
}