#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> parent;
int n;

struct line{
    double dist;
    int src;
    int dst;
};

bool comp(line l1, line l2){
    return l1.dist < l2.dist;
}

int find_parent(int idx){
    if(idx == parent[idx]){
        return idx;
    }else{
        return parent[idx] = find_parent(parent[idx]);
    }
}

bool same_parent(int a, int b){
    int pa = find_parent(a);
    int pb = find_parent(b);
    return pa==pb;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    double a, b;
    double ans = 0;
    cin >> n;
    vector<pair<double, double>> stars;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        stars.push_back(make_pair(a, b));
    }
    vector<line> lines;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double tmp = pow(stars[i].first - stars[j].first, 2) + pow(stars[i].second - stars[j].second, 2);
            tmp = sqrt(tmp);
            line l = {tmp, i, j};
            lines.push_back(l);
        }
    }
    sort(lines.begin(), lines.end(), comp);
    parent.resize(n);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < lines.size(); i++) {
        double cost = lines[i].dist;
        int star1 = lines[i].src;
        int star2 = lines[i].dst;
        if (same_parent(star1, star2) == false) {
            // star1, star2 union
            int pa = find_parent(star1);
            int pb = find_parent(star2);
            parent[pb] = pa;

            ans += cost;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << ans;

    return 0;
}

