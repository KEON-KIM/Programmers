#include <string>
#include <vector>
#include <iostream>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N;
vector<pair<int, int>> Queen;
bool cols[12] = {false, };
bool visited[12][12] = {false, };
bool isPut(int curX, int curY)
{
    for(pair<int, int> p : Queen)
    {
        int x = p.first;
        int y = p.second;
        if(curY == y - (curX-x) || curY == y + (curX-x)) 
            return false;
    }
    
    return true;
}
int dfs(int x, int y, int depth)
{
    int cnt = 0;
    if(depth == N-1) return 1;
    
    FOR(i, N)
    {
        if(cols[i]) continue;
        if(isPut(x+1, i))
        {
            cols[i] = true;
            Queen.push_back({x+1, i});
            cnt += dfs(x+1, i, depth+1);
            Queen.pop_back();
            cols[i] = false;
        }
    }
    
    return cnt;
}
int solution(int n) {
    N = n;
    int answer = 0;
    FOR(i, n)
    {
        cols[i] = true;
        Queen.push_back({0, i});
        answer += dfs(0, i, 0);
        Queen.pop_back();
        cols[i] = false;
    }
    return answer;
}

int main()
{
    cout << solution(10);
    return 0;
}