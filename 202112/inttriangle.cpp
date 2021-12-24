#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {

    int n = triangle.size();
    int answer = 0;

    vector<vector<int>> dp(n, vector<int>(n,0));

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < i + 1;j++) {
            if (j == 0 && i == 0) {
                dp[i][j] = triangle[i][j];
            }
            else if (j == 0) {
                dp[i][j] = triangle[i][j] + dp[i - 1][j];
            }
            else if (j == i) {
                dp[i][j] = triangle[i][j] + dp[i - 1][j-1];
            }
            else {
                dp[i][j] = max(triangle[i][j] + dp[i - 1][j-1], triangle[i][j] + dp[i - 1][j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(dp[n-1][i]>answer){
            answer = dp[n-1][i];
        }
    }

    return answer;
}