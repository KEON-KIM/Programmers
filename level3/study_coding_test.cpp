#include <cstring>
#include <vector>
#include <iostream>

#define MAX 181
#define INF 1e9
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int max_alp = 0, max_cop = 0;
int board[MAX][MAX];
int dfs(int algo, int code, vector<vector<int>> problems) 
{
    if (max_alp <= algo && max_cop <= code) 
        return 0;

    int &ref = board[algo][code];
    if (ref != INF) 
        return board[algo][code];
    
    ref++;
    ref = min(ref, dfs(min(algo + 1, max_alp), code, problems) + 1);
    ref = min(ref, dfs(algo, min(code + 1, max_cop), problems) + 1); // dpboard 최신화

    for (vector<int> problem : problems) 
    {
        if (problem[0] <= algo && problem[1] <= code) 
        { // 문제 해결 가능하다면,
            ref = min(ref, problem[4] + 
                dfs( min(algo + problem[2], max_alp), min(code + problem[3], max_cop), problems));
        }
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
    // memset(board, 0x3f, sizeof(board));
    // cout << board[0][0]+1 << endl;
    FOR(i, MAX)
        FOR(j, MAX) board[i][j] = INF;

    return dfs(alp, cop, problems);
}

int main()
{
    vector<vector<int>> problems
        // = {{10,15,2,1,2},{20,20,3,3,4}};
        = {{0,0,2,1,2},{4,5,3,1,2},{4,11,4,0,2},{10,4,0,4,2}};
    cout << solution(0, 0, problems);
    return 0;
}
/*
import java.util.*;
import java.io.*;

class Solution {
    static int maxAlgo = 0;
    static int maxCode = 0;
    static final int ALGO = 1;
    static final int CODE = 2;
    static final int INF = 1_000_000_000;
    static int[][] dp;

    static int cal(int value, int judge) {
        if (judge == ALGO) {
            return Math.min(maxAlgo, value);
        } else {
            return Math.min(maxCode, value);
        }
    }

    static int dfs(int algo, int code, int[][] problems) {
        if (maxAlgo <= algo && maxCode <= code) {
            return 0;
        }

        if (dp[algo][code] != INF) {
            return dp[algo][code];
        }

        dp[algo][code] = INF + 1;

        dp[algo][code] = Math.min(dp[algo][code], 1 + dfs(cal(algo + 1, ALGO), code, problems));
        dp[algo][code] = Math.min(dp[algo][code], 1 + dfs(algo, cal(code + 1, CODE), problems));

        for (int[] problem : problems) {
            if (problem[0] <= algo && problem[1] <= code) {
                dp[algo][code] = Math.min(dp[algo][code], problem[4] + dfs(cal(algo + problem[2], ALGO)
                        , cal(code + problem[3], CODE), problems));
            }
        }

        return dp[algo][code];
    }

    public int solution(int alp, int cop, int[][] problems) {
        for (int[] problem : problems) {
            maxAlgo = Math.max(maxAlgo, problem[0]);
            maxCode = Math.max(maxCode, problem[1]);
        }

        dp = new int[Math.max(alp, maxAlgo) + 1][Math.max(cop, maxCode) + 1];

        for (int i = 0; i <= Math.max(alp, maxAlgo); i++) {
            Arrays.fill(dp[i], INF);
        }

        return dfs(alp, cop, problems);
    }
}

#include <string>
#include <vector>
#include <iostream>
#include <queue>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int timeCost[8];
int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int max_alp, max_cop;
    priority_queue<pipii, vector<pipii>, greater<pipii>> pQue;
    max_cop = max_alp = -1;
    FOR(i, problems.size())
    {
        timeCost[i] = problems[i][0] + problems[i][1];
        max_alp = max(max_alp, problems[i][0]);
        max_cop = max(max_cop, problems[i][1]);
    }

    pQue.push({0, {alp, cop}});
    while(!pQue.empty())
    {
        int alp_cur = pQue.top().second.first;
        int cop_cur = pQue.top().second.second;
        int cost = pQue.top().first;
        pQue.pop();
        cout << alp_cur << "/" << cop_cur << ":" << cost<< endl;
        if(alp_cur >= max_alp && cop_cur >= max_cop) return cost;

        FOR(i, problems.size())
        {
            if(problems[i][0] <= alp_cur && problems[i][1] <= cop_cur) // 문제를 풀 수 있을 때
                pQue.push({cost + problems[i][4], {alp_cur + problems[i][2], cop_cur + problems[i][3]}});
            
            else // 문제를 풀 수 없을 때
            {
                int x = (problems[i][0] < alp_cur)? 0 : problems[i][0] - alp_cur;
                int y = (problems[i][1] < cop_cur)? 0 : problems[i][1] - cop_cur;
                if(timeCost[i] > cost+x+y){
                    timeCost[i] = cost + x + y;
                    pQue.push({ cost + x + y, {problems[i][0], problems[i][1]}});
                }
            }
            
        }
    }
    return answer;
}
*/