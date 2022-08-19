#include <string>
#include <vector>
#include <iostream>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define nFOR(i, k, n) for(int i = k; i < n; i++)
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
	int answer = 0;
	vector<vector<int>> temp;
	temp.resize(board.size()+1, vector<int>(board[0].size()+1, 0)); // 0으로 초기화
	FOR(i, skill.size())
	{
		int x1, x2, y1, y2, degree;
		x1 = skill[i][1], y1 = skill[i][2];
		x2 = skill[i][3], y2 = skill[i][4];
		degree = skill[i][5];
		if(skill[i][0] == 1) // 파괴
		{
			degree *= -1;
			temp[x1][y1] += degree;
			temp[x1][y2+1] += -degree;
			temp[x2+1][y1] += -degree;
			temp[x2+1][y2+1] += degree;
		}
		else // 회복
		{
			temp[x1][y1] += degree;
			temp[x1][y2+1] += -degree;
			temp[x2+1][y1] += -degree;
			temp[x2+1][y2+1] += degree;
		}
	}
	FOR(i, temp.size())
		nFOR(j, 1, temp[0].size())
			temp[i][j] += temp[i][j-1];


	FOR(i, temp[0].size())
		nFOR(j, 1, temp.size())
			temp[j][i] += temp[j-1][i];

	FOR(i, board.size())
		FOR(j, board[0].size())
			if(board[i][j] + temp[i][j] <= 0) 
				answer++;

	return (board.size() * board[0].size()) - answer;
}

int main()
{
	vector<vector<int>> board
		= {{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5}};
		// = {{1,2,3},{4,5,6},{7,8,9}};

	vector<vector<int>> skill
		= {{1,0,0,3,4,4},{1,2,0,2,3,2},{2,1,0,3,1,2},{1,0,1,3,3,1}};
		// = {{1,1,1,2,2,4},{1,0,0,1,1,2},{2,2,0,2,0,100}};

	cout << solution(board, skill);
	return 0;
}