#include <vector>
#include <cstring>
#include <iostream>

#define INF 987654321
#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int dp[101][202];
vector<int> board[202];
void Init(int n, vector<vector<int>> &edge_list)
{
	FOR(i, n)
		FOR(j, n)
			dp[i][j] = INF;
	FOR(i, n) board[i].clear();
    // FOR(i, n) board[i].push_back(i);
    for(vector<int> v : edge_list)
    {
    	board[v[0]].push_back(v[1]);
    	board[v[1]].push_back(v[0]);
    }
}

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
	
    Init(n, edge_list);
	
    int answer = 0;
    int start = gps_log[0], end = gps_log[k-1];

    dp[0][start] = 0;
    for (int i = 0; i < k - 1; i++) {
    	FOR(j, n){
	    	if (dp[i][j] == INF)
	        	continue;

	    	for (int next : board[j]) 
	    	{
	        	int value = dp[i][j];
	        	if (next != gps_log[i + 1]) value++;
	        	dp[i + 1][next] = min(dp[i + 1][next], value);
	     	}
    	}
    }

    return ((dp[k - 1][end] != INF) ? dp[k - 1][end] : -1);
}

int main()
{
	vector<vector<int>> edge_list 
		= {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}};
		// = {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}};
		
	vector<int> gps_log 
		= {1, 2, 3, 3, 6, 7};
		// = {1, 2, 4, 6, 5, 7};
	cout << solution(7, 10, edge_list, 6, gps_log);
	return 0;
}
/*#include <vector>
#include <iostream>

#define MAX 202
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int result = MAX;
vector<int> board[MAX];
bool visited[MAX] = {false, };
void print(vector<int> &ref)
{
	for(int i : ref)
		cout << i << " ";
	cout << endl;
}
int different(vector<int> &left, vector<int> &right)
{
	int cnt = 0;
	FOR(i, left.size())
		if(left[i] != right[i]) cnt++;

	// print(right);
	return cnt;
}
void dfs(int cur, int idx, int diff, vector<int> &history, vector<int> &gps_log)
{
	print(history);
	if(diff > result) return;
	if(history.size() == gps_log.size() ){//&& gps_log[gps_log.size()-1] == history[history.size()-1]){
		result = min(result, different(gps_log, history));
		return;
	}
	
	for(int i = 0; i < board[cur].size(); i++)
	{
		int next = board[cur][i];
		cout << "IDX : " <<  next << endl;
		if(!visited[next] || cur == next)
		{
			visited[next] = true;
			history.push_back(next);
			if(history[idx+1] != gps_log[idx+1]) {
				cout << "O" << endl;
				dfs(next, idx+1, diff+1, history, gps_log);
			}
			else{
				cout << "X" << endl;
				dfs(next, idx+1, diff, history, gps_log);
			}
			history.pop_back();
			visited[next] = false;
		}
	}
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    for(int i = 1; i <= n; i++) board[i].push_back(i);
    for(vector<int> v : edge_list)
    {
    	board[v[0]].push_back(v[1]);
    	board[v[1]].push_back(v[0]);
    }
    FOR(i, n+1)
    {
    	print(board[i]);
    }
    vector<int> tmp;
    tmp.push_back(gps_log[0]);
    visited[gps_log[0]] = true;
    dfs(gps_log[0], 0, 0, tmp, gps_log);
    if(result == MAX) return -1;
    else answer = result;
    return answer;
}
*/