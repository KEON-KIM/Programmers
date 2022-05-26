#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N;
char number[4] = {'-','1', '2', '4'};
string Recursion(int idx, int num, string result)
{
	for(int i = 3; i > 0; i--)
	{
		if(pow(3, idx) * i <= num &&
			pow(3, idx-1) + pow(3, idx-1)/2 -1 < num - (pow(3, idx) * i))
		{

			cout << i << endl;
			result += number[i];
			if(idx == 0) return result;
			else return Recursion(idx-1, num - (pow(3, idx) * i), result);
		}
	}
}
string solution(int n) {
    string answer = "";
    for(int i = 19; i >= 0; i--)
    {
    	if(pow(3, i) + pow(3, i)/2 -1 < n)
    	{
    		// cout << i << endl;
    		answer = Recursion(i, n, "");
    		break;
    	}
    }

    return answer;
}

int main()
{
	cin >> N;
	cout << solution(N);
	return 0;
}