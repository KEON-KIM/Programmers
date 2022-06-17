#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 102
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

bool visited[MAX]; // visited : power shell
vector<int> board[MAX];
int bfs(int start, vector<vector<int>> &wires)
{
    visited[start] = true;
    queue<int> Que;
    Que.push(start);

    int cnt = 0;
    while(!Que.empty())
    {
        int x = Que.front();
        Que.pop();
        
        for(int i : board[x])
        {
            if(!visited[i])
            {
                visited[i] = true;
                Que.push(i);
                cnt++;
            }
        }
    }

    return cnt;
}

void Reset(int n)
{
    for(int i = 1; i <= n; i++)
        board[i].clear();
    memset(visited, false, sizeof(visited));
}

int solution(int n, vector<vector<int>> wires) {
    int answer = MAX;
    FOR(i, wires.size())
    {
        Reset(n);
        FOR(j, wires.size())
        {
            if(i == j) continue;
            board[wires[j][0]].push_back(wires[j][1]);
            board[wires[j][1]].push_back(wires[j][0]);
        }
        
        vector<int> tmp;
        for(int j = 1; j <= n; j++) // explore to all power shell
        {
            if(!visited[j]){
                cout << j << endl;
                tmp.push_back(bfs(j, wires));
            }
        }
        answer = min(answer, abs(tmp[0] - tmp[1]));
        
        // reset
       
    }
    
    return answer;
}

int main()
{
    vector<vector<int>> wires
        // = {{1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9}};
        = {{1, 2}, {2, 7}, {3, 7}, {3, 4}, {4, 5}, {6, 7}};
    cout << solution (wires.size()+1, wires);
    return 0;
}