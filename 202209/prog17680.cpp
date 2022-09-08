//
// Created by Emily Cho on 2022/09/08.
// 2018 카카오 블라인드
// lv2 캐시

#include <string>
#include <vector>
#include <map>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> vec;
    map<string, bool> isCached;
    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        for (int j = 0; j < city.size(); j++) {
            city[j] = tolower(city[j]);
        }
        cities[i] = city;
    }
    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        if (isCached.count(city) == 0 || !isCached[city]) { // 캐시에 없다
            answer += 5;
            vec.push_back(city);
            isCached[city] = true;
            if (vec.size() > cacheSize) {
                isCached[vec[0]] = false;
                vec.erase(vec.begin());
            }
        } else {
            answer += 1;
            for (int j = 0; j < vec.size(); j++) {
                if (vec[j] == city) {
                    vec.erase(vec.begin() + j);
                    vec.push_back(city);
                }
            }
        }
    }
    return answer;
}