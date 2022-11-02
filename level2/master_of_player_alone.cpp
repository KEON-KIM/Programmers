#include<algorithm>
#include<iostream>
#include<vector>

#define endl '\n'
#define MAX 102
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;
vector<int> board[MAX];
bool visited[MAX] = {false, };
void dfs(int idx, int cur, vector<int> cards)
{
	if(visited[cur]) return;
	else
	{
		int next = cards[cur-1];
		visited[cur] = true;
		board[idx].push_back(cur);
		dfs(idx, next, cards);
	}
}
int solution(vector<int> cards)
{
	vector<int> v;
	int answer = 0, dep = 0;
	FOR(i, cards.size())
	{
		if(!visited[cards[i]])
		{
			dfs(++dep, cards[i], cards);
			v.push_back(board[dep].size());
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	if(dep == 1) return 0;
	else return v[0] * v[1];
	
	return answer;
}
int main()
{	
	vector<int> cards = {8,6,3,7,2,5,1,4};
	cout << solution(cards);
	return 0;
}