//
// Created by Emily Cho on 2022/08/09.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 정확성, 효율성 모두 통과
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int left = 0;
    int right = people.size() - 1;

    while (left < right) {
        if (people[left] + people[right] <= limit) {
            answer++;
            left++;
            right--;
        } else {
            answer++;
            right--;
        }
    }
    if (left == right) answer++;

    return answer;
}
/*
// 90/100 (정확성 15/15 효율성 3/5)
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    while (!people.empty()) {
        if (people.size() == 1) {
            answer++;
            break;
        }
        if (people.front() + people.back() <= limit) {
            answer++;
            people.erase(people.begin());
            people.erase(people.end() - 1);
        } else {
            answer++;
            people.erase(people.end() - 1);
        }
    }
    return answer;
}
 */

int main(){
    solution({70,50,80,50},100);
}
