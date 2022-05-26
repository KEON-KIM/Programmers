#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int result, N;
bool visited[8];
char names[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
vector<string> Data;
bool ischeck(string group)
{
	for(string str : Data)
	{
		int a , b;
		a = b = -1;
		int index = str[4] - '0';
		char op = str[3];

		FOR(i, group.length())
		{
			if(group[i] == str[0]) a = i;
			if(group[i] == str[2]) b = i;
			if(a != -1 && b != -1) break;
		}

		if(op== '<')
		{
			if(!(abs(a - b) < index + 1)) return false;
		}
		
		else if(op == '>')
		{
			if(!(abs(a - b) > index + 1)) return false;
		}

		else if(op == '=')
		{
			if(!(abs(a - b) == index + 1)) return false;
		}
	}

	return true;
}

void dfs(string group)
{
	if(group.length() == 7)
	{
		if(ischeck(group)){
			result++;
		}return;
	}
	FOR(i, 8)
	{
		if(!visited[i])
		{
			visited[i] = true;
			dfs(group + names[i]);
			visited[i] = false;
		}
	}
}

int solution(int n, vector<string> data) {
	Data = data;
	result = 0;
    int answer = 0;
	memset(visited, false, sizeof(visited));

	dfs("");
    answer = result;
    return answer;
}

int main()
{
	vector<string> data = {"N~F=0", "R~T>2"};
	cout << solution(2, data) << endl;
	return 0;
}