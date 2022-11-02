#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 100002
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;
typedef pair<int, int> pii;

int result[MAX];
vector<int> graph[MAX];
bool destinations[MAX] = {false, };
void bfs(int start)
{
    bool visited[MAX] = {false, };
    queue<pii> Que; // {cost, cur} 

    Que.push({0, start});
    visited[start] = true;
    while(!Que.empty())
    {
        int cost = Que.front().first;
        int cur = Que.front().second;
        Que.pop();

        if(destinations[cur]) result[cur] = cost;
        FOR(i, graph[cur].size())
        {
            int next = graph[cur][i];

            if(!visited[next])
            {
                visited[next] = true;
                Que.push({cost+1, next});
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    memset(result, -1, sizeof(result));

    FOR(i, roads.size())
    {
        graph[roads[i][0]].push_back(roads[i][1]);
        graph[roads[i][1]].push_back(roads[i][0]);
    }
    FOR(i, sources.size()) destinations[sources[i]] = true;
    
    bfs(destination);
    FOR(i, sources.size())
    {
        answer.push_back(result[sources[i]]);
    }
    return answer;
}

int main()
{
    int n 
        // = 3;
        = 5;
    int destination
        // = 1;
        = 5;
    vector<vector<int>> roads
        // = {{1, 2}, {2, 3}};
        = {{1, 2}, {1, 4}, {2, 4}, {2, 5}, {4, 5}};
    vector<int> sources
        // = {2, 3};
        = {1, 3, 5};
    vector<int> v = solution(n, roads, sources, destination);
    FOR(i, v.size()) cout << v[i] << ' ';
    return 0;
}