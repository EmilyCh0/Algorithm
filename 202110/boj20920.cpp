#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<string, int> a, pair<string,int> b){
    if(a.second==b.second&&a.first.length()==b.first.length()){
        // 사전 순
        return a.first < b.first;
    }else if(a.second==b.second){
        // 길이가 길수록
        return a.first.length() > b.first.length();
    }
    // 자주 나올수록
    return a.second > b.second;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin>>N>>M;
    map<string, int> words;
    string tmp;
    for(int i=0;i<N;i++){
        cin>>tmp;
        if(tmp.length()<M){
            continue;
        }else{
            auto iter = words.find(tmp);
            if(iter != words.end()){
                // 존재
                words[tmp]+=1;
            }else{
                words[tmp]=1;
            }
        }
    }
    vector<pair<string, int>> vec(words.begin(), words.end());
    sort(vec.begin(), vec.end(),comp);

    for(int i=0;i<vec.size();i++){
        cout<<vec[i].first<<"\n";
    }

    return 0;
}
