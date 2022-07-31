#include <string>
#include <vector>
#include <iostream>
 
using namespace std;

#define MAX 102
#define FOR(i, n) for(int i = 1; i <= n; i++) 
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    bool graph[MAX][MAX] = {false, };
    for (vector<int> v : results)  graph[v[0]][v[1]] = true;
    FOR(i, n) {
        FOR(j, n) {
            FOR(k, n) {
                if (graph[j][i] && graph[i][k]) {
                    graph[j][k] = true;
                }
            }
        }
    }
    
    FOR(i, n) 
    {
        int count = 0;
        FOR(j, n) 
            if (graph[i][j] || graph[j][i]) 
                count++;

        if (count == n - 1) answer++;
    }

    return answer;
}


int main()
{
    vector<vector<int>> results
        = {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}};
    cout << solution(5, results);
    return 0;
}