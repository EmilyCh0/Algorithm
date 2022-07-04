#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    vector<vector<int>> vec(n+1);
    for(int i=0;i<edge.size();i++){
        int a = edge[i][0];
        int b = edge[i][1];
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    vector<bool> visit(n+1, false);

    queue<pair<int, int>> que;
    que.push(make_pair(1,0));
    visit[1] = true;
    int maxLen = 0;
    while(!que.empty()){
        pair p = que.front();
        que.pop();
        int now = p.first;
        int cnt = 0;

        for(int i=0;i<vec[now].size();i++){
            int next = vec[now][i];

            if(visit[next]){
                continue;
            }
            que.push(make_pair(next, p.second+1));
            visit[next]=true;
            cnt++;
        }
        if(cnt==0){
            if(maxLen == p.second){
                answer++;
            }else if(maxLen < p.second){
                answer=1;
                maxLen = p.second;
            }
        }
    }

    return answer;
}