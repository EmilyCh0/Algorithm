#include <iostream>
#include <vector>

using namespace std;

int boj1446(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, D, s, e, dist;
    cin>>N>>D;
    vector<int> vec(D+1,10001);
    vector<pair<int,int>> shortcut[10001];

    for(int i=0;i<N;i++){
        cin>>s>>e>>dist;
        if(e-s<=dist||e>D){  // 지름길이 아닌 경우, 도착지 e가 최종 목적지보다 큰 경우
            continue;
        }
        shortcut[e].push_back(make_pair(s,dist));
    }
    for(int i=0;i<D+1;i++){
        vec[0]=0;
        for(int i=1;i<=D;i++){
            if(shortcut[i].size()==0){ // 지름길이 없으면
                vec[i]=vec[i-1]+1;
            }else{
                for(int j=0;j<shortcut[i].size();j++){
                    vec[i]=min(vec[i],min(vec[i-1]+1,vec[shortcut[i][j].first]+shortcut[i][j].second));
                }
            }
        }
    }
    cout<<vec[D];
    return 0;
}

