#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define MAX 1001
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef pair<int, int> pii;
int N, M;
int dxdy[4][2] = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
bool visited[51][51] = {false, };
vector<pii> bfs(int a, int b, int val, vector<vector<int>> &board)
{
    queue<pii> Que;
    vector<pii> res;

    Que.push({a, b});
    while(!Que.empty())
    {
        int x = Que.front().first;
        int y = Que.front().second;
        Que.pop();
        res.push_back({x, y});

        FOR(i, 4)
        {
            int dx = x + dxdy[i][0];
            int dy = y + dxdy[i][1];

            if(dx < 0 || dy < 0 || dx >= M || dy >= N) continue;
            if(visited[dx][dy] || board[dx][dy] != val) continue;
            visited[dx][dy] = true;
            Que.push({dx, dy});
        }
    }
    return res;
}

int solution(vector<vector<int>> board) {
    int answer = 0, index = 0;
    int isRoot[MAX] = {0, };
    bool isDelete[MAX] = {false, };
    isDelete[0] = true; // 0 : 위에 아무도 없을 경우
    M = board.size(); N = board[0].size();
    FOR(i, M)
    {
        FOR(j, N)
        {
            index = max(index, board[i][j]);
            // cout << board[i][j] << "/"<< isDelete[isRoot[board[i][j]]] << "/ROOT : " << isRoot[board[i][j]] << "/"<< visited[i][j] << endl;
            if(board[i][j] && !visited[i][j])
            {
                // cout << board[i][j] << endl;
                vector<pii> xy = bfs(i, j, board[i][j], board);
                int min_y = 0x3f, max_y = -1, min_x = 0x3f, max_x = -1;
                for(pii p : xy)
                {
                    min_x = min(min_x, p.first);
                    max_x = max(max_x, p.first);
                    min_y = min(min_y, p.second);
                    max_y = max(max_y, p.second);
                }
                /*if(max_y - min_y == 2)
                    isDelete[board[i][j]] = (board[i][min_y] && board[i][min_y+1] && board[i][max_y]);
                else
                    isDelete[board[i][j]] = board[i][min_y] && board[i][max_y];*/
                
                // 파괴될 수 있는지 
                isDelete[board[i][j]] = false;
                if(max_x - min_x < max_y - min_y) // 2x3
                {
                    if(board[max_x][min_y] && board[max_x][min_y+1] && board[max_x][max_y])
                    {
                        for(int k = min_y; k <= max_y; k++)
                        {
                            isDelete[board[i][j]] = true;
                            if(board[min_x][k] != board[i][j])
                            {
                                for(int l = max_x; l >= 0; l--)
                                {
                                    if(board[i][j] != board[l][k] && !isDelete[board[l][k]])
                                    {
                                        isDelete[board[i][j]] = false;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                else // 3x2
                {
                    if(board[min_x][min_y] && board[min_x+1][min_y] && board[max_x][min_y]) // 좌측 가득
                    {
                        if(!(board[min_x][max_y] || board[min_x+1][max_y]))
                        {
                            isDelete[board[i][j]] = true;
                            for(int k = max_x; k >= 0; k--)
                            {
                                if(board[i][j] != board[k][max_y] && !isDelete[board[k][max_y]])
                                {
                                    isDelete[board[i][j]] = false;
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        if(!(board[min_x][min_y] || board[min_x+1][min_y])) // 우측 가득
                        {
                            isDelete[board[i][j]] = true;
                            for(int k = max_x; k >= 0; k--)
                            {
                                if(board[i][j] != board[k][min_y] && !isDelete[board[k][min_y]])
                                {
                                    isDelete[board[i][j]] = false;
                                    break;
                                }
                            }
                        }
                    }
                }
                
               /* if(!isDelete[board[i][j]] || !isDelete[isRoot[board[i][j]]])
                {
                    isDelete[board[i][j]] = false;
                    for(int k = min_y; k <= max_y; k++)
                    {
                        for(int l = max_x+1; l < M; l++)
                        {
                            if(board[l][k])
                            {
                                isRoot[board[l][k]] = board[i][j];
                                break;
                            }
                        }
                    }
                }
                else
                    answer++;*/
                

            }
        }
    }
    for(int i = 1; i < index; i++) if(isDelete[i]) {answer++;}
    return answer;
}

int main()
{
    vector<vector<int>> board
        = {{0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,4,4,0,0,0},
        {0,0,0,0,3,0,4,0,0,0},
        {0,0,0,2,3,0,0,0,5,5},
        {1,2,2,2,3,3,0,0,0,5},
        {1,1,1,0,0,0,0,0,0,5}};
    cout << solution(board);
    return 0;
}