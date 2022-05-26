#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> Que;
    FOR(i, progresses.size())
    	Que.push((int)ceil((float)(100 - progresses[i])/(float)speeds[i]));
    

    int cnt = 0, timer = Que.front();
    while(!Que.empty())
    {
        if(Que.front() <= timer)
        {
            while(Que.front() <= timer && !Que.empty())
            {
                Que.pop();
                cnt++;
            }
        }
        else
        {
            answer.push_back(cnt);
            timer = Que.front();
            cnt = 0;
        }
    }
    if(cnt) answer.push_back(cnt);
    return answer;
}

int main()
{
	vector<int> progresses = {93, 30, 55};
	vector<int> speeds = {1, 30, 5};
	// vector<int> progresses = {95, 90, 99, 99, 90, 89, 80, 99};//, 39, 48, 0};
	// vector<int> speeds = {1, 1, 1, 1, 1, 1, 1, 1};//, 1, 2, 1};
	vector<int> answer = solution(progresses, speeds);
	for(int i : answer) cout << i << " ";

	return 0;
}