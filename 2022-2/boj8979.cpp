#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

struct Country {
    Country(int i, int i1, int i2, int i3) {
        this->num = i;
        this->g = i1;
        this->s = i2;
        this->b = i3;
    }

    int num;
    int g;
    int s;
    int b;
};

int cmp(Country a, Country b) {
    if (a.g > b.g) {
        return true;
    } else if (a.g == b.g && a.s > b.s) {
        return true;
    } else if (a.g == b.g && a.s == b.s && a.b > b.b) {
        return true;
    }
    return false;
}

bool isSame(Country a, Country b) {
    if (a.g == b.g && a.s == b.s && a.b == b.b)
        return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<Country> vec;
    for (int i = 0; i < n; i++) {
        int num, g, s, b;
        cin >> num >> g >> s >> b;
        vec.push_back(Country(num, g, s, b));
    }
    sort(vec.begin(), vec.end(), cmp);
    int rate = 0;
    for (int i = 0; i < n; i++) {
        if (vec[i].num == k) {
            rate = i;
            Country found = vec[i];
            for (int j = i - 1; j >= 0; j--) {
                if (isSame(vec[j], found)) {
                    rate = j;
                } else {
                    break;
                }
            }
            break;
        }
    }
    cout << rate + 1;
}

