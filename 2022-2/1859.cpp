#include<iostream>
#include<vector>

using namespace std;

vector<int> vec;

pair<int, int> findMax(int s, int e) {
    int mx = vec[s];
    int maxIdx = s;
    for (int i = s; i < e; i++) {
        if (mx <= vec[i]) {
            mx = vec[i];
            maxIdx = i;
        }
    }
    return make_pair(mx, maxIdx);
}

int main(int argc, char** argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        int n;
        cin >> n;
        vec.assign(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        int s = 0;
        int e = n;
        long long sum = 0;
        while (true) {
            if (s >= n) {
                break;
            }
            pair<int, int> p = findMax(s, e);
            sum += (long long) (p.second - s) * (long long) p.first;
            for (int i = s; i < p.second; i++) {
                sum -= (long long) vec[i];
            }
            s = p.second + 1;
        }
        cout << "#" << test_case << " " << sum << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}