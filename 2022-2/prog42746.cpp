#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b){
    return stoi(a+b) > stoi(b+a);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> vec;
    for (int i: numbers) {
        vec.push_back(to_string(i));
    }
    sort(vec.begin(), vec.end(), comp);
    for (string i: vec) {
        answer += i;
    }
    if (answer[0] == '0') {
        answer = "0";
    }
    return answer;
}