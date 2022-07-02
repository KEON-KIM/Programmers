#include <string>
#include <vector>
#include <iostream>

#define MAX 100001
#define MOD 1234567
#define FOR(i, n) for(int i = 2; i <= n; i++)
using namespace std;

int dp[MAX] = {0, };
int solution(int n) {
    int answer = 0;
    dp[1] = 1;
    FOR(i, n)
        dp[i] = (dp[i-1] + dp[i-2])%MOD; 
    
    answer = dp[n];
    return answer;
}

int main()
{
    cout << solution(5);
    return 0;
}