#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define MAX 102
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int board[MAX][MAX];
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int bfs(int x1, int y1, int x2, int y2)
{
	queue<pair<int, pair<int, int>>> Que; // moveCnt, {x, y};
	Que.push({1, {x1, y1}});
	board[x1][y1] = 0;

	while(!Que.empty())
	{
		int move = Que.front().first;
		int x = Que.front().second.first;
		int y = Que.front().second.second;
		Que.pop();

		if(x == x2 && y == y2) return move;
		FOR(i, 4)
		{
			int dx = x + dxdy[i][0];
			int dy = y + dxdy[i][1];

			if(dx < 0 || dy < 0 || dx >= MAX || dy >= MAX) continue;
			if(!board[dx][dy]) continue;
			board[dx][dy] = 0;
			Que.push({move+1, {dx, dy}});
		}
	}
	return -1;
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    FOR(i, rectangle.size())
    {
    	FOR(j, 4) rectangle[i][j] *=2; 
    	for(int j = rectangle[i][0]; j <= rectangle[i][2]; j++){
    		board[rectangle[i][1]][j] = 1;
    		board[rectangle[i][3]][j] = 1;
    	}
    	for(int j = rectangle[i][1]; j <= rectangle[i][3]; j++)
    	{
    		board[j][rectangle[i][0]] = 1;
    		board[j][rectangle[i][2]] = 1;
    	}
    }

    FOR(i, rectangle.size())
    {
    	for(int j = rectangle[i][0]+1; j < rectangle[i][2]; j++)
    	{
    		for(int k = rectangle[i][1]+1; k < rectangle[i][3]; k++)
    		{
    			board[k][j] = 0;
    		}
    	}
    }

    FOR(i, 22){
    	FOR(j, 22)
    		cout << board[i][j] << " ";
    	cout << endl;
    }
    //print();
    answer = bfs(characterY*2, characterX*2, itemY*2, itemX*2);
    return answer/2;
}

int main()
{
	vector<vector<int>> rectangle 
		// = {{1, 1, 7, 4}};
		= {{1,1,7,4},{3,2,5,5},{4,3,6,9},{2,6,8,8}};// x1, y1, x2, y2 // 1,3,7,8
		// = {	{1, 1, 8, 4}, {2, 2, 4, 9}, {3, 6, 9, 8}, {6, 3, 7, 7}}; // 9, 7, 6, 1
	cout << solution(rectangle, 1, 3, 7, 8);
	return 0;
}