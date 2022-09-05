#include <cstring>
#include <vector>
#include <limits>
#include <iostream>
#include <queue>

#define MAX 300002
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

int dp[MAX];
vector<int> graph[MAX];
int dfs(int n, vector<int> &sales)
{
    if(graph[n].empty()) return 0;
    int &ret = dp[n];
    if(ret != -1) return ret;

    ret = 1<<31 - 1;
    int s = 0; // select
    FOR(i, graph[n].size())
    {
        int next = graph[n][i];
        s += dfs(next, sales); // 최소 subRoot값 모두 저장
    }

    ret = min(ret, s + sales[n-1]); // 자신 노드 포함 

    FOR(i, graph[n].size())
    {
        int next = graph[n][i];
        int dts = s - dfs(next, sales); // 자신 노드 don't select
        dts += sales[next-1];

        FOR(j, graph[next].size())
        {
            int nnext = graph[next][j]; // next -> next
            if(!graph[nnext].empty())
               dts += dfs(nnext, sales);
        }

        ret = min(ret, dts);
    }

    return ret;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    FOR(i, links.size())
        graph[links[i][0]].push_back(links[i][1]); // grapth(A).push_back(B) : A는 B노드를 갖고 있다.

    memset(dp, -1, sizeof(dp));
    return dfsa(1, sales);
}

int main()
{
    vector<int> sales
        = {14, 17, 15, 18, 19, 14, 13, 16, 28, 17};
        // = {5, 6, 5, 3, 4};
        // = {5, 6, 5, 1, 4};
        // = {10, 10, 1, 1};

    vector<vector<int>> links
        = {{10, 8}, {1, 9}, {9, 7}, {5, 4}, {1, 5}, {5, 10}, {10, 6}, {1, 3}, {10, 2}};
        // = {{2,3}, {1,4}, {2,5}, {1,2}};
        // = {{2,3}, {1,4}, {2,5}, {1,2}};
        // = {{3,2}, {4,3}, {1,4}};

    cout << solution(sales, links);
    return 0;
}