//
// Created by Emily Cho on 2022/08/16.
//

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";

    vector<int> numbers;

    stringstream sstream(s);
    string num;
    while (getline(sstream, num, ' ')) {
        numbers.push_back(stoi(num));
    }
    sort(numbers.begin(), numbers.end());

    answer = to_string(numbers[0]) + " " + to_string(numbers[numbers.size() - 1]);

    return answer;
}