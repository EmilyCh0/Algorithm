#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    auto truck = truck_weights.begin();
    int weightSum = 0;
    queue<int> que;
    while (true) {
        if (truck_weights.size() == 0) {
            answer += bridge_length;
            break;
        }
        answer++;
        if (que.size() == bridge_length) {
            weightSum -= que.front();
            que.pop();
        }
        if (weightSum + *truck <= weight) {
            weightSum += *truck;
            que.push(*truck);
            truck = truck_weights.erase(truck);
        } else que.push(0);
    }
    return answer;
}