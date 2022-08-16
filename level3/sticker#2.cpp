#include <vector>
#include <iostream>

#define MAX 100001
using namespace std;

int solution(vector<int> sticker)
{   
    int dp[MAX];
    int answer = -1;
    int n = sticker.size();
    
    if (sticker.size() == 1)
        return sticker[0];
    
    // first sticker detach
    dp[0] = sticker[0];
    dp[1] = dp[0];
    for(int i = 2; i < n - 1; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
        answer = max(answer, dp[i]);
    }

    // last sticker detach
    dp[n - 1] = dp[n - 2];
    dp[0] = 0;
    for(int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2 < 0 ? 0 : i - 2] + sticker[i]);
        answer = max(answer, dp[i]);
    }
    
    return answer;
}

int main()
{
    vector<int> sticker = {14, 6, 5, 11, 3, 9, 2, 10};
    cout << solution(sticker);
    return 0;
}