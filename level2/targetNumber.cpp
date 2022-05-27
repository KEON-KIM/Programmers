#include <iostream>
#include <cstring>
#include <vector>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int result;
bool visited[20];
vector<int> board;
void dfs(int idx, int sum, int target)
{
	if(idx == board.size())
	{
		if(sum == target)result++;
		return;
	}
	
		// visited[idx] = true;
	dfs(idx + 1, sum + board[idx], target);
	dfs(idx + 1, sum - board[idx], target);
		// visited[idx] = false;
	
	
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    result = 0;
    board = numbers;
    memset(visited, false, sizeof(visited));
    dfs(0, 0, target);
    answer = result;
    return answer;
}

int main()
{
	vector<int> numbers = {1, 1, 1, 1, 1};
	cout <<	solution(numbers, 3);

	return 0;
}