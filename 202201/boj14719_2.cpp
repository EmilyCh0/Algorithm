#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    vector<int> vec(w);
    for (int i = 0; i < w; i++) {
        cin >> vec[i];
    }
    vector<pair<int, int>> rain(w);
    int leftH = 0;
    int rightH = 0;
    for (int i = 0; i < w; i++) {
        leftH = max(leftH, vec[i]);
        rightH = max(rightH, vec[w - i - 1]);
        rain[i].first = leftH;
        rain[w - i - 1].second = rightH;
    }
    int sum = 0;
    for (int i = 0; i < w; i++) {
        int minval = min(rain[i].first, rain[i].second);
        sum += minval - vec[i];
    }
    cout << sum;

    return 0;
}
