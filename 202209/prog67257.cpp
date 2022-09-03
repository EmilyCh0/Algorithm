//
// Created by Emily Cho on 2022/09/03.
// 2020 카카오 인턴십
// 수식최대화

#include <string>
#include <vector>
#include <deque>

using namespace std;

deque<long long> numbers;
deque<char> operators;
deque<long long> tmpNum;
deque<char> tmpOp;

void calculate(char oper){
    while(!operators.empty()){
        long long b = numbers.front();
        char op = operators.front();
        if(op!= oper){
            tmpNum.push_back(b);
            numbers.pop_front();
            tmpOp.push_back(op);
            operators.pop_front();
        }else{
            numbers.pop_front();
            long long a = numbers.front();
            numbers.pop_front();
            long long res;
            if(oper=='*') res = b*a;
            else if(oper=='-') res = b-a;
            else res = b+a;
            numbers.push_front(res);
            operators.pop_front();
        }
    }
    tmpNum.push_back(numbers.front());
    numbers.pop_front();
    while(!tmpNum.empty()){
        numbers.push_back(tmpNum.front());
        tmpNum.pop_front();
    }
    while(!tmpOp.empty()){
        operators.push_back(tmpOp.front());
        tmpOp.pop_front();
    }
}

long long solution(string expression) {
    long long answer = 0;
    deque<long long> oriNumbers;
    deque<char> oriOperators;

    string num = "";
    for(char i: expression){
        if(i=='-'||i=='*'||i=='+'){
            oriNumbers.push_back(stoll(num));
            num = "";
            oriOperators.push_back(i);
        }else{
            num+=i;
        }
    }
    if(num!="") oriNumbers.push_back(stoll(num));
    // 초기화
    numbers = deque<long long>();
    numbers = oriNumbers;
    operators = deque<char>();
    operators = oriOperators;
    // * + -
    calculate('*');
    calculate('+');
    calculate('-');
    answer = max(answer, (long long)(abs(numbers.front())));
    // 초기화
    numbers = deque<long long>();
    numbers = oriNumbers;
    operators = deque<char>();
    operators = oriOperators;
    // * + -
    calculate('*');
    calculate('-');
    calculate('+');
    answer = max(answer, (long long)(abs(numbers.front())));
    // 초기화
    numbers = deque<long long>();
    numbers = oriNumbers;
    operators = deque<char>();
    operators = oriOperators;
    // * + -
    calculate('+');
    calculate('*');
    calculate('-');
    answer = max(answer, (long long)(abs(numbers.front())));
    // 초기화
    numbers = deque<long long>();
    numbers = oriNumbers;
    operators = deque<char>();
    operators = oriOperators;
    // * + -
    calculate('+');
    calculate('-');
    calculate('*');
    answer = max(answer, (long long)(abs(numbers.front())));
    // 초기화
    numbers = deque<long long>();
    numbers = oriNumbers;
    operators = deque<char>();
    operators = oriOperators;
    // * + -
    calculate('-');
    calculate('*');
    calculate('+');
    answer = max(answer, (long long)(abs(numbers.front())));
    // 초기화
    numbers = deque<long long>();
    numbers = oriNumbers;
    operators = deque<char>();
    operators = oriOperators;
    // * + -
    calculate('-');
    calculate('+');
    calculate('*');
    answer = max(answer, (long long)(abs(numbers.front())));

    return answer;
}