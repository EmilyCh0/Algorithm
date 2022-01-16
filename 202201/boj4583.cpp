#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> vec(26, -1);

void check(string str) {
    string tmp = "";
    for (int i = str.size() - 1; i >= 0; i--) {
        if (vec[str[i] - 'a'] == -1) {
            cout << "INVALID\n";
            return;
        } else {
            tmp += (char) vec[str[i] - 'a'];
        }
    }
    cout << tmp << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vec[1] = 3 + 'a'; vec[3] = 1 + 'a'; vec[8] = 8 + 'a'; vec[14] = 14 + 'a'; vec[15] = 16 + 'a'; vec[16] = 15 + 'a'; vec[21] = 21 + 'a'; vec[22] = 22 + 'a'; vec[23] = 23 + 'a';

    while (true) {
        string str;
        cin >> str;
        if (str == "#") {
            break;
        }
        check(str);
    }

    return 0;
}