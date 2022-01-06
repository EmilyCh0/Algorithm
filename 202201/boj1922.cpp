#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> parent;
int sum=0;

struct node{
    node(int src, int dst, int cost): src(src), dst(dst), cost(cost){}
    int src;
    int dst;
    int cost;
};
struct comp{
    bool operator()(node n1, node n2){
        return n1.cost > n2.cost;
    }
};

priority_queue<node, vector<node>, comp> pq;

int find_parent(int a) {
    if (parent[a] == a) {
        return a;
    }
    return parent[a] = find_parent(parent[a]);
}


void merge(int a, int b) {
    int pa, pb;
    pa = find_parent(a);
    pb = find_parent(b);
    parent[pa] = pb;
    return;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    parent.resize(10001);
    for (int i = 0; i < n; i++) {
        parent[i + 1] = i + 1;
    }
    for (int i = 0; i < m; i++) {
        int s, d, c;
        cin >> s >> d >> c;
        pq.push(node(s, d, c));
    }
    while (!pq.empty()) {
        int s, d, c;
        s = pq.top().src;
        d = pq.top().dst;
        c = pq.top().cost;
        pq.pop();
        if(find_parent(s)== find_parent(d)){
            continue;
        }
        sum+=c;
        merge(s, d);
    }
    cout << sum;

    return 0;
}

