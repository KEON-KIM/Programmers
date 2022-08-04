#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
 
using namespace std;
 
typedef vector<int> v;

struct cmp {
    bool operator()(v a, v b) {
        return a[1] > b[1];
    }
};
 
int solution(vector<v> jobs) {
    int answer = 0,  i = 0, curTime = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<v, vector<v>, cmp> pQue;

    while (i < jobs.size() || !pQue.empty()) 
    {
        if (jobs.size() > i && curTime >= jobs[i][0]) 
        {
            pQue.push(jobs[i++]);
            continue;
        }
        if (!pQue.empty()) 
        {
            curTime += pQue.top()[1];
            answer += curTime - pQue.top()[0];
            pQue.pop();
            cout << curTime << endl;
        }
        else
            curTime = jobs[i][0];
    }

    return answer / jobs.size();
}
int main()
{
	vector<v> jobs
		// = {{0, 3}, {1, 9}, {2, 6}};
	// = {{0, 3}, {2, 9}, {3, 6}};
	= { {15, 34}, {24, 10}, {28, 39}, {43, 20}, {37, 5}, {47, 22}, {20, 47}, {15, 2}, {35, 43}, {26, 1}};
	 // = {{0, 6}, {0, 8}, {7, 1}};
	cout << solution(jobs);
	return 0;
}