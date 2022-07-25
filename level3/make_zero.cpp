#include <string>
#include <vector>
#include <iostream>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;
ll answer = 0;
void dfs(vector<vector<int>>& board, vector<ll>& sum, int cur, int parent) {  
    FOR(i, board[cur].size())
        if (board[cur][i] != parent) 
            dfs(board, sum, board[cur][i], cur); 
    
    sum[parent] += sum[cur]; 
    answer += abs(sum[cur]); 
}
ll solution(vector<int> a, vector<vector<int>> edges) {

    vector<ll> sum(a.size());
    FOR(i, a.size()) sum[i] = a[i];

    vector<vector<int>> board(a.size());
    FOR(i, edges.size())
    {
        board[edges[i][0]].push_back(edges[i][1]);
        board[edges[i][1]].push_back(edges[i][0]);
    }
    
    dfs(board, sum, 0, 0); // graph, sum, cur_index, cur_parent
    
    if (sum[0] == 0) return answer;
    else return - 1;
}