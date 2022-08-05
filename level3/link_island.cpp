#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>

#define MAX 101
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

// kruskal
typedef pair<int, int> pii;
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<pii> board[MAX];
    bool visited[MAX] = {false, };
    for(vector<int> v : costs)
    {
        board[v[0]].push_back({v[1], v[2]});
        board[v[1]].push_back({v[0], v[2]});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pQue; //cost, next
    pQue.push({0, 0});

    while(!pQue.empty())
    {
        int cost = pQue.top().first;
        int cur = pQue.top().second;
        pQue.pop();

        if(!visited[cur])
        {
            visited[cur] = true;
            answer += cost;

            for(pii p : board[cur])
            {
                int nextCost = p.second;
                int next = p.first;

                if(!visited[next])
                    pQue.push({nextCost, next});
            }
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> costs  
        = {{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}};
    cout << solution(4, costs);
    return 0;
}