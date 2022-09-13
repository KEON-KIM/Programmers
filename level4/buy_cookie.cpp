#include <string>
#include <vector>
#include <iostream>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int solution(vector<int> cookie) {
    int answer = 0, sum = 0;
    FOR(i, cookie.size()) sum += cookie[i];
    FOR(i, cookie.size()-1)
    {
    	int l = i, r = i+1;
    	int lsum = cookie[l], rsum = cookie[r];
    	while((rsum <= sum/2 && lsum <= sum/2) && (l > -1 && r < cookie.size()))
    	{
    		if(rsum > lsum) 
    			lsum += cookie[--l];
    		else if(lsum > rsum)
    			rsum += cookie[++r];

    		else
    		{
    			answer = max(answer, rsum);
    			lsum += cookie[--l];
    			rsum += cookie[++r];
    		}
    	}
    }

    return answer;
}

int main()
{
	vector<int> cookie
		= {1, 1, 2, 3};
		// = {1, 2, 4, 5};
	cout << solution(cookie);
	return 0;
}