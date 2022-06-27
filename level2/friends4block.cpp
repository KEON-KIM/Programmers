#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

#define MAX 31
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N, M;
int dxdy[4][3][2] = {
        {{0, 1}, {1, 0}, {1, 1}}, 
        {{1, 0}, {0, -1}, {1, -1}}, 
        {{0, -1}, {-1, 0}, {-1, -1}}, 
        {{0, 1}, {-1, 0}, {-1, 1}}
    };
bool visited[31][31] = {false, };
int find(vector<string> board)
{
    int cnt = 0;
    FOR(i, N)
    {
        FOR(j, M)
        {
            if(board[i][j] == '.') continue;
            FOR(k, 4)
            {
                bool flag = false;
                FOR(l, 3)
                {
                    int dx = i + dxdy[k][l][0];
                    int dy = j + dxdy[k][l][1];
                    if(dx < 0 || dy < 0 || dx >= N || dy >= M ||
                        board[dx][dy] != board[i][j])
                    {
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                {
                    FOR(l, 3)
                    {
                        int dx = i + dxdy[k][l][0];
                        int dy = j + dxdy[k][l][1];
                        if(!visited[dx][dy]) cnt++;
                        visited[dx][dy] = true;
                    }
                    if(!visited[i][j]) cnt++;
                    visited[i][j] = true;
                }
            }
        }
    }
    return cnt;
}

void update(vector<string> &board)
{
    FOR(i, M)
    {
        bool flag = false;
        for(int j = N-1; j >= 0; j--)
        {
            int cur = j;
            if(visited[j][i] && !flag)
                flag = true;

            if(flag && !visited[j][i])
            {
                while(cur+1 < N && visited[cur+1][i])
                {
                    char tmp = board[cur][i];
                    board[cur++][i] = '.';
                    board[cur][i] = tmp; 
                }

                visited[cur][i] = false;
            }
        }
    }
}

void print(vector<string> board)
{
    for(string str : board)
        cout << str << endl;
}
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    N = m; M = n;

    while(true)
    {
        int cnt = find(board);
        if(!cnt) break;
        update(board);
        answer += cnt;
        memset(visited, false, sizeof(visited));
        print(board);
    }

    return answer;
}

int main()
{
    vector<string> board
        // = {"CCBDE", "AAADE", "AAABF", "CCBBF"};
        // = {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"};
        = {"TTTANT",
           "RRFACC",
           "RRRFCC",
           "TMMRAA",
           "TTMMMF",
           "TTMTTJ"};

    cout << solution(6, 6, board);
    return 0;
}