#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define MAX 10000000

using namespace std;

int len;
string str;
bool prime[MAX] = {false, };
bool number[MAX] = {false, }; // visited checking
bool visited[8] = {false, };
void checkPrime()
{
	for(int i = 2; i < MAX; i++)
	{
		for(int j = 2; j * i < MAX; j++)
		{
			if(!prime[i*j])
			{
				prime[i*j] = true;
			}
		}
	}
}
int dfs(string val)
{
	int count = 0;
	int v = 0;
	cout << val << endl;
	if(val.length() > len) return count;
	if(val.length() > 0)
		v = stoi(val);
	if(!prime[v]) count++;
	
	for(int i = 0; i < len; i++)
	{
		string tmp = val;
		tmp += str[i];
		int key = stoi(tmp);
		if(key >= MAX) continue;
 		if(!number[key] && !visited[i])
		{
			number[key] = true;
			visited[i] = true;
			count += dfs(tmp);
			visited[i] = false;
		}
	}

	return count;
}
int solution(string numbers) {
	int answer = 0;
	prime[0] = true;
	prime[1] = true;
	str = numbers;
	len = numbers.length();
	checkPrime();

    answer = dfs(""); // val, idx, dep;
    return answer;
}

int main()
{
	// string numbers = "17";
	string numbers = "011";
	cout << solution(numbers) << endl;
}