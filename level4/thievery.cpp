#include <cstring>
#include <vector>
#include <iostream>

#define MAX 1000010
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N;
int dfs(int idx, vector<int> &money, int dp[MAX])
{
    if(idx > N) return 0;
    int &ref = dp[idx];
    if(ref != -1) return ref;
    ref = max(dfs(idx+2, money, dp) + money[idx], dfs(idx+1, money, dp));
    return ref;
}

int solution(vector<int> money) {
    int answer = 0;
    int dp[2][MAX];
    N = money.size()-1;

    memset(dp, -1, sizeof(dp));
    dp[1][N] = 0;
    dp[0][N] = money[N];
    answer = max(dfs(0, money, dp[1]), dfs(1, money, dp[0]));

    return answer;
}


int main()
{
    vector<int> money
        // = {1,2,3,1};
        = {1, 4, 5, 3, 11, 1, 8, 10};
    cout << solution(money);
    return 0;
}