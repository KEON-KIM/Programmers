#include <string>
#include <vector>
#include <iostream>
#include <queue>

#define MAX 501
#define INF 1000000
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

bool visited[MAX] = {false, };
int dfs(int curTime, int answer, vector<vector<int>> &jobs)
{
	int minValue = INF;
	int idx = -1;
	FOR(i, jobs.size())
	{
		if(jobs[i][0] <= curTime && !visited[i])
		{
			if(minValue > (jobs[i][1] + curTime) - jobs[i][0])
			{
				idx = i;
				minValue = (jobs[i][1] + curTime) - jobs[i][0];
			}
		}
	}
	if(idx == -1) return answer;
	
	visited[idx] = true;
	answer = dfs(curTime + jobs[idx][1], answer + minValue, jobs);
	return answer;
}
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    answer = dfs(0, 0, jobs);

    return answer/ jobs.size();
}

int main()
{
	vector<vector<int>> jobs
		= {{0, 3}, {1, 9}, {2, 6}};
	cout << solution(jobs);
	return 0;
}