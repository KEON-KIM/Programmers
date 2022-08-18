#include <vector>
#include <iostream>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef pair<int, int> pii;

int N, M;
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool safety(int x, int y) 
{
    return y>=0 && x>=0 && y<M && x<N;
}

bool can_move(vector<vector<int>> &board, int x, int y) 
{
    FOR(i, 4) 
    {
        int dx = x + dxdy[i][0];
        int dy = y + dxdy[i][1];

        if(safety(dx, dy) && board[dx][dy]) return false;
    }

    return true;
}

pair<bool, int> dfs(vector<vector<int>> &board, int x1, int y1, int x2, int y2) {
    if(can_move(board, x1, y1)) return {false, 0}; // 움직일 수 없다면 패배
    
    pair<bool, int> ret = {false, 0};
    if(board[x1][y1]) { // 자신의 발판 있는 경우 -> 없다면 패배 
        int minT = 1e9, maxT = -1;
        FOR(i, 4) {
            int dx = x1 + dxdy[i][0];
            int dy = y1 + dxdy[i][1];
            
            if(!safety(dx, dy) || !board[dx][dy]) continue;
            
            board[x1][y1] = 0;
            auto [win, move]= dfs(board, x2, y2, dx, dy);
            board[x1][y1] = 1;
            
            if(!win) 
            { 
                ret.first = true;
                minT = min(minT, move);
            }
            else if(!ret.first) 
                maxT = max(maxT, move);
        }
        
        ret.second = ret.first ? minT+1 : maxT+1;
    }
    
    return ret;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    N = board.size(), M = board[0].size();
    return dfs(board, aloc[0], aloc[1], bloc[0], bloc[1]).second;
}

int main()
{
    vector<vector<int>> board
        = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
        // = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
        // = {{1, 1, 1, 1, 1}};
        // = {{1}};

    vector<int> aloc
        = {1, 0};
        // = {1, 0};
        // = {0, 0};
        // = {0, 0};

    vector<int> bloc
        = {1, 2};
        // = {1, 2};
        // = {0, 4};
        // = {0, 0};

    cout << solution(board, aloc, bloc);
    return 0;
}