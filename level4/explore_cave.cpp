#include <string>
#include <vector>
#include <iostream>
#include <map>

#define MAX 100001
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

bool visited[MAX] = {false, };
vector<int> graph[MAX];
map<int, int> before;
map<int, int> prevNode;
void dfs(int idx, vector<vector<int>> &path, vector<vector<int>> &order)
{
    if(!visited[before[idx]]) // 현재 방문 노드가 막혀있다면
    {
        prevNode[before[idx]] = idx;
        return;// 추후 뚫어주길 기다린다.
    }

    visited[idx] = true;
    if(prevNode[idx]) // 현재 노드가 뚫을 수 있는 노드라면
        dfs(prevNode[idx], path, order); // 뚫은 노드부터 탐색을 다시 시작한다.
    
    FOR(i, graph[idx].size())
        if(!visited[graph[idx][i]])
            dfs(graph[idx][i], path, order);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    FOR(i, path.size())
    {
        graph[path[i][0]].push_back(path[i][1]);
        graph[path[i][1]].push_back(path[i][0]);
    }

    FOR(i, order.size())
        before[order[i][1]] = order[i][0];
    
    visited[0] = true;
    FOR(i, graph[0].size())
        dfs(graph[0][i], path, order);

    FOR(i, n)
        if(!visited[i]) return false;
    return true;
}

int main()
{
    vector<vector<int>> path
        = {{0,1},{0,3},{0,7},{8,1},{3,6},{1,2},{4,7},{7,5}};
        // = {{8,1},{0,1},{1,2},{0,7},{4,7},{0,3},{7,5},{3,6}};
        // = {{0,1},{0,3},{0,7},{8,1},{3,6},{1,2},{4,7},{7,5}};

    vector<vector<int>> order
        = {{8,5},{6,7},{4,1}};
        // = {{4,1},{5,2}};
        // = {{4,1},{8,7},{6,5}};

    cout << solution(9, path, order);
    return 0;
}