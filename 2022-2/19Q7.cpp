#include <iostream>
#include <list>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        list<char> password;
        password.clear();
        auto cursor = password.end();
        for (char ch: str) {
            if (ch == '<' && cursor != password.begin())
                cursor--;
            else if (ch == '>' && cursor != password.end())
                cursor++;
            else if (ch == '-' && cursor != password.begin())
                cursor = password.erase(--cursor);
            else if (ch != '<' && ch != '>' && ch != '-')
                password.insert(cursor, ch);
        }

        for (auto ch: password) {
            cout << ch;
        }
        cout << '\n';
    }

    return 0;
}