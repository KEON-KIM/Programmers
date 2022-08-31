#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int m, int n, vector<vector<pair<int, int>>> info)
{
	int score[m] = {0, };
	int result = 0;
	int res_x, res_y;
	set<int> board[m][n]; 
	
	for(int i = 0; i < info.size(); i++)
	{
		int minX = info[i][0].first;
		int maxX = info[i][1].first;
		int minY = info[i][0].second;
		int maxY = info[i][1].second;

		for(int x = minX; x <= maxX; x++)
		{
			for(int y = minY; y <= maxY; y++)
			{
				board[x][y].insert(i);
				if(result < board[x][y].size())
				{
					res_x = x;
					res_y = y;
					result = board[x][y].size();
				}
			}
		}
	}

	cout << res_x << "/" << res_y << endl;
	for(auto it : board[res_x][res_y])
		cout << it << endl;

	return result;
}
int main()
{
	int m = 10, n = 10;
	vector<vector<pair<int, int>>> info
		= {{{0, 0}, {3, 0}}, {{0, 1}, {1, 3}}, {{3, 3},{5, 5}}, {{1, 5}, {3, 6}}, {{0, 9}, {3, 9}}, {{5, 1}, {5, 8}}};
	cout << solution(m, n, info);
	return 0;
}