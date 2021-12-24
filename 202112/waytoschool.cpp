#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));

    for(int i=0;i<puddles.size();i++){
        int a=puddles[i][0];
        int b=puddles[i][1];
        dp[b][a]=-1;
    }
    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dp[i][j]==-1){
                continue;
            }
            int n1=0;
            int n2=0;
            if(dp[i-1][j]!=-1){
                n1=dp[i-1][j];
            }
            if(dp[i][j-1]!=-1){
                n2=dp[i][j-1];
            }
            dp[i][j]+=(n1+n2)%1000000007;
        }
    }
    answer=dp[n][m];

    return answer;
}