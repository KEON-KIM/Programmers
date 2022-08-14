#include <string>
#include <vector>
#include <iostream>

#define MAX 18
using namespace std;

int result = -1;
int visited[MAX];
vector<int> board[MAX];
void dfs(int start, pair<int, int> count, vector<int> &info)
{
	int sheep = count.first;
	int wolf = count.second;
	result = max(result, sheep);
	cout << start<< " : "<<sheep << "|" << wolf << endl;
	for(int i = 0; i < info.size(); i++)
	{
		cout << visited[i] << " ";
	}cout << endl;
	for(int i : board[start])
	{
		if(visited[i] < 2)
		{
            visited[i]++;
			if(info[i]) // wolf
			{
				if(sheep > wolf + 1)
				{
					if(visited[i] < 2)
						dfs(i, {sheep, wolf + 1}, info);
					
					else
						dfs(i, count, info);
				}
			}
			else // 0 : sheep
			{
				if(visited[i] < 2)
					dfs(i, {sheep+1, wolf}, info);
				
				else
					dfs(i, count, info);
                
			}
            visited[i]--;
		}
	}

}
int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    for(int i = 0; i < edges.size(); i++)
    {
    	board[edges[i][0]].push_back(edges[i][1]);
    	board[edges[i][1]].push_back(edges[i][0]);
    }
    visited[0] = 1;
    dfs(0, {1, 0}, info); // next, count;
    return result;
}

int main()
{
	vector<int> info
		= {0,0,1,1,1,0,1,0,1,0,1,1};
		// = {0,1,0,1,1,0,1,0,0,1,0};
	vector<vector<int>> edges
		= {{0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9}};
		// = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6},{3,7},{4,8},{6,9},{9,10}};

	cout << solution(info, edges);
	return 0;
}