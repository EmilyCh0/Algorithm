#include "iostream"
#include "vector"

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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int kg, ks, kb;
    vector<Country> vec;
    for (int i = 0; i < n; i++) {
        int num, g, s, b;
        cin >> num >> g >> s >> b;
        vec.push_back(Country(num, g, s, b));
        if (num == k) {
            kg = g;
            ks = s;
            kb = b;
        }
    }
    int rating = 1;
    for (int i = 0; i < n; i++) {
        Country now = vec[i];
        if (now.num == k)
            continue;
        if (now.g > kg || (now.g == kg && now.s > ks) || (now.g == kg && now.s == ks && now.b > kb)) {
            rating++;
        }
    }
    cout << rating;
}



