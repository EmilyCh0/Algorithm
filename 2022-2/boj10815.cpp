#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

vector<int> vec;
int n;

int check(int num) {
    int s = 0;
    int e = n;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (vec[mid] == num) {
            return 1;
        } else if (vec[mid] <= num) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vec.resize(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        cout << check(tmp) << ' ';
    }
}