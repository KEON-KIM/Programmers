#include <iostream>
#include <string>
#include <vector>

#define MAX 10001
using namespace std;

int solution(int n) {
    int answer = 0;
    int dp[MAX] = {0, };
    for(int i = 1; i <= n; i++)
    {
        dp[i]++;
        int idx = i;
        cout << "I : " << i << endl;
        for(int j = i+1; idx < n; j++)
        {
            idx += j;
            dp[idx]++;
            cout << "J : " << j << endl;
            cout << "IDX : " << idx << endl;
        }
    }

    answer = dp[n]; 
    return answer;
}

int main()
{
    cout << solution(15);
    return 0;
}