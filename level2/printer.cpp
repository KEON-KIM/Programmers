#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int len = priorities.size();
    priority_queue<int> pQue;
    deque<pair<int ,int>> dQue;
    FOR(i, len)
    {
        pQue.push(priorities[i]);
        dQue.push_back({i, priorities[i]});
    }

    while(!dQue.empty())
    {
        int idx = dQue.front().first;
        int pri = dQue.front().second;
        dQue.pop_front();

        if(pri >= pQue.top())
        {
            pQue.pop();
            answer++;
            if(idx == location) break;
            continue;
        }
        dQue.push_back({idx, pri});
    }
    return answer;
}

int main()
{
    // vector<int> priorities = {2, 1, 3, 2};
    vector<int> priorities = {1, 1, 9, 1, 1, 1};

    cout << solution(priorities, 0);
    return 0;
}