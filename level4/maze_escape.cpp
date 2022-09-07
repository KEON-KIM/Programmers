#include <cstring>
#include <vector>
#include <queue>
#include <iostream>

#define MAX 1002
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, bool> pib;

int dist[MAX][2];
bool trapInfo[MAX] = {false, };
bool visited[MAX] = {false, };
int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) 
{
    int answer = 1 << 31 -1;
    vector<pii> ori_roads[MAX], trap_roads[MAX];
    FOR(i, roads.size())
    {
        ori_roads[roads[i][0]].push_back({roads[i][1], roads[i][2]});
        trap_roads[roads[i][1]].push_back({roads[i][0], roads[i][2]});
    }
    FOR(i, traps.size())
        trapInfo[traps[i]] = true;
    memset(dist, 0x7f, sizeof(dist));
    priority_queue<pii, vector<pii>, greater<pii>> pQue;// {cost, {next, onTrap}}
    //visited[start] = true;
    // dist[start][1] = 0;
    // dist[start][0] = 0;
    pQue.push({0, start});
    while(!pQue.empty())
    {
        int cost = pQue.top().first;
        int cur = pQue.top().second;
        pQue.pop();
        
        if(cur == end) answer = min(answer, cost);
        if(trapInfo[cur] && !visited[cur])
        { 
            for(pii p : trap_roads[cur])
            {  
                int next = p.first;
                int nextCost = cost + p.second;
                if(dist[next][visited[next]] > nextCost)
                {
                    dist[next][visited[next]] = nextCost;
                    pQue.push({nextCost, next});
                }
            }
        }
        else
        {
            for(pii p : ori_roads[cur])
            {
                int next = p.first;
                int nextCost = cost + p.second;
                if(dist[next][visited[next]] > nextCost)
                {
                    dist[next][visited[next]] = nextCost;
                    pQue.push({nextCost, next});
                }
            }
        }
        //visited[cur] = !visited[cur];
    }
    
    return answer;
}

int main()
{
    vector<vector<int>> roads
        // = {{1, 2, 2}, {3, 2, 3}};
        = {{1, 2, 1}, {3, 2, 1}, {2, 4, 1}};
        // = {{1, 2, 1}, {2, 3, 1}, {3, 2, 1}, {3, 5, 1}, {1, 5, 10}};
    vector<int> traps
        // = {2};
        = {2, 3};

    // cout << solution(3, 1, 3, roads, traps);
    cout << solution(4, 1, 4, roads, traps);
    // cout << solution(5, 1, 5, roads, traps);
    return 0;
}