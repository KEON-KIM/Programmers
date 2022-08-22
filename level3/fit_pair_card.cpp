#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef pair<int ,int> pii;
typedef pair<int, pii> pipii;

vector<pii> cardset[7];
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
pipii bfs(int dest, pii start, vector<vector<int>> &board){
    bool visited[4][4] = {0, };
    queue<pipii> Que;
    Que.push({0, {start.first, start.second}});
    visited[start.first][start.second] = true;

    while(!Que.empty()){
        int x = Que.front().second.first;
        int y = Que.front().second.second;
        int cnt = Que.front().first;
        Que.pop();

        if(board[x][y] == dest)
        {
            board[x][y] = 0;
            return {cnt+1, {x, y}}; // Enter : cnt+1
        }
        FOR(i, 4) // move
        {
            int dx = x + dxdy[i][0];
            int dy = y + dxdy[i][1];
            if(dx < 0 || dy < 0 || dx >= 4 || dy >= 4)
                continue;
            if(!visited[dx][dy])
            {
                visited[dx][dy] = true;
                Que.push({cnt+1, {dx, dy}});
            }
        }
        FOR(i, 4) // ctrl + move
        { 
            int dx = x;
            int dy = y;
            while(dx+dxdy[i][0] >= 0 && dy+dxdy[i][1] >= 0 
                    && dx+dxdy[i][0] < 4 && dy+dxdy[i][1] < 4)
            {
                dx += dxdy[i][0];
                dy += dxdy[i][1];
                if(board[dx][dy])
                    break;
            } 
            if(!visited[dx][dy])
            {
                visited[dx][dy] = true;
                Que.push({cnt+1, {dx, dy}});
            }
        }
    }
}

void Init(vector<vector<int>> &board, vector<vector<int>> &tmpBoard)
{
    FOR(i, 4)
        FOR(j, 4)
            tmpBoard[i][j] = board[i][j];
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 1e9;
    vector<int> cards;
    vector<vector<int>> tmpBoard(4, vector<int>(4));
    FOR(i, board.size())
        FOR(j, board[0].size())
            if(board[i][j])
            {
                if(cardset[board[i][j]].size() <= 0)
                    cards.push_back(board[i][j]);
                cardset[board[i][j]].push_back({i, j});
            }
            
    sort(cards.begin(), cards.end());
    do
    {
        int cnt = 0;
        pii cur = {r, c};

        pipii tmp;
        tmpBoard = board;
        FOR(i, cards.size())
        {
            tmp = bfs(cards[i], cur, tmpBoard); // 커서가 가르킬 카드까지
            cnt += tmp.first;
            cur = tmp.second;
            tmp = bfs(cards[i], cur, tmpBoard); // 짝 맞는 카드까지    
            cnt += tmp.first;
            cur = tmp.second;
        }

        answer = min(answer, cnt);
    }while(next_permutation(cards.begin(), cards.end()));

    return answer;
}

int main()
{
    vector<vector<int>> board
        = {{1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0}};
        // = {{3,0,0,2},{0,0,1,0},{0,1,0,0},{2,0,0,3}};
    cout << solution(board, 1, 0);
    return 0;
}