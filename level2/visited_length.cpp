#include <iostream>
#include <string>
#include <cstring>

#define MAX 11
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;
int dxdy[4][2]// = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // D, U, R, L
	= {{0, -1}, {1, 0}, {0, 1}, {-1, 0}}; // L, D, R, U;

bool visited[MAX][MAX][4];
int direction(char c)
{
	if(c == 'L') return 0;
	else if(c == 'R') return 2;
	else if(c == 'U') return 3;
	else return 1;
}

int dfs(int x, int y, int cnt, string &dirs)
{
	cout << x << " " << y << endl;
	int move = 0;
	if(cnt == dirs.length()) return 0;

	int dx = x + dxdy[direction(dirs[cnt])][0];
	int dy = y + dxdy[direction(dirs[cnt])][1];
	if(dx < 0 || dy < 0 || dx >= MAX || dy >= MAX) 
	{
		move += dfs(x, y, cnt+1, dirs);
		return move;
	}

	if(!visited[dx][dy][direction(dirs[cnt])])
	{
		cout << "IN" << endl;
		move++;
		visited[x][y][direction(dirs[cnt])] = true;
		visited[dx][dy][(direction(dirs[cnt])+2)%4] = true;
	}
	move += dfs(dx, dy, cnt+1, dirs);
	return move;
}

int solution(string dirs) {
    int answer = 0;
    memset(visited, false, sizeof(visited));
	answer = dfs(5, 5, 0, dirs);
    return answer;
}

int main()
{
	string dirs 
		// = "ULURRDLLU";
		= "LULLLLLLU";

	cout << solution(dirs);
	return 0;
}