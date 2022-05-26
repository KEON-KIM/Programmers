#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pQue;
    for(int s : scoville)
    	pQue.push(s);

    while(!pQue.empty())
    {
    	if(pQue.top() >= K) pQue.pop();
    	else
    	{
    		int a = pQue.top();
    		cout << a << endl;
    		pQue.pop();
    		int b = pQue.top();
    		pQue.pop();

    		pQue.push(a + (b * b));
    		answer++;
    	}
    }

    return answer;
}
int main()
{
	vector<int> scoville = {1, 2, 3, 9, 10, 12};

	cout << solution(scoville, 7);
	return 0;
}