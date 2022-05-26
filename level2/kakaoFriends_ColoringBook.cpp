#include <iostream>
#include <vector>
#include <queue>

#define MAX 101
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int M, N;
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool visited[MAX][MAX];
int bfs(int startX, int startY, vector<vector<int>> board)
{
    int res = 1;
    int info = board[startX][startY];
    queue<pair<int, int>> Que;
    Que.push({startX, startY});
    
    visited[startX][startY] = true;
    while(!Que.empty())
    {
        int x = Que.front().first;
        int y = Que.front().second;
        Que.pop();
        
        FOR(i, 4)
        {
            int dx = x + dxdy[i][0];
            int dy = y + dxdy[i][1];
            
            if(dx < 0 || dy < 0 || dx >= M || dy >= N) continue;
            if(board[dx][dy] == info && !visited[dx][dy])
            {
                Que.push({dx, dy});
                visited[dx][dy] = true;
                res++;
            }
        }
    }
    return res;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    M = m; N = n;

    FOR(i, m)
        FOR(j, n)
            if(!visited[i][j] && picture[i][j]) 
            {
                answer[1] = max(answer[1], bfs(i, j, picture));
                answer[0]++;
            }
        
    return answer;
}

int main()
{
    vector<vector<int>> tmp =
        // {{1, 1, 1, 0},
        // {1, 2, 2, 0},
        // {1, 0, 0, 1},
        // {0, 0, 0, 1},
        // {0, 0, 0, 3},
        // {0, 0, 0, 3}};

    {{1, 1, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}};

    vector<int> result(2);
    result = solution(6, 4, tmp);
    cout << "result : " <<  result[0] << " " << result[1]<< endl;

    return 0;
}