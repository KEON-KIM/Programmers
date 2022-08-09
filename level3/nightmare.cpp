#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

typedef long long ll;
ll solution(int n, vector<int> works) {
	priority_queue<int> pQue;
    ll answer = 0;
	for(int i : works)
		pQue.push(i);
	while(n)
	{
		int x = pQue.top();
		pQue.pop();
		pQue.push(--x);
		--n;
	}
	while(!pQue.empty())
	{
		cout << pQue.top() << endl;
		answer+=pow(pQue.top()>=0? pQue.top():0,2);
		pQue.pop();
	}
    return answer;
}

int main()
{
	vector<int> works 
	// = {4, 3, 3};
	= {1, 1};
	cout << solution(3, works);
	return 0;
}