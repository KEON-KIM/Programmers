#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 5
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;
bool visited[MAX][MAX];
int dxdy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
/*void print()
{
	cout << "------------------" << endl;
	FOR(i, MAX)
	{
		FOR(j, MAX)
			cout << dist[i][j] << " ";
		cout << endl;
	}
}*/
bool bfs(int a, int b, vector<string> board)
{
	queue<pair<int, pair<int, int>>> Que;
	Que.push({0, {a, b}});
	while(!Que.empty())
	{
		int dist = Que.front().first;
		int x = Que.front().second.first;
		int y = Que.front().second.second;
		Que.pop();
		
		if(board[x][y] == 'P')
		{
			if(!dist) 
			{
                if(visited[x][y]) continue;
				visited[x][y] = true;
			}
			
			else if(dist <= 2){
				return false;
			}

		}

		FOR(i, 4)
		{
			int dx = x + dxdy[i][0];
			int dy = y + dxdy[i][1];

			if(dx < 0 || dy < 0 || dx >= MAX || dy >= MAX) continue;
			if(board[dx][dy] == 'X' || visited[dx][dy] ) continue;

			Que.push({dist+1, {dx, dy}});
			visited[dx][dy] = true;
		}

	}return true;

}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
	for(vector<string> v : places)
	{
		memset(visited, false, sizeof(visited));
		queue<pair<int, int>> Que;
		FOR(i, MAX)
			FOR(j, MAX)
				if(v[i][j] == 'P') Que.push({i, j});
		bool flag = false;
		while(!Que.empty())
		{
			memset(visited, false, sizeof(visited));
			int x = Que.front().first;
			int y = Que.front().second;
			Que.pop();

			if(!bfs(x, y, v)){
				flag = true;
				answer.push_back(0);
				break;
			}
		}if(!flag)answer.push_back(1);
	}
    return answer;
}

int main()
{
	vector<vector<string>> places =
	{
		{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, 
		{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, 
		{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, 
		{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, 
		{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"},
		{"PXPXP", "OPXPX", "PXPXP", "XPXPX", "PXPXP"},
		{"PPPXP", "OPXPX", "PXPXP", "XPXPX", "PXPXP"},
		{"XPXPX", "PXPXP", "XPXPX", "PXPXP", "XPXPX"},
		{"XPOPX", "PXPXP", "XPXPX", "PXPXP", "XPXPX"},
		{"PPPPP", "PPPPP", "PPPPP", "PPPPP", "PPPPP"},
		{"OPOPO", "POPOP", "OPOPO", "POPOP", "OPOPO"},
		{"PXOOP", "XPOOX", "PXXOP", "XOPOX", "POOOP"},
		{"POOOO", "OOOOO", "OOPOO", "OOOOO", "OOOOO"},
		{"POOOO", "XXXXX", "PXPOO", "XXXXP", "OOOOP"},
		{"PXOOO", "OOOOO", "PXOOO", "OOOOO", "OOOPO"}
	};
	vector<int> answer = solution(places);
	for(int i : answer)
		cout << i << " ";
	return 0;
}