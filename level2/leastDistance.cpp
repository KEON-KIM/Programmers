#include <iostream>
#include <vector>
#include <queue>

#define MAX 101
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef pair<int ,int> pii;

int dist[MAX][MAX];
bool visited[MAX][MAX];
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int bfs(pii startPoint, vector<vector<int>> board)
{
	pii endPoint = {board.size(), board[0].size()};
	queue<pii> Que;
	Que.push(startPoint);

	visited[0][0] = true;
	while(!Que.empty())
	{
		int x = Que.front().first;
		int y = Que.front().second;
		Que.pop();

		if(x == endPoint.first-1 && y == endPoint.second-1)
			return dist[x][y] + 1;
		
		FOR(i, 4)
		{
			int dx = x + dxdy[i][0];
			int dy = y + dxdy[i][1];

			if(dx < 0 || dy < 0 || dx >= endPoint.first || dy >= endPoint.second) continue;
			if(visited[dx][dy] || !board[dx][dy]) continue;
			visited[dx][dy] = true;
			dist[dx][dy] = dist[x][y] + 1;
			Que.push({dx, dy});
		}
	}

	return -1;
}
int solution(vector<vector<int>> maps)
{
    int answer = 0;
    answer = bfs({0, 0}, maps);
    return answer;
}

int main()
{
	// vector<vector<int>> maps = 
	// 	{{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}};
	vector<vector<int>> maps = 
		{{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,0},{0,0,0,0,1}};
	cout << solution(maps);
	return 0;
}