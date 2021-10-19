#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    int n;
    const int DIV=1000000000;
    cin>>n;
    vector<vector<int>> dp(n,vector<int>(10,0));
    dp[0][0]=0;
    dp[0][1]=dp[0][2]=dp[0][3]=dp[0][4]=dp[0][5]=dp[0][6]=dp[0][7]=dp[0][8]=dp[0][9]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<10;j++){
            if(j==0){
                dp[i][j]=dp[i-1][j+1]%DIV;
            }
            else if(j==9){
                dp[i][j]=dp[i-1][j-1]%DIV;
            }
            else{
                long long tmp=dp[i-1][j+1]+dp[i-1][j-1];
                dp[i][j]=tmp%DIV;
            }
        }
    }
    long long sum=0;
    for(int i=0;i<10;i++){
        sum+=dp[n-1][i];
    }
    sum%=DIV;
    cout<<sum;

    return 0;
}

