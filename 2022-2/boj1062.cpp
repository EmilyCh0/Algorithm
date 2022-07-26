#include "iostream"
#include "vector"

using namespace std;

int n, m;
int ans = 0;

vector<string> words;
vector<char> letters;
vector<bool> alphabet;

int countReadableWords() {
    int cnt = 0;
    for (string w: words) {
        bool flag = true;
        for (char ch: w) {
            if (!alphabet[ch - 'a']) {
                flag = false;
                break;
            }
        }
        if (flag)
            cnt++;
    }
    return cnt;
}

void selectLetters(int idx, int cnt) {
    if (cnt == m || cnt >= letters.size()) {
        ans = max(ans, countReadableWords());
        return;
    }
    for (int i = idx; i < letters.size(); i++) {
        if (!alphabet[letters[i] - 'a']) {
            alphabet[letters[i] - 'a'] = true;
            selectLetters(i, cnt + 1);
            alphabet[letters[i] - 'a'] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    alphabet.assign(26, false);
    alphabet['a' - 'a'] = true;
    alphabet['n' - 'a'] = true;
    alphabet['t' - 'a'] = true;
    alphabet['i' - 'a'] = true;
    alphabet['c' - 'a'] = true;
    m -= 5;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        words.push_back(str.substr(4, str.size() - 8));
        for (int j = 4; j < str.size() - 3; j++) {
            if (!alphabet[str[j] - 'a']) {
                letters.push_back(str[j]);
                alphabet[str[j] - 'a'] = true;
            }
        }
    }
    for (char ch: letters) {
        alphabet[ch - 'a'] = false;
    }

    if (m < 0) {
        cout << 0;
        return 0;
    } else if (m == 0) {
        cout << countReadableWords();
        return 0;
    } else if (m >= letters.size()) {
        cout << n;
        return 0;
    }

    selectLetters(0, 0);

    cout << ans;
    return 0;
}