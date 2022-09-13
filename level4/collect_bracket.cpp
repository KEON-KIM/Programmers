#include <string>
#include <vector>
#include <iostream>
#include <set>

#define MAX 16
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;


int solution(int n)
{
	int dp[MAX] = {0, };
	dp[0] = dp[1] = 1;
	for(int i = 2; i <= n; i++)
		for(int j = 1; j <= i; j++)
			dp[i] += (dp[j-1] * dp[i-j]);
	return dp[n];
}
/*int solution(int n) {
    int answer = 0;
    set<string> dp[15];
    dp[0].insert("()");
    FOR(i, n-1)
    {
    	for(auto it : dp[i])
    	{
    		for(int j = 0; j < it.size(); j++)
    		{
    			string tmp = "";
    			for(int k = 0; k < j; k++)
    			{
    				tmp += it[k];
    			}
    			tmp += "()";
    			for(int k = j; k < it.size(); k++)
    			{
    				tmp+= it[k];
    			}
    			dp[i+1].insert(tmp);
    		}
    		dp[i+1].insert("("+it+")");
    	}

    	for(auto it : dp[i+1])
    		cout << it << endl;
    }
    answer = dp[n-1].size();
    return answer;
}*/

int main()
{
	cout << solution(4);
	return 0;
}