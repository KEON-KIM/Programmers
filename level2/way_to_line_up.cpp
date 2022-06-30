#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
vector<int> solution(int n, ll k) {
    vector<int> answer;
    ll dp[21] = {0, };
    vector<int> visited;
    for(int i = 1; i <= n; i++)
        visited.push_back(i);

    dp[1] = 1;
    for(int i = 2; i <= n; i++)
        dp[i] = dp[i-1] * i;

    for(int i = n; i > 1; i--)
    {
        if(k%dp[i-1]) // 0으로 안나눠 질 때 
        {
            ll idx = k/dp[i-1];
            answer.push_back(visited[idx]);
            visited.erase(visited.begin()+idx);
            k-= (idx) * dp[i-1];
        }
        else // 0으로 나눠질때 
        {
            ll idx = k/dp[i-1]-1;
            answer.push_back(visited[idx]);
            visited.erase(visited.begin()+idx);
            k-= (idx) * dp[i-1];
        }
    }
    if(visited.size() > 0)
        answer.push_back(visited[0]);
    return answer;
}

int main()
{
    vector<int> answer = solution(20, 1343498412);
    for(int i : answer)
        cout << i << " ";
    cout << endl;
}