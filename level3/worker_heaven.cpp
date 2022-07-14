#include <iostream>
#include <vector>

#define MAX 501
#define MOD 20170805
#define pii pair<int, int>
#define FOR(i, n) for(int i = 1; i < n; i++)

using namespace std;

int solution(int m, int n, vector<vector<int>> cm)
{
    int dp[MAX][MAX][4] = { 0 }; // dpp[x][y][dpir]
    if (m == 1 && n == 1)
        return 1;
    FOR(i, m){
        if (cm[i][0] == 1)
            break;
        dp[i][0][2] = 1;  
    }
    
    FOR(i, n){
        if (cm[i][0] == 1)
            break;
        dp[0][i][0] = 1;
    }
    

    FOR(i, m)
    {
        FOR(j, n)
        {
            if (cm[i - 1][j] == 0)
                dp[i][j][2] = (dp[i][j][2] + dp[i - 1][j][0] + dp[i - 1][j][2]) % MOD;
            else if (cm[i - 1][j] == 2) 
                dp[i][j][2] = (dp[i][j][2] + dp[i - 1][j][2]) % MOD;

            if (cm[i][j - 1] == 0)
                dp[i][j][0] = (dp[i][j][0] + dp[i][j - 1][0] + dp[i][j - 1][2]) % MOD;
            else if (cm[i][j - 1] == 2) 
                dp[i][j][0] = (dp[i][j][0] + dp[i][j - 1][0]) % MOD;
        }
    }

    int answer = (dp[m - 1][n - 1][0] + dp[m - 1][n-1][2]) % MOD;
    return answer;
}