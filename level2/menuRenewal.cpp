#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

#define LEN 11
#define MAX 21
#define ALPHA 26
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

int orderSize[LEN] = {0, };
bool alpha[MAX][ALPHA];
bool visited[ALPHA];
map<string, int> countMenu;
vector<string> orderVector;
void dfs(string str, int len, int index, int order)
{
	// cout << str << endl;
	if(str.length() == len)
	{
		// cout << str << endl;
		countMenu[str]++;
		orderSize[len] = max(orderSize[len], countMenu[str]);
		// string tmp = str;
		// sort(tmp.begin(), tmp.end());
		// if(tmp != str) return;
		// if(countMenu.find(str) != countMenu.end()) 
		// {
		// 	countMenu[str]++;
		// 	orderSize[str.length()] = max(orderSize[str.length()], countMenu[str]);
		// }
		// else countMenu.insert({str, 0});
		return;
	}
	for(int i = index; i < orderVector[order].length(); i++)
	{
		string tmp = str;
		tmp += orderVector[order][i];
		// cout << tmp << endl;
		dfs(tmp, len, i+1, order);
	}
	/*for(char c : orderVector[order])
	{
		if(!visited[c - 'A'])
		{
			string tmp = str;
			tmp += c;
			visited[c - 'A'] = true;
			dfs(tmp, len, order);
			visited[c - 'A'] = false;
		}
	}*/

	/*for(int i = 0; i < ALPHA; i++)
		if(alpha[order][i] && !visited[i])
		{
			visited[i] = true;
			dfs(str + (char)('A' + i ), len, order);	
			visited[i] = false;
		}*/
}

vector<string> solution(vector<string> orders, vector<int> course) 
{
	vector<string> answer;
	orderVector = orders;
	memset(alpha, false, sizeof(alpha));
   	FOR(i, orders.size())
    {
    	sort(orderVector[i].begin(), orderVector[i].end());
    	// int l = orders[i].length();
    	// maxLen = max(maxLen, l);
    	// for(char c : orders[i])
    	// 	alpha[i][c - 'A'] = true;
    	for(int len : course)
			dfs("", len, 0, i);
    }
    vector<pair<int, string>> sorted;
    for(auto iter : countMenu)
    	if(iter.second > 1)
    		sorted.push_back({iter.second, iter.first});

    for(pair<int, string> p : sorted)
    	if(p.first == orderSize[p.second.length()])
    		answer.push_back(p.second);
    
    	/*int len = iter.first.length();
    	int cnt = iter.second;
    	if(cnt && cnt == orderSize[len])
    		answer.push_back(iter.first);*/
    

    sort(answer.begin(), answer.end());
    return answer;
}


int main()
{
	// vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
	vector<string> orders = {"XYZ", "XWY", "WXA"};
	vector<int> course = {2, 3, 4};
	vector<string> result;
	result = solution(orders, course);
	for(string str : result)
		cout << str << endl;

	for(int i : course)
		cout << orderSize[i] << " "; 
	return 0;
}
/*#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 11
#define ALPHA 26
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

int orderSize[MAX];
vector<int> alpha[ALPHA];
vector<pair<int, string>> answer[11];
//orders 배열의 각 원소는 크기가 2 이상 10 이하인 문자열입니다.
vector<string> order;
int ischeck(string str)
{
	int res = 0;
	FOR(i, ALPHA)
	{
		int cnt = 0;
		for(char c : str)
		{
			int val = c - 'A';
			auto it = find(alpha[val].begin(), alpha[val].end(), i);
			if(it != alpha[val].end()) cnt++;
		}
		if(cnt == str.length()) res++;
	}
	return res;
}
void dfs(int idx, string str, int menu)
{
	if(str.length() >= menu)
	{
		int cnt = ischeck(str);
		if(cnt >= 2 && cnt >= orderSize[str.length()])
		{
			orderSize[str.length()] = cnt;
			answer[str.length()].push_back({cnt, str});
		}
		return;
	}

	for(int i = idx; i < ALPHA; i++)
		if(alpha[i].size() > 0)
			dfs(i+1, str + (char)('A' + i ), menu);	
		
}

vector<string> solution(vector<string> orders, vector<int> course) 
{
    vector<string> result;
	order = orders;
   	FOR(i, orders.size())
    {
    	for(char c : orders[i])
    		alpha[c - 'A'].push_back(i);
    	
    }
    FOR(i, orders.size())
    	orderSize[orders[i].length()] = ischeck(orders[i]);

    for(int i : course)
    	dfs(0, "", i);
    
    for(int i = 2; i < MAX; i++)
        for(pair<int, string> p : answer[i])
            if(orderSize[i] == p.first)
                result.push_back(p.second);
        
    
    sort(result.begin(), result.end());
    return result;
}*/