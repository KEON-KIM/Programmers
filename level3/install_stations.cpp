#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int start = 1;
    for(int i = 0; i < stations.size(); i++)
    {
    	if(start < stations[i] - w - 1)
    		answer += (((stations[i] - w - 1) - start)/((w*2)+1)) + 1;
    	start = stations[i] + w + 1;

    	if(start < n && i == stations.size()-1)
    		answer += ((n - start)/((w*2)+1)) + 1;
    	
    }
    return answer;
}

int main()
{
	vector<int> stations 
		// = {4, 11};
		// = {9};
		= {3, 9, 13};
	cout << solution(15, stations, 2);
	return 0;
}