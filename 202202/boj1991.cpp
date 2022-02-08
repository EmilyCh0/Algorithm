#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

struct node{
    char me, left, right;
};

vector<node> vec;

string prefix() {
    string ans = "A";
    stack<node> sta;
    sta.push(vec[0]);
    vector<bool> visit(vec.size(), false);

    while (!sta.empty()) {
        node now = sta.top();
        if (now.left != '.' && !visit[now.left - 'A']) {
            sta.push(vec[now.left - 'A']);
            ans += vec[now.left - 'A'].me;
        } else {
            if (now.right != '.' && !visit[now.right - 'A']) {
                visit[now.me - 'A'] = true;
                sta.pop();
                sta.push(vec[now.right - 'A']);
                ans += vec[now.right - 'A'].me;
            } else {
                visit[now.me - 'A'] = true;
                sta.pop();
            }
        }
    }
    return ans;
}

string infix() {
    string ans = "";
    stack<node> sta;
    sta.push(vec[0]);
    vector<bool> visit(vec.size(), false);

    while (!sta.empty()) {
        node now = sta.top();
        if (now.left != '.' && !visit[now.left - 'A']) {
            sta.push(vec[now.left - 'A']);
        } else {
            ans += now.me;
            if (now.right != '.' && !visit[now.right - 'A']) {
                visit[now.me - 'A'] = true;
                sta.pop();
                sta.push(vec[now.right - 'A']);
            } else {
                visit[now.me - 'A'] = true;
                sta.pop();
            }
        }
    }
    return ans;
}

string postfix() {
    string ans = "";
    stack<node> sta;
    sta.push(vec[0]);
    vector<bool> visit(vec.size(), false);

    while (!sta.empty()) {
        node now = sta.top();
        if (now.left != '.' && !visit[now.left - 'A']) {
            sta.push(vec[now.left - 'A']);
        } else {
            if (now.right != '.' && !visit[now.right - 'A']) {

                sta.push(vec[now.right - 'A']);
            } else {
                ans += now.me;
                visit[now.me - 'A'] = true;
                sta.pop();
            }
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vec.resize(n);
    for (int i = 0; i < n; i++) {
        char m, l, r;
        cin >> m >> l >> r;
        struct node nn = {m, l, r};
        vec[m - 'A'] = nn;
    }
    cout << prefix() << '\n';
    cout << infix() << '\n';
    cout << postfix();

    return 0;
}
