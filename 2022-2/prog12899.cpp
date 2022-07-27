#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    while (true) {
        if (n < 3) {
            answer = to_string(n) + answer;
            break;
        }
        int quot = n / 3;
        int rem = n % 3;
        if (rem == 0) {
            quot--;
            rem = 4;
        }
        answer = to_string(rem) + answer;
        n = quot;
        if (n == 0)
            break;
    }
    return answer;
}