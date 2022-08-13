#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define MAX 1002
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

bool windowSlide(int x, int y, int s, vector<vector<int>> &board)
{
    for(int i = x; i < x + s; i++)
    {
        for(int j = y; j < y + s; j++)
        {
            if(!board[i][j])
                return false;
        }
    }
    return true;
}
int solution(vector<vector<int>> board)
{
    int dp[MAX][MAX];
    int n = board.size(), m = board[0].size();
    int answer = 0;
    // INIT;
    FOR(i, n)
        FOR(j, m)
            dp[i][j] = board[i][j];

    FOR(i, n)
        FOR(j, m)
        {
            if(i < 1 || j < 1) continue;
            if(board[i-1][j-1])
            {
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                answer = max(answer, dp[i][j]);
            }
        }

    return answer*answer;

}

int main()
{
    vector<vector<int>> board
        // = {{0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0}};
        = {{0,0,1,1},{1,1,1,1}};
    cout << solution(board);
    return 0;
}