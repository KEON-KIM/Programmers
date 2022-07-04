#include <string>
#include <vector>
#include <iostream>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int maxScore = 0, minIndex = 0;
int scoreBoard[11] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
vector<int> result;
void print(vector<int> &answer)
{
	for(int i : answer)
		cout << i << " ";
	cout << endl;
}
void dfs(int n, int idx, vector<int> &info, vector<int> &answer)
{
	cout << n << ' ' << idx << ' ' << endl;
	if(n == 0 || idx > 10)
	{
		int score = 0, min = 0;
		cout << "=================" << endl;
		print(answer);
		FOR(i, 11)
		{
			if(answer[i]) min = i;
			if(info[i] > answer[i])
				score -= scoreBoard[i];
			else if(info[i] < answer[i])
				score += scoreBoard[i];
		}
		cout << "-----SCORE : " << score << endl;
		if(maxScore <= score && minIndex < min)
		{
			cout << "CHANGE !!" << endl;
			maxScore = score;
			result = answer;
		}
		return;
	}

	// win;
	if(n - (info[idx]+1) >= 0) // 승리할 수 있음
	{ 
		answer[idx] = (info[idx]+1); // 승리할 수 있는 최소 조건
		dfs(n - (info[idx]+1),  idx + 1, info, answer);
		answer[idx] = 0;
	}
	// lose
	dfs(n, idx + 1, info, answer);
}
vector<int> solution(int n, vector<int> info) {
    vector<int> answer(11);
    result.resize(11);

    dfs(n, 0, info, answer);

    if(!maxScore) return {-1};
    int tmp = 0;
    FOR(i, 11)
    	tmp += result[i];
    if(tmp != n)
    	result[10] = n - tmp;
    return result;
}

int main()
{
	vector<int> info
		// = {2,1,1,1,0,0,0,0,0,0,0}; // 5
		// = {1,0,0,0,0,0,0,0,0,0,0}; // 1
		// = {0,0,1,2,0,1,1,1,1,1,1}; // 9
		= {0,0,0,0,0,0,0,0,3,4,3}; // 10
		// = {0,0,1,1,0,0,0,0,0,1,0}; // 3

	vector<int> answer 
		= solution(10, info);
	cout << "maxScore : " << maxScore << endl;
	for(int i : answer)
		cout << i << " ";
	cout << endl;
	return 0;
}