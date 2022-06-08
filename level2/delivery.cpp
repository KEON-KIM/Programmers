#include <iostream>
#include <vector>
using namespace std;
// Floyd
#define MAX 51
#define INF 100000
#define FOR(i, n) for(int i = 0; i < n; i++)
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int board[MAX][MAX];
    //Init
    FOR(i, MAX)
    	FOR(j, MAX) 
    	{
    		if(i == j) 
    		{
    			board[i][j] = 0;
    			continue;
    		}
    		board[i][j] = INF;
    	}

    for(vector<int> v : road)
    {
    	board[v[0]][v[1]] = min(board[v[0]][v[1]], v[2]);
    	board[v[1]][v[0]] = min(board[v[1]][v[0]], v[2]);
    }

    for(int dia = 1; dia < MAX; dia++)
    	for(int i = 1; i < MAX; i++)
	    	for(int j = 1; j < MAX; j++)
	    		board[i][j] = min(board[i][j], board[i][dia] + board[dia][j]);
	    
    for(int i = 1; i <= N; i++)
    	if(board[1][i] > K) answer++;

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
    return N - answer;
}

int main()
{
	// vector<vector<int>> road 
	// = {{1,2,1}, {2,3,3}, {5,2,2}, {1,4,2}, {5,3,1}, {5,4,2}};
	vector<vector<int>> road 
	= {{1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1}};
	// cout << solution(5, road, 3);
	cout << solution(6, road, 4);
	return 0;
}