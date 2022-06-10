#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
	int len = prices.size();
    vector<int> answer;
    stack<int> St; // idx, value;

    answer.resize(len);
    for(int i = 0; i < len; i++)
    {
    	if(!St.empty())
    	{
    		while(!St.empty())
    		{
    			int idx = St.top();
    			if(prices[idx] <= prices[i]) break;
    			St.pop();
    			answer[idx] = i - idx;
    		}
			St.push(i);
    	}
    	else
    		St.push(i);
    }

    while(!St.empty())
    {
    	int idx = St.top();
    	St.pop();
    	answer[idx] = len - idx - 1;
    }

    return answer;
}
int main()
{
	// vector<int> prices = {1, 2, 3, 2, 3};
	vector<int> prices = {4, 5, 3, 4, 2, 1};
	vector<int> answer = solution(prices);
	for(int i : answer)
		cout << i << " ";
	cout << endl;
	return 0;
}