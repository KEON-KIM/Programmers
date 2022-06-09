#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer = -1;
bool visited[8];
void dfs(int idx, int cur, int res, vector<vector<int>> &dungeons)
{
	answer = max(answer, res);
	
	if(cur <= 0) return;
	for(int i = 0; i < dungeons.size(); i++)
	{
		if(!visited[i] && cur >= dungeons[i][0])
		{
			visited[i] = true;
			dfs(idx+1, cur - dungeons[i][1], res+1, dungeons);
			visited[i] = false;
		}
	}
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(0, k, 0, dungeons);

    return answer;
}

int main()
{
	vector<vector<int>> dungeons = 
		{{80,20}, {50,40}, {30,10}};

	cout << solution(80, dungeons);
	return 0;
}