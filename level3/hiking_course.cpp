#include <cstring>
#include <vector>
#include <iostream>
#include <queue>

#define MAX 1001
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef pair<int, int> pii;

int dist[MAX];
vector<pii> board[MAX];
bool isSummit(int cur, vector<int> &summits)
{
    for(int i : summits)
        if(cur == i) return true;
    return false;
}

int bfs(int start, vector<int> &summits)
{
    queue<int> Que; // dist, next;    

    Que.push(start);
    while(!Que.empty())
    {
        int cur = Que.front();
        Que.pop();
        cout << cur << endl;

        if(isSummit(cur, summits)) continue;
        for(pii p : board[cur])
        {
            int next = p.first;
            int nextCost = p.second;
            cout << "NEXT : " << next << endl;
            if(dist[next] > max(dist[cur], nextCost))
            {
                Que.push(next);
                dist[next] = max(dist[cur], nextCost);
            }
        }
    }
    return -1;
}
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    FOR(i, paths.size())
    {
        board[paths[i][0]].push_back({paths[i][1], paths[i][2]}); // {dest, dist}
        board[paths[i][1]].push_back({paths[i][0], paths[i][2]}); // 
    }
    memset(dist, 0x3f, sizeof(dist));
    int min_intensity = 1e9;
    int min_summit = -1;

    FOR(i, gates.size())
        dist[gates[i]] = 0;

    FOR(i, gates.size())
        bfs(gates[i], summits);

    for(int summit : summits)
    {
        if(min_intensity > dist[summit]) 
        {
            min_intensity = dist[summit];
            min_summit = summit;
        }
        else if(min_intensity == dist[summit] && min_summit > summit)
            min_summit = summit;
    }
    FOR(i, n)
        cout << dist[i] << " ";
    cout << endl;

    answer.push_back(min_summit);
    answer.push_back(min_intensity);
    return answer;
}

int main()
{
    vector<vector<int>> paths
        // = {{1, 2, 3}, {2, 3, 5}, {2, 4, 2}, {2, 5, 4}, {3, 4, 4}, {4, 5, 3}, {4, 6, 1}, {5, 6, 1}};
        = {{1, 4, 4}, {1, 6, 1}, {1, 7, 3}, {2, 5, 2}, {3, 7, 4}, {5, 6, 6}};
        // = {{1, 2, 5}, {1, 4, 1}, {2, 3, 1}, {2, 6, 7}, {4, 5, 1}, {5, 6, 1}, {6, 7, 1}};
        // = {{1, 3, 10}, {1, 4, 20}, {2, 3, 4}, {2, 4, 6}, {3, 5, 20}, {4, 5, 6}};

    vector<int> gates 
        // = {1, 3};
        = {1};
        // = {3, 7};
        // = {1, 2};

    vector<int> summits
        // = {5};
        = {2, 3, 4};
        // = {1, 5};
        // = {5};

    vector<int> answer = solution(7, paths, gates, summits);
    cout << answer[0] << "|" << answer[1];
    return 0;
}

/*#include <string>
#include <vector>
#include <iostream>
#include <queue>

#define MAX 50002
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef pair<int, int> pii;

vector<pii> board[MAX];
int bfs(int start, int dest, bool visited[])
{
    priority_queue<pii, vector<pii>, greater<pii>> pQue; // dist, next; 
    

    int intensity = -1;
    pQue.push({0, start});
    while(!pQue.empty())
    {
        int cur = pQue.top().second;
        int cost = pQue.top().first;
        pQue.pop();
        
        intensity = max(intensity, cost);
        visited[cur] = true;
        if(cur == dest) return intensity;

        for(pii p : board[cur])
        {
            int next = p.first;
            int nextCost = p.second;

            if(!visited[next])
            {
                pQue.push({nextCost, next});
            }
        }
    }
    return -1;
}
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    FOR(i, paths.size())
    {
        board[paths[i][0]].push_back({paths[i][1], paths[i][2]}); // {dest, dist}
        board[paths[i][1]].push_back({paths[i][0], paths[i][2]}); // 
    }
    int intensity = 1e9, dest;
    FOR(i, gates.size())
    {
        FOR(j, summits.size())
        {
            bool visited[MAX] = {false, };
            FOR(k, summits.size()) if(j!=k)visited[summits[k]] = true;
            int tmp = bfs(gates[i], summits[j], visited);
            
            if(intensity > tmp)
            {
                intensity = tmp;
                dest = summits[j];
            }
            else if(intensity == tmp && summits[j] < dest)
                dest = summits[j];
        }
    }
    answer.push_back(dest);
    answer.push_back(intensity);
    return answer;
}*/