#include <string>
#include <vector>
#include <iostream>

#define MAX 501
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int dp[MAX][MAX] = {0, };
    dp[0][0] = triangle[0][0];
    FOR(i, triangle.size()-1)
    {
    	FOR(j, triangle[i].size())
    	{
    		dp[i+1][j] = max(dp[i+1][j], triangle[i+1][j]+dp[i][j]);
    		dp[i+1][j+1] = max(dp[i+1][j+1], triangle[i+1][j+1] + dp[i][j]);

    		answer = max(answer, max(dp[i+1][j], dp[i+1][j+1]));
    	}
    }
    FOR(i, triangle.size())
    {
    	FOR(j, triangle[i].size())
    	{
    		cout << dp[i][j] << " ";
    	}
    	cout << endl;
    }
    return answer;
}

int main()
{
	vector<vector<int>> triangle
		= {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};

	cout << solution(triangle);
	return 0;
}