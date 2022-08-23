#include <cstring>
#include <vector>
#include <iostream>

#define MAX 151
#define INF 1000000000
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int board[MAX][MAX];
int max_alp = 0, max_cop = 0;
int dfs(int algo, int code, vector<vector<int>> problems) 
{
    if (max_alp <= algo && max_cop <= code) // 문제를 모두 풀 수 있을 경우
        return 0;

    int &ref = board[algo][code];
    if (ref != INF) 
        return board[algo][code];
    
    ref = INF + 1;
    ref = min(ref, dfs(min(algo + 1, max_alp), code, problems) + 1);
    ref = min(ref, dfs(algo, min(code + 1, max_cop), problems) + 1); // dpboard 최신화
    
    FOR(i, problems.size())
        if (problems[i][0] <= algo && problems[i][1] <= code) // 문제 해결 가능하다면
        {
            ref = min(ref, problems[i][4] + 
                dfs(min(algo + problems[i][2], max_alp), min(code + problems[i][3], max_cop), problems));
        }
    
    
    return ref;
}


int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;

    FOR(i, problems.size())
    {
        max_alp = max(max_alp, problems[i][0]);
        max_cop = max(max_cop, problems[i][1]);
    }   
    
    FOR(i, MAX)
        FOR(j, MAX) 
            board[i][j] = INF;

    return dfs(alp, cop, problems);
}
