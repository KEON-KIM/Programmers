#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 51
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef pair<int, int> pii;  
bool visited[MAX][MAX] = {false, };
bool game_visited[MAX][MAX] = {false, };
vector<vector<vector<int>>> material[MAX];
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<vector<int>> rotation(vector<vector<int>> mat)
{
	vector<vector<int>> tmp(mat[0].size(), vector<int>(mat.size(), 0));
	FOR(i, mat.size())
		FOR(j, mat[0].size())
			tmp[j][mat.size()-i-1] = mat[i][j];
	return tmp;
}
// vector<vector<int>> binding(int idx, vector<vector<int>> mat)
// {
	
// }
void print(vector<vector<int>> tmp)
{
	cout << "==================" << endl;
	FOR(i, tmp.size())
	{
		FOR(j, tmp[0].size())
		{
			cout << tmp[i][j] << ' ';
		}cout << endl;
	}
}
bool isSame(vector<vector<int>> m1, vector<vector<int>> m2)
{
	FOR(t, 4)
	{
		bool flag = false;
		if(m1.size() != m2.size() || m1[0].size() != m2[0].size()) 
		{
			m2 = rotation(m2);
			continue;
		}
		FOR(i, m1.size())
		{
			FOR(j, m1[0].size())
			{
				if(m1[i][j] != m2[i][j]) 
				{
					flag = true;
					break;
				}
			}
			if(flag) break;
		}
		if(!flag) return true;
		m2 = rotation(m2);
	}
	return false;
}
pair<int, vector<vector<int>>> bfs(int startX, int startY, bool flag, vector<vector<int>> &table)
{
	queue<pii> Que;
	Que.push({startX, startY});
	bool board[MAX][MAX] = {false, };

	int cnt = 0;
	int minX, minY, maxX, maxY;
	minX = maxX = startX; minY = maxY = startY;
	while(!Que.empty())
	{
		int x = Que.front().first;
		int y = Que.front().second;
		Que.pop();

		FOR(i, 4)
		{
			int dx = x + dxdy[i][0];
			int dy = y + dxdy[i][1];
			if(dx < 0 || dy < 0 || dx >= table.size() || dy >= table.size() || visited[dx][dy]) continue;
			if(flag? table[dx][dy] : !table[dx][dy])
			{
				Que.push({dx, dy});
				visited[dx][dy] = true;
				board[MAX/2 + (dx - startX)][MAX/2 + (dy - startY)] = true;
				minX = min(minX, dx); minY = min(minY, dy);
				maxX = max(maxX, dx); maxY = max(maxY, dy);
				cnt++;
			}
		}
	}
	// cout << "MAXX : " << maxX << " MINX : " << minX << " MAXY : " << maxY << " MINY : " << minY << endl;
	// int s = max((maxX - minX), (maxY - minY)) + 1;
	if(!cnt) return {1, {{1}}};
	int x_size = maxX - minX+1;
	int y_size = maxY - minY+1;
	vector<vector<int>> result(x_size, vector<int>(y_size, 0));
	FOR(i, x_size)
		FOR(j, y_size)
			result[i][j] = board[MAX/2 - (startX - minX) + i][MAX/2 - (startY - minY) + j];

	return {cnt, result};
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) 
{
    int answer = 0;
    FOR(i, table.size())
    {
    	FOR(j, table[0].size())
    	{
    		if(!visited[i][j] && table[i][j])
    		{
    			pair<int, vector<vector<int>>> p = bfs(i, j, 1, table);
    			material[p.first].push_back(p.second);
    			// cout << "TABLE : " << endl;
    			// print(p.second);
    		}
    	}
    }
    // print(game_board);
    // cout << "=========" <<endl;
    // print(table);
    memset(visited, false, sizeof(visited));
   	bool using_board[MAX][MAX] = {false, };
    FOR(i, game_board.size())
    {
    	FOR(j, game_board.size())
    	{
    		if(!visited[i][j] && !game_board[i][j])
    		{
    			pair<int, vector<vector<int>>> p = bfs(i, j, 0, game_board);
    			// cout << "MAP : " << endl;
    			// print(p.second);
    			FOR(i, material[p.first].size())
    			{
    				// print(material[p.first][i]);
    				if((isSame(p.second, material[p.first][i]) && !using_board[p.first][i]))
    				{
    					using_board[p.first][i] = true;
    					answer += p.first;
    					// cout << "=========" << endl;
    					// print(material[p.first][i]);
    					break;
    				}
    			}
    		}
    	}
    }
    return answer;
}
int main()
{
	vector<vector<int>> game_board
		// = {{1,1,0,0,1,0},{0,0,1,0,1,0},{0,1,1,0,0,1},{1,1,0,1,1,1},{1,0,0,0,1,0},{0,1,1,1,0,0}};
		// = {{0,0,0},{1,1,0},{1,1,1}};
		= {{0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0}, {1,0,0,0,1,0,1,0,1,0,1,0,0,1,0,1,1,1}, {0,1,1,1,0,0,1,0,1,0,0,1,1,0,1,0,0,0}, {0,0,0,0,1,1,0,0,1,1,0,1,0,0,1,0,0,0}, {0,1,1,1,0,0,1,1,1,1,0,1,1,1,0,1,1,1}, {1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0}, {0,0,0,1,1,1,0,0,1,1,0,1,1,1,1,0,0,1}, {1,1,1,0,0,0,1,1,0,0,1,0,0,0,0,1,1,0}, {0,0,1,0,1,1,1,0,0,1,0,1,1,1,1,0,0,0}, {1,1,0,1,1,0,1,1,1,1,0,1,0,0,0,1,1,1}, {0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,1,0}, {1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,0,1,0}, {0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,1,0,0}, {1,0,1,1,0,1,1,0,0,0,1,0,0,0,1,0,0,1}, {1,0,0,1,1,0,0,1,1,1,0,1,1,1,0,1,1,0}, {0,1,1,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0}, {0,0,0,1,0,1,0,1,0,0,1,1,1,1,1,1,1,0}, {0,1,0,1,1,0,0,1,0,1,0,0,0,0,0,0,1,0}};

	vector<vector<int>> table
		// = {{1,0,0,1,1,0},{1,0,1,0,1,0},{0,1,1,0,1,1},{0,0,1,0,0,0},{1,1,0,1,1,0},{0,1,0,0,0,0}};
		// = {{1,1,1},{1,0,0},{0,0,0}};
		= {{1,1,1,1,1,1,0,1,0,1,1,0,0,1,0,0,1,0}, {0,0,0,0,0,0,1,1,1,0,1,0,1,1,0,1,1,0}, {1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,1,0,1}, {1,1,0,1,1,1,0,1,0,1,0,1,1,0,1,0,0,1}, {1,1,1,0,0,0,1,0,1,0,1,0,0,1,0,0,1,1}, {0,0,0,1,1,1,0,1,1,1,0,1,1,0,1,0,0,0}, {1,1,1,0,0,0,0,0,1,1,0,1,1,0,1,1,1,1}, {0,0,1,0,1,1,0,1,0,0,1,0,0,1,0,0,0,0}, {1,0,1,0,0,0,0,1,0,1,1,0,1,1,0,1,1,1}, {1,0,1,0,1,1,1,1,0,1,1,0,0,0,1,1,1,0}, {1,1,0,1,0,0,0,0,1,0,0,1,1,1,0,0,0,0}, {0,0,1,1,1,1,0,1,1,0,1,0,0,0,1,1,0,1}, {1,1,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,1}, {1,1,0,0,1,1,1,0,1,1,0,1,0,1,0,1,0,1}, {0,0,1,1,0,1,1,0,1,0,1,1,0,0,0,1,0,0}, {1,1,1,0,1,0,0,1,0,1,1,0,0,1,0,1,0,1}, {0,0,0,0,1,0,1,1,1,0,0,1,0,1,1,0,1,1}, {0,1,1,1,1,0,0,1,0,0,1,1,0,1,0,0,1,1}};
	
	cout << solution(game_board, table);
	return 0;
}

/*
map과 set의 차이
깊은 복사 얕은복사
메모리 영역
map쓰는이유
behaviorTree
*/