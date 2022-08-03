#include <cstring>
#include <vector>
#include <iostream>
#include <climits>
#include <queue>

#define MAX 202
#define INF 123456789
#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;

typedef pair<int, int> pii;
int N;
int Dijikstra(int s, int e, vector<pair<int, int>> graph[])
{
    int dist[N+1] = {INF, };
    //INIT
    FOR(i, N) dist[i] = INF;
    priority_queue<pii, vector<pii>, greater<pii>> pQue; //cost, next;
    pQue.push({0, s});
    dist[s] = 0;
    while(!pQue.empty())
    {
        int cost = pQue.top().first;
        int cur = pQue.top().second;
        pQue.pop();

        for(pair<int, int> p : graph[cur])
        {
            int nextCost = p.first;
            int next = p.second;

            if(cost + nextCost <= dist[next])
            {
                dist[next] = cost + nextCost;
                pQue.push({cost + nextCost, next});
            }
        }
    }

    return dist[e];
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    N = n;
    int answer = INF;
    vector<pair<int, int>> graph[MAX]; // cost, next;
    
    for(vector<int> v : fares)
    {
        graph[v[0]].push_back({v[2], v[1]});
        graph[v[1]].push_back({v[2], v[0]});
    }

    FOR(i, n)
    {
        int cost = 0;
        if(i != s) cost = Dijikstra(s, i, graph);
        if(cost != INF) answer = min(answer, Dijikstra(i, a, graph) + Dijikstra(i, b, graph) + cost);
    }

    return answer;
}

int main()
{
    vector<vector<int>> fares
        // 6, 4, 6, 2
        = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
        // 7, 3, 4, 1
        // = {{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}};
        //6, 4, 5, 6
        // = {{2,6,6}, {6,3,7}, {4,6,7}, {6,5,11}, {2,5,12}, {5,3,20}, {2,4,8}, {4,3,9}};
    cout << solution(6, 4, 6, 2, fares);
    return 0;
}