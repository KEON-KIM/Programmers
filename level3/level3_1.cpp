#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


long long solution(int n, vector<int> times)
{
	sort(times.begin(), times.end());
	
	int size = times.size(), estimate, total;
	int min_ = times[0] * (n/size);
	int max_ = times[size-1] * (n/size);


	while(min_ < max_)
	{
		total = 0;
		estimate = (max_ + min_)/2;
		for(int i : times) total += estimate/i;

		if( total < n)
			min_ = estimate + 1;
		else
			max_ = estimate;
	}
	return min_;
}

int main()
{
	cout << solution(6, {7,10}) << endl;
	cout << solution(10, {2,5,6,7}) << endl;
	cout << solution(18, {2,5,6,7}) << endl;
	cout << solution(4, {7,101}) << endl;
	return 0;
}