#include <string>
#include <vector>
#include <iostream>

#define FOR(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    int l, r, cnt; // que1_ptr, que2_ptr
    l = r = cnt = 0;
    ll lval = 0, rval = 0;
    FOR(i, queue1.size())
    {
    	lval += queue1[i];
    	rval += queue2[i];
    }
    while(true)
    {
    	if(l >= queue1.size() || r >= queue2.size()) break;
    	if(lval > rval)
    	{
    		rval += queue1[l];
    		lval -= queue1[l];
    		queue2.push_back(queue1[l++]);
    	}
    	else if(lval < rval)
    	{
    		lval += queue2[r];
    		rval -= queue2[r];
    		queue1.push_back(queue2[r++]);
    	}
    	else return cnt;
    	cnt++;
    }

    return answer;
}

int main()
{
	vector<int> queue1
		// = {3, 2, 7, 2};
		= {1, 2, 1, 2};
		// = {1,1,1,8,10,9}; 
		// = {1, 1};

	vector<int> queue2
		// = {4, 6, 5, 1};
		= {1, 10, 1, 2};
		// = {1,1,1,1,1,1};
		// = {1, 5};

	cout << solution(queue1, queue2) << endl;
	return 0;
}