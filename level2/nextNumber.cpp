#include <iostream>
#include <string>
#include <vector>

#define MAX 1000001
using namespace std;
int binary(int n)
{
	int res = 0;
	while(n > 1)
	{
		if(n%2) res++;
		n /= 2;
	}
	if(n) res++;
	return res;
}

int solution(int n) {
    int answer = 0;
    int res = binary(n);
    for(int i = n + 1; i < MAX; i++)
    {
    	if(res == binary(i))
    	{
    		answer = i;
    		break;
    	}
    }

    return answer;
}

int main()
{
	cout << solution(78);
	return 0;
}