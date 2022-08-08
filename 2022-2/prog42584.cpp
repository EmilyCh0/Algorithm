// lv2 주식가격
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n);
    stack<int> sta;

    for(int idx=0;idx<n;idx++){
        while(!sta.empty()&&prices[sta.top()]>prices[idx]){
            answer[sta.top()] = idx-sta.top();
            sta.pop();
        }
        sta.push(idx);
    }
    while(!sta.empty()){
        answer[sta.top()] = n - sta.top() - 1;
        sta.pop();
    }
    return answer;
}

// vector<int> solution(vector<int> prices) {
//     vector<int> answer;
//     int n = prices.size();
//     for(int i=0;i<n;i++){
//         int p = prices[i];
//         for(int j=i+1;j<n;j++){
//             if(prices[j]<p||j==n-1){
//                 answer.push_back(j-i);
//                 break;
//             }
//         }
//     }
//     answer.push_back(0);
//     return answer;
// }