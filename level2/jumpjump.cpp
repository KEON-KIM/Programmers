#include <iostream>
#include <string>
#include <vector>

#define MAX 2001
#define MOD 1234567

using namespace std;

typedef long long ll;
ll solution(int n) {
    ll dp[MAX];
    ll answer = 0;

    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++)
        dp[i] = (dp[i-1] + dp[i-2])%MOD;
    
    answer = dp[n];
    return answer;
}

int main()
{
    cout << solution(4);
    return 0;
}