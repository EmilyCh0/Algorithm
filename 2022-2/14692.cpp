#include<iostream>

using namespace std;

int main(int argc, char** argv) {
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        int n;
        cin >> n;
        if (n % 2 == 0) cout << "#" << test_case << " Alice\n";
        else cout << "#" << test_case << " Bob\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}