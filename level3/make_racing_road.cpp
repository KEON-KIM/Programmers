#include <cstring>
#include <climits>
#include <vector>
#include <iostream>
#include <queue>

#define MAX 26
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;
typedef pair<int, int> pii;
int solution(vector<vector<int>> board) {
    int answer = INT_MAX;
    int costboard[MAX][MAX][4];
    memset(costboard, 0x3f, sizeof(costboard));
    int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    queue<pair<int, pii>> Que;
    Que.push({0, {0, 0}});
    Que.push({2, {0, 0}});

    costboard[0][0][0] = 0;
    costboard[0][0][2] = 0;
    while(!Que.empty())
    {
        int dir = Que.front().first;
        int x = Que.front().second.first;
        int y = Que.front().second.second;
        Que.pop();

        if(x == board.size()-1 && y == board[0].size()-1) continue;
        FOR(i, 4)
        {
            int dx = x + dxdy[i][0];
            int dy = y + dxdy[i][1];
            int cost = costboard[x][y][dir] + (dir==i?100:600);

            if(dx < 0 || dy < 0 || dx >= board.size() || dy >= board[0].size()) continue;
            if(cost > costboard[dx][dy][i] || board[dx][dy] ) continue;
            costboard[dx][dy][i] = cost;
            Que.push({i, {dx, dy}});
        }
    }

    FOR(i, 4)
        answer = min(answer, costboard[board.size()-1][board[0].size()-1][i]);

    return answer;

}


int main()
{
    vector<vector<int>> board
        // = {{0, 0, 0, 0, 0, 0, 0, 0},
        //    {1, 0, 1, 1, 1, 1, 1, 0},
        //    {1, 0, 0, 1, 0, 0, 0, 0},
        //    {1, 1, 0, 0, 0, 1, 1, 1},
        //    {1, 1, 1, 1, 0, 0, 0, 0}, 
        //    {1, 1, 1, 1, 1, 1, 1, 0}, 
        //    {1, 1, 1, 1, 1, 1, 1, 0}, 
        //    {1, 1, 1, 1, 1, 1, 1, 0}};

        = {{0,0,0},{0,0,0},{0,0,0}};
        // = {{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0}};
        // = {{0,0,1,0},{0,0,0,0},{0,1,0,1},{1,0,0,0}};
        // = {{0,0,0,0,0,0},{0,1,1,1,1,0},{0,0,1,0,0,0},{1,0,0,1,0,1},{0,1,0,0,0,1},{0,0,0,0,0,0}};

    cout << solution(board);
    return 0;
}