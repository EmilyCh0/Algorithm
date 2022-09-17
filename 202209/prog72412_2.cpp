//
// Created by Emily Cho on 2022/09/17.
//

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, vector<int>> um;

void allCase(string str, int score){
    char arr[4][2] = {{str[0],'-'},{str[1],'-'},{str[2],'-'},{str[3],'-'}};
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                for(int l=0;l<2;l++){
                    string tmp = "";
                    tmp += arr[0][i]; tmp += arr[1][j]; tmp += arr[2][k]; tmp += arr[3][l];
                    um[tmp].push_back(score);
                }
            }
        }
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for(auto i: info){
        string str[4];
        int score;
        stringstream ss(i);
        ss>>str[0]>>str[1]>>str[2]>>str[3]>>score;
        string s = "";
        s +=str[0][0]; s +=str[1][0]; s +=str[2][0]; s +=str[3][0];
        allCase(s, score);
    }
    for(auto iter = um.begin(); iter !=um.end();iter++){
        sort(iter->second.begin(), iter->second.end());
    }
    for(auto i: query){
        string str[4], aand;
        int score;
        stringstream ss(i);
        ss>>str[0]>>aand>>str[1]>>aand>>str[2]>>aand>>str[3]>>score;
        string s = "";
        s +=str[0][0]; s +=str[1][0]; s +=str[2][0]; s +=str[3][0];
        vector<int> scores = um[s];
        //sort(scores.begin(), scores.end());
        if(scores.size()!=0){
            int idx = lower_bound(scores.begin(), scores.end(), score) - scores.begin();
            answer.push_back(scores.size()-idx);
        }else answer.push_back(0);
    }
    return answer;
}
