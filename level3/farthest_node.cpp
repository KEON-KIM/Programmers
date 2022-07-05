#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define MAX 20002
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int distance[MAX];
    bool visited[MAX];
    vector<int> board[MAX];

    // Init;
    for(vector<int> v : edge)
    {
        board[v[0]].push_back(v[1]);
        board[v[1]].push_back(v[0]);
    }

    //Bfs
    int idx = -1;
    queue<pair<int, int>> Que;
    Que.push({1, 0});
    visited[1] = true;
    while(!Que.empty())
    {
        int node = Que.front().first;
        int dist = Que.front().second;
        Que.pop();

        distance[dist]++;
        idx = max(idx, dist);
        for(int i : board[node])
        {
            if(!visited[i])
            {
                visited[i] = true;
                Que.push({i, dist+1});
            }
        }
    }

    answer = distance[idx];
    return answer;
}

int main()
{
    vector<vector<int>> edge 
        = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
    cout << solution(6, edge);
    return 0;
}