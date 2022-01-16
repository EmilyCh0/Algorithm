#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 4;
    string str;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (!(ch == 'U' || ch == 'C' || ch == 'P')) {
            continue;
        }
        if (cnt == 0) {
            break;
        } else if (cnt == 4 && ch == 'U') {
            cnt--;
        } else if ((cnt == 3 || cnt == 1) && ch == 'C') {
            cnt--;
        } else if (cnt == 2 && ch == 'P') {
            cnt--;
        }
    }
    if (cnt == 0) {
        cout << "I love UCPC";
    } else {
        cout << "I hate UCPC";
    }

    return 0;
}
