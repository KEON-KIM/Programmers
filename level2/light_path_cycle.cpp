#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 501
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

bool visited[MAX][MAX][4];

int N, M;
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int dfs(int x, int y, int dir, vector<string> &grid)
{
	x = x < 0 ? N - 1 : x, y = y < 0? M - 1 : y, dir %= 4;
	int cnt = 0;
	int dx, dy;
	cout << x << '/'<< y <<'/'<<dir << '/' << cnt << endl;
	if(visited[x][y][dir]) return 0;
	if(grid[x][y] == 'L')
	{
		visited[x][y][dir] = true;
		if(!dir)// East -> North
		{
			dx = x + dxdy[dir+3][0];
			dy = y + dxdy[dir+3][1];
			cnt += dfs(dx%N, dy%M, dir+3, grid) + 1;
		}
		else if(dir == 1) //West -> South
		{
			dx = x + dxdy[dir+1][0];
			dy = y + dxdy[dir+1][1];
			cnt += dfs(dx%N, dy%M, dir+1, grid) + 1;
		}
		else // South -> East, North -> West;
		{
			dx = x + dxdy[(dir+2)%4][0];
			dy = y + dxdy[(dir+2)%4][1];
			cnt += dfs(dx%N, dy%M, dir+2, grid) + 1;
		}
	}
	else if(grid[x][y] == 'R')
	{
		int dx, dy;
		visited[x][y][dir] = true;
		if(dir == 3) // North -> East
		{
			dx = x + dxdy[(dir+1)%4][0];
			dy = y + dxdy[(dir+1)%4][1];
			cnt += dfs(dx%N, dy%M, dir+1, grid) + 1;
		}
		else if(dir == 2) // South -> West
		{
			dx = x + dxdy[(dir+3)%4][0];
			dy = y + dxdy[(dir+3)%4][1];
			cnt += dfs(dx%N, dy%M, dir+3, grid) + 1;
		}
		else
		{
			dx = x + dxdy[dir+2][0];
			dy = y + dxdy[dir+2][1];
			cnt += dfs(dx%N, dy%M, dir+2, grid) + 1;
		}
	}
	else
	{
		visited[x][y][dir] = true;
		dx = x + dxdy[dir][0];
		dy = y + dxdy[dir][1];
		cnt += dfs(dx%N, dy%M, dir, grid) + 1;
	}

	return cnt;
}
vector<int> solution(vector<string> grid) {
	int res = 0;
	N = grid.size(); M = grid[0].size();
	
    vector<int> answer;
    FOR(i, N)
    	FOR(j, M)
    		FOR(k, 4)
    		{
    			int tmp = dfs(i, j, k, grid);
		    	if(tmp)
		    		answer.push_back(tmp);
    		}
        
    
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
	vector<string> grid
		// = {"SL","LR"};
		// = {"S", "S"};
		= {"S"};
		// = {"R", "R"};
	vector<int> answer = solution(grid);
	FOR(i, answer.size())
		cout << answer[i] << " ";

	return 0;
}