#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find_parent(int a){
    if(a==parent[a]){
        return a;
    }else{
        return parent[a] = find_parent(parent[a]);
    }
}

void union_group(int a,int b){
    int pa = find_parent(a);
    int pb = find_parent(b);
    if(pa!=pb){
        parent[pb]=pa;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, o, s, e;
    cin >> n >> m;
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> o >> s >> e;
        if (o == 0) {
            union_group(s, e);
        } else {
            if (find_parent(s) == find_parent(e)) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << "\n";
            }
        }
    }

    return 0;
}
