#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
vector<pipii> graph[4][3];
int dxdy[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, 
					{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
char mapping[13] = {'1', '2','3', '4', '5', '6', '7', '8', '9', '*', '0', '#'};
void make_graph()
{
	FOR(i, 4)
	{
		FOR(j, 3)
		{
			graph[i][j].push_back({1, {i, j}});
			FOR(t, 8)
			{
				int dx = i + dxdy[t][0];
				int dy = j + dxdy[t][1];
				if(dx < 0 || dy < 0 || dx >= 4 || dy >= 3) continue;
				if(t < 4)
					graph[i][j].push_back({2, {dx, dy}});
				else
					graph[i][j].push_back({3, {dx, dy}});
			}
		}
	}
}
// Dijikstra
pipii bfs(pii p, char c)
{
	bool visited[4][3] = {false, };
	priority_queue<pipii, vector<pipii>, greater<pipii>> pQue;
	pQue.push({0, p});
	while(!pQue.empty())
	{
		int cost = pQue.top().first;
		int x = pQue.top().second.first;
		int y = pQue.top().second.second; 
		pQue.pop();

		// cout << mapping[x*3+y] << endl;	
		if(c == mapping[x * 3 + y]) 
			return {cost, {x, y}};
		
		FOR(k, graph[x][y].size())
		{
			pipii v = graph[x][y][k];
			if(!visited[v.second.first][v.second.second])
			{
				visited[v.second.first][v.second.second] = true;
				pQue.push({cost + v.first, v.second});
			}
		}
	}
}
int solution(string number)
{
	int result = 0;
	make_graph();
	pair<pii, pii> thumb = {{1, 0}, {1, 2}};
	FOR(i, number.length())
	{
		pipii v1 = bfs(thumb.first, number[i]);
		pipii v2 = bfs(thumb.second, number[i]);
		// cout << "CHAR : " << number[i] << endl;
		if(v1.first < v2.first)
		{
			// cout << "ADD1 : " << v1.first;
			result += v1.first;
			thumb.first = v1.second;
		}
		else
		{
			// cout << "ADD2 : " << v2.first;
			result += v2.first;
			thumb.second = v2.second;
		}
	}

	// cout <<"RESULT : " <<  result << endl;
	return result;
}
int main()
{
	string number 
	= "1756";
	// = "5123";
	cout << solution(number);
	return 0;
}