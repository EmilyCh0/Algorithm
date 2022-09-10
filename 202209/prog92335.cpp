// Created by Emily Cho on 2022/09/10.
// 2022 카카오 블라인드
// lv2 k진수에서 소수 개수 구하기

#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

bool isPrime(long long n){
    for(long long i=2;i<pow(n,0.5)+1;i++){
        if(n%i==0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string res = "";
    int input = n;
    while (input > 0) {
        res = to_string(input % k) + res;
        input /= k;
    }
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == '0') {
            res[i] = ' ';
        }
    }
    stringstream ss(res);
    long long num;
    while (ss >> num) {
        if (num == 1) continue;
        else if (num == 2) {
            answer++;
            continue;
        }
        if (isPrime(num)) answer++;
    }
    return answer;
}