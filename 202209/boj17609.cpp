// Created by Emily Cho on 2022/09/07.
// 17609 회문 (골5)

#include <iostream>

using namespace std;

bool isPalindrome(string str) {
    int l = 0;
    int r = str.size() - 1;
    while (true) {
        if (l >= r) return true;
        if (str[l] == str[r]) {
            l++;
            r--;
        } else return false;
    }
}

int check(string str) {
    int left = 0;
    int right = str.size() - 1;
    while (true) {
        if (left >= right) return 0;
        if (str[left] == str[right]) {
            left++;
            right--;
        } else if (left + 1 < right && (str[left] == str[right - 1] || str[left + 1] == str[right])) {
            if (left + 2 == right) return 1;
            bool flag = isPalindrome(str.substr(left, right - left));
            if (flag) return 1;
            flag = isPalindrome(str.substr(left + 1, right - left));
            if (flag) return 1;
            else return 2;
        } else if (left + 1 == right) {
            return 1;
        } else {
            return 2;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        int res = check(str);
        if (res == 0) cout << 0 << '\n';
        else if (res == 1) cout << 1 << '\n';
        else cout << 2 << '\n';
    }

    return 0;
}
