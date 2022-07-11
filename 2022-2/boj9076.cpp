#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> vec(5, 0);
        for (int j = 0; j < 5; j++) {
            cin >> vec[j];
        }
        sort(vec.begin(), vec.end());
        if (vec[3] - vec[1] >= 4) {
            cout << "KIN\n";
        } else {
            cout << vec[1] + vec[2] + vec[3] << '\n';
        }
    }
}