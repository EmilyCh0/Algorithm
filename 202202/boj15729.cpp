#include "iostream"
#include "vector"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, inp;
    cin >> n;
    vector<bool> vec(1000001);
    vector<bool> light(1000001);
    for (int i = 0; i < n; i++) {
        cin >> inp;
        vec[i] = inp != 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (vec[i] != light[i]) {
            cnt++;
            light[i + 1] = !light[i + 1];
            light[i + 2] = !light[i + 2];
        }
    }
    cout << cnt;

    return 0;
}