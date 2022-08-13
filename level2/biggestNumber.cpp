#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
//Project R - Project LLL - 글로벌프로덕션실
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;
string solution(vector<int> numbers) {
    string answer = "";
    priority_queue<pair<int, string>> pQue;
    for(int i : numbers){
    	string tmp = to_string(i);
    	string str = tmp;
    	int idx = 0;
    	while(tmp.length() <= 3)
    		tmp += str[idx++%str.length()];
    	
    	pQue.push({stoi(tmp), str});
    }

    while(!pQue.empty())
    {
		answer += pQue.top().second;
    	pQue.pop();
    }
    if(answer[0] == '0') answer = "0";
    return answer;
}

int main()
{
	// vector<int> numbers = {6, 10, 2};
	// vector<int> numbers = {3, 30, 34, 5, 9};
	// vector<int> numbers = {41,4140};
	vector<int> numbers = {0, 0};
	// vector<int> numbers = {41, 411, 412, 4114};
	cout << solution(numbers) << endl;
	return 0;
}