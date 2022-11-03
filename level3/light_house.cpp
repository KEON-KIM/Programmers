#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 100002
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;
typedef pair<int, int> pii;

vector<int> graph[MAX];
bool visited[MAX] = {false, };
pii dfs(int parent)
{
	visited[parent] = true;
	vector<int> child;
	pii result = {1, 0};
	FOR(i, graph[parent].size())
	{
		int next = graph[parent][i];
		if(!visited[next])
			child.push_back(next);
	}
	if(!child.size()) return result;
	else
	{
		FOR(i, child.size())
		{
			pii child_res = dfs(child[i]);
			result.first += min(child_res.first, child_res.second);
			result.second += child_res.first;
		}
		
		return result;
	}
}
int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    FOR(i, lighthouse.size())
    {
    	graph[lighthouse[i][0]].push_back(lighthouse[i][1]);
    	graph[lighthouse[i][1]].push_back(lighthouse[i][0]);
    }

    pii result = dfs(1);

    return min(result.first, result.second);
}
int main()
{
	int n 
		= 8;
		// = 10;
	vector<vector<int>> lighthouse
		= {{1, 2}, {1, 3}, {1, 4}, {1, 5}, {5, 6}, {5, 7}, {5, 8}};
		// = {{4, 1}, {5, 1}, {5, 6}, {7, 6}, {1, 2}, {1, 3}, {6, 8}, {2, 9}, {9, 10}};
	cout << solution(n, lighthouse);
	return 0;
}