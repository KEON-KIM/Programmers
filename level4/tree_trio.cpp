#include <cstring>
#include <vector>
#include <iostream>

#define MAX 250002
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef pair<int, int> pii;
vector<int> graph[MAX];
bool visited[MAX] = {false, };
int child, maxLen, cnt; 
void dfs(int cur, int len, bool flag)
{
    if(visited[cur]) return;
    if(!flag)
    {
        if(len > maxLen)
        {
            maxLen = len;
            child = cur; 
        }
    }
    else
    {
        if(len > maxLen)
        {
            maxLen = len;
            child = cur;
            cnt = 1;
        }
        else if(len == maxLen) cnt++;
    }
    visited[cur] = true;
    FOR(i, graph[cur].size())
        dfs(graph[cur][i], len+1, flag);
}

void sol(int c, bool flag)
{
    cnt = 0;
    maxLen = 0;
    memset(visited, false, sizeof(visited));

    dfs(c, 0, flag);
}

int solution(int n, vector<vector<int>> edges) {
    FOR(i, edges.size())
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    sol(1, false);
    sol(child, true);
    if(cnt >= 2) return maxLen;
    else
    {
        sol(child, n, true);
        if(cnt >= 2) return maxLen;
        else return maxLen - 1;
    }
}

int main()
{
    vector<vector<int>> edges
        = {{1,2},{2,3},{3,4}};
        // = {{1,5},{2,5},{3,5},{4,5}};

    cout << solution(4, edges);
    return 0;
}