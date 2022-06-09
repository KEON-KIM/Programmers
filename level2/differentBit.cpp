#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define INF 101
using namespace std;

typedef long long ll;
ll btol(string str)
{
	ll result = 0;
	
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == '1')
			result += pow(2, i);
	}
	return result;
}
vector<ll> solution(vector<ll> numbers) {
    vector<ll> answer;

    for(ll l : numbers)
    {
    	if(l < 2)
    	{
    		if(l == 0)
    			answer.push_back(1);
    		else
    			answer.push_back(2);
    		continue;
    	}
    	int idx = 0;
    	int lz, rz, lo; 
    	lz = INF; lo = rz = -1;
    	string tmp = "";

    	while(l > 1)
    	{
    		if(l%2){
    			if(idx < lz || idx < rz)
    				lo = max(idx, lo);
    		}
    		else
    		{
    			lz = min(lz, idx);
    			rz = max(rz, idx);
    		}
    		tmp += ((l%2) + '0');
    		l /= 2;
    		idx++;
    	}
		tmp += '1';

    	if(rz == -1)
    	{
    		tmp += '1';
    		tmp[idx] = '0';
    	}
    	else if(lo != -1) // 일반 경우 
    	{
    		tmp[lo] = '0';
    		tmp[lz] = '1';
    	}

    	else //(lo == -1) // 0이 왼쪽에 치우칠 경우
    		tmp[lz] = '1';
    	
    	answer.push_back(btol(tmp));
    }

    return answer;
}

int main()
{
	// vector<ll> numbers = {2, 7, 8};
	vector<ll> numbers = {1001,337,0,1,333,673,343,221,898,997,121,1015,665,779,891,421,222,256,512,128,100};
	vector<ll> res = solution(numbers);

	for(ll l: res)
		cout << l << endl;

	return 0;
}