#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

// int rxry[4][2] = {{}}
int visited[2][101][101];
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
typedef pair<int, int> pii;
struct drone
{
    // int dir; // 0 : north / 1: east / 2 : south / 3: west
    pii lwing;
    pii rwing;
    drone(pii l, pii r)
    {
        // dir = d;
        lwing = l;
        rwing = r;
    }
};
void print(vector<vector<int>> board, drone d)
{
    board[d.lwing.first][d.lwing.second] = 2;
    board[d.rwing.first][d.rwing.second] = 2;
    cout << "========MAP========" << endl;
    FOR(i, board.size())
    {
        FOR(j, board.size())
        {
            cout << board[i][j] << ' ';
        }cout << endl;
    }
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    int N = board.size();
    queue<pair<int, drone>> Que;
    Que.push({0, drone({0, 0}, {0, 1})});
    while(!Que.empty())
    {
        int cost = Que.front().first;
        drone d = Que.front().second;
        Que.pop();

        // print(board, d);
        if((d.lwing.first == N-1 &&  d.lwing.second == N-1) || (d.rwing.first == N-1 && d.rwing.second == N-1)) {answer = cost; break;}
        FOR(i, 4)
        {
            int lx = d.lwing.first + dxdy[i][0];
            int ly = d.lwing.second + dxdy[i][1];

            int rx = d.rwing.first + dxdy[i][0];
            int ry = d.rwing.second + dxdy[i][1];

            if(lx < 0 || lx >= N || ly < 0 || ly >= N ||
                 rx < 0 || rx >= N || ry < 0 || ry >= N) continue;
            if(board[rx][ry] || board[lx][ly] || (visited[0][lx][ly] && visited[1][rx][ry])) continue; // 벽에 부딪힘 / 이미 왔던 곳
            visited[0][lx][ly] = true;
            visited[1][rx][ry] = true;
            Que.push({cost+1, {{lx, ly}, {rx, ry}}});
        }

        if(d.lwing.first == d.rwing.first) // 누워있음
        {
            // cout << "FUCK" << endl;
            int lx = d.lwing.first;
            int ly = d.lwing.second;
            if(lx-1 >= 0 && ly + 1 < N && !board[lx-1][ly+1] && !board[lx-1][ly]) // 왼쪽 기준 반시계 방향
            {
                int rx = lx-1;
                int ry = ly;
                if(!visited[0][lx][ly] || !visited[1][rx][ry]) 
                {
                    visited[0][lx][ly] = true;
                    visited[1][rx][ry] = true;
                    // cout << "LEFT BASE UNCLOCK" << endl;
                    // cout << lx << '/' << ly << "  :  " << rx << '/' << ry << endl; 
                    // print(board, drone(d.lwing, {rx, ry}));
                    Que.push({cost + 1, drone(d.lwing, {rx, ry})});
                }
            }
            if(lx + 1 < N && ly + 1 < N && !board[lx+1][ly+1] && board[lx+1][ly])
            {
                int rx = lx+1;
                int ry = ly;
                if(!visited[0][lx][ly] || !visited[1][rx][ry]) 
                {
                    visited[0][lx][ly] = true;
                    visited[1][rx][ry] = true;
                    // cout << "LEFT BASE CLOCK" << endl;
                    Que.push({cost + 1, drone(d.lwing, {rx, ry})});
                }
            }

            int rx = d.rwing.first;
            int ry = d.rwing.second;
            if(rx + 1 < N && ry - 1 >= 0 && !board[rx+1][ry-1] && board[rx+1][ry]) //오른쪽 기준 반시계 방향
            {
                lx = rx +1;
                ly = ry;
                if(!visited[0][lx][ly] || !visited[1][rx][ry]) 
                {
                    visited[0][lx][ly] = true;
                    visited[1][rx][ry] = true;
                    // cout << "RIGHT BASE UNCLOCK" << endl;
                    Que.push({cost + 1, drone({lx, ly}, d.rwing)});
                }
            }
            if(rx -1 >= 0 && ry - 1 >= 0 && !board[rx-1][ry-1] && board[rx-1][ry])
            {
                lx = rx-1;
                ly = ry;
                if(!visited[0][lx][ly] || !visited[1][rx][ry]) 
                {
                    visited[0][lx][ly] = true;
                    visited[1][rx][ry] = true;
                    // cout << "RIGHT BASE CLOCK" << endl;
                    Que.push({cost + 1, drone({lx, ly}, d.rwing)});
                }
            }
        }

        if(d.lwing.second == d.rwing.second) // 서있음 
        {
            int lx = d.lwing.first;
            int ly = d.lwing.second;
            if(lx + 1 < N && ly - 1 >= 0 && !board[lx+1][ly-1] && !board[lx][ly-1]) // 왼쪽 기준 시계 방향 
            {
                int rx = lx;
                int ry = ly-1;
                if(!visited[0][lx][ly] || !visited[1][rx][ry]) 
                {
                    visited[0][lx][ly] = true;
                    visited[1][rx][ry] = true;
                    // cout << "LEFT BASE CLOCK" << endl;
                    Que.push({cost + 1, drone(d.lwing, {rx, ry})});
                }
            }
            if(lx + 1 < N && ly + 1 < N && !board[lx+1][ly+1] && !board[lx][ly+1]) // 반시계 방향
            {
                int rx = lx;
                int ry = ly+1;
                if(!visited[0][lx][ly] || !visited[1][rx][ry]) 
                {
                    visited[0][lx][ly] = true;
                    visited[1][rx][ry] = true;
                    // cout << "LEFT BASE UNCLOCK" << endl;
                    Que.push({cost + 1, drone(d.lwing, {rx, ry})});
                }
            }

            int rx = d.rwing.first;
            int ry = d.rwing.second;
            if(rx - 1 >= 0 && ry - 1 >= 0 && !board[rx-1][ry-1] && board[rx][ry-1]) // 반시계 방향
            {
                lx = rx;
                ly = ry-1;
                if(!visited[0][lx][ly] || !visited[1][rx][ry]) 
                {
                    visited[0][lx][ly] = true;
                    visited[1][rx][ry] = true;
                    // cout << "RIGHT BASE UNCLOCK" << endl;
                    Que.push({cost + 1, drone({lx, ly}, d.rwing)});
                }
            }

            if(rx -1 >= 0 && ry + 1 < N && !board[rx-1][ry+1] && board[rx][ry+1]) // 시계 방향
            {
                lx = rx;
                ly = ry+1;
                if(!visited[0][lx][ly] || !visited[1][rx][ry]) 
                {
                    visited[0][lx][ly] = true;
                    visited[1][rx][ry] = true;
                    // cout << "RIGHT BASE CLOCK" << endl;
                    Que.push({cost + 1, drone({lx, ly}, d.rwing)});
                }
            }
        }
        
    }
    return answer;
}

int main()
{
    vector<vector<int>> board
        = {{0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0}};
    cout << solution(board);
    return 0;
}