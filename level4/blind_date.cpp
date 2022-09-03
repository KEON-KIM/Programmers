#include <vector>
#include <cstring>
#include <iostream>
#include <queue>

#define MAX 51
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;
// bfs접근
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
typedef pair<long, long> pll;
typedef long long ll;
int M, N;
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll visited[MAX][MAX][4];
void print(vector<vector<int>> &time_map)
{
    for(vector<int> v : time_map)
    {
        for(int i : v)
            cout << i << " ";
        cout<<endl;
    }
    cout << "======VISITED======" << endl;
    FOR(i, M)
    {
        FOR(j, N)
            cout << visited[i][j] << " ";
        cout << endl;
    }
}
pll bfs(vector<vector<int>> &time_map, int maxTime)
{
    queue<pair<pll, pll>> Que;
    priority_queue<pll, vector<pll>, greater<pll>> pQue;
    memset(visited, 0x7f, sizeof(visited));
    Que.push({{0, 0}, {0, 0}});
    while(!Que.empty())
    {
        ll move = Que.front().first.first;
        ll cur = Que.front().first.second;
        ll x = Que.front().second.first;
        ll y = Que.front().second.second;
        Que.pop();

        cout << "=================" << endl;
        cout << move << "/" << cur << "/" <<  x << "/" <<  y << endl;
        print(time_map);
        if(x == M-1 && y == N-1 && cur <= maxTime)
            pQue.push({move, cur}); 
        // time_map[x][y] = -1; // 지나왔다고 체크
        FOR(i, 4)
        {
            ll dx = x + dxdy[i][0];
            ll dy = y + dxdy[i][1];

            if(dx >= M || dy >= N || dx < 0 || dy < 0)continue;
            if(time_map[dx][dy] == -1) continue;
            if(visited[dx][dy][i] > cur + time_map[dx][dy])
            {
                visited[dx][dy][i] = cur + time_map[dx][dy];
                Que.push({{move+1, cur + time_map[dx][dy]}, {dx, dy}});
            }
        }
    }
    return pQue.top();
}
vector<int> solution(int m, int n, int s, vector<vector<int>> time_map) {
    M = m; N = n;
    pll p = bfs(time_map, s);
    vector<int> answer(2);

    answer[0] = p.first;
    answer[1] = p.second;
    
    return answer;
}

int main()
{
    vector<vector<int>> time_map 
        // = {{0, 2, 99}, {100, 100, 4}, {1, 2, 0}};
        // = {{0, 1, 1, -1, 2, 4}, {-1, 7, 2, 1, 5, 7}, {-1, 1, -1, 1, 6, 3}, {-1, 1, -1, -1, 7, 0}};
        = {{0, 1, 1, 1, 1}, {9, 9, 9, 1, 9}, {1, 1, 1, 1, 9}, {1, 1, 5, 9, 9}, {1, 1, 1, 1, 0}};
    vector<int> answer = solution(5, 5, 12, time_map);
    cout << answer[0] << "/" << answer[1] << endl;
    return 0;
}