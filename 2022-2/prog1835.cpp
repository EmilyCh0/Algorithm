#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool check(vector<int> vec, string str, int idx1, int idx2){

    char op = str[3];
    int gap = str[4]-'0';
    if(op=='='){
        if(abs(idx1-idx2)-1==gap) return true;
        else return false;
    }else if(op=='>'){
        if(abs(idx1-idx2)-1>gap) return true;
        else return false;
    }else if(op=='<'){
        if(abs(idx1-idx2)-1<gap) return true;
        else return false;
    }
    return false;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<int> vec = {0,1,2,3,4,5,6,7};
    map<char, int> idxMap;
    idxMap['A'] = 0; idxMap['C'] = 1; idxMap['F'] = 2; idxMap['J'] = 3; idxMap['M'] = 4;
    idxMap['N'] = 5; idxMap['R'] = 6; idxMap['T'] = 7;

    do {
        bool flag = true;
        for(string str: data){
            int idx1 = vec[idxMap[str[0]]];
            int idx2 = vec[idxMap[str[2]]];
            flag = check(vec, str, idx1, idx2);
            if(!flag) break;
        }
        if(flag) answer++;
    }while(next_permutation(vec.begin(), vec.end()));

    return answer;
}