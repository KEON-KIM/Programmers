#include <cstring>
#include <vector>
#include <iostream>
#include <climits>
#include <queue>

#define MAX 202
#define INF 1e8
#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;

typedef pair<int, int> pii;
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1e9;
    int board[MAX][MAX];
    //Init()
    FOR(i, n)
    	FOR(j, n){
    		board[i][j] = 1e8;
    		if(i == j) board[i][j] = 0;
    	}

    for(vector<int> v : fares)
    {
    	board[v[0]][v[1]] = v[2];
    	board[v[1]][v[0]] = v[2];
    }

    FOR(dia, n)
    	FOR(i, n)
    		FOR(j, n)
    			board[i][j] = min(board[i][j], board[i][dia] + board[dia][j]);
    		

    FOR(i, n)
    	answer = min(answer, board[s][i] + board[i][a] + board[i][b]);
    
    return answer;
}

int main()
{
    vector<vector<int>> fares
        // 6, 4, 6, 2
        // = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
        // 7, 3, 4, 1
        // = {{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}};
        // 6, 4, 5, 6
        = {{2,6,6}, {6,3,7}, {4,6,7}, {6,5,11}, {2,5,12}, {5,3,20}, {2,4,8}, {4,3,9}};
    cout << solution(6, 4, 5, 6, fares);
    return 0;
}