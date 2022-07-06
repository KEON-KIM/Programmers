#include <iostream>
#include <string>
#include <vector>

#define MAX 201
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

bool visited[MAX];
void dfs(int idx, vector<vector<int>> computers)
{
    FOR(i, computers[idx].size())
    {
        if(computers[idx][i] && !visited[i])
        {
            visited[i] = true;
            dfs(i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    FOR(i, n)
    {
        if(!visited[i])
        {
            answer++;
            visited[i] = true;
            dfs(i, computers);
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> computers
        = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
        // = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
    cout << solution(3, computers);
    return 0;
}