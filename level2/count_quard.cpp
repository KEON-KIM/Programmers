#include <iostream>
#include <string>
#include <vector>

using namespace std;
void dfs(int x, int y, int s, vector<vector<int>> &arr, vector<int> &answer)
{
	int zero_cnt = 0;
	for(int i = x; i < x + s; i++)
		for(int j = y; j < y + s; j++)
			if(arr[i][j] == 0)
				zero_cnt++;
	
	if(zero_cnt == s*s)
	{
		answer[0]++;
		return;
	}
	else if(zero_cnt == 0) 
	{
		answer[1]++;
		return;
	}

	dfs(x, y, s/2, arr, answer);
	dfs(x, y + s/2, s/2, arr, answer);
	dfs(x + s/2, y, s/2, arr, answer);
	dfs(x + s/2, y + s/2, s/2, arr, answer);
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    answer.resize(2);
    int N = arr.size();
    dfs(0, 0, N, arr, answer);
    return answer;
}

int main()
{
	vector<int> answer;
	vector<vector<int>> arr 
		// = {{1,1,0,0},{1,0,0,0},{1,0,0,1},{1,1,1,1}};
		= {{1,1,1,1,1,1,1,1},{0,1,1,1,1,1,1,1},{0,0,0,0,1,1,1,1},{0,1,0,0,1,1,1,1},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,1},{0,0,0,0,1,0,0,1},{0,0,0,0,1,1,1,1}};
	answer = solution(arr);
	cout << answer[0] << " / " << answer[1] << endl;
	return 0;
}