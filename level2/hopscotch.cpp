#include <iostream>
#include <vector>

#define MAX 100001
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int board[4];
void print()
{
	FOR(i, 4)
		cout << board[i] <<" /";
	cout << endl;
}
int solution(vector<vector<int>> land)
{
    int answer = 0;
    int N = land.size();
    FOR(i, 4) board[i] = land[N-1][i];
    print();
    for(int i = N - 2; i >= 0; i--)
    {
    	int temp[4];
    	FOR(j, 4)
    	{
    		int tmp = board[j];
    		FOR(k, 4)
    		{
    			if(j == k) continue;
    			tmp = max(tmp, board[k] + land[i][j]);
    			answer = max(answer, tmp);
    		}
    		temp[j] = tmp;
    	}
    	FOR(j, 4)
    		board[j] = temp[j];
    }

    return answer;
}

int main()
{
	vector<vector<int>> land = {{1,2,3,5},{5,6,7,8},{4,3,2,1}};
	cout << solution(land);
	return 0;
}