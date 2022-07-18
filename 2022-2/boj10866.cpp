#include "iostream"
#include "deque"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    deque<string> dq;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (str.compare("size") == 0) {
            cout << dq.size() << '\n';
        } else if (str.compare("back") == 0) {
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        } else if (str.compare("empty") == 0) {
            if (dq.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if (str.compare("front") == 0) {
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        } else if (str.compare("pop_front") == 0) {
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        } else if (str.compare("pop_back") == 0) {
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        } else if (str.compare("push_back") == 0) {
            string num;
            cin >> num;
            dq.push_back(num);
        } else if (str.compare("push_front") == 0) {
            string num;
            cin >> num;
            dq.push_front(num);
        }
    }
}