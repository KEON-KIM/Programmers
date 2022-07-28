#include <string>
#include <vector>
#include <queue>
#include <map>
// #include <set>
#include <algorithm>
#include <iostream>
#include <typeinfo>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

vector<string> result;
bool dfs(string start, int cnt, int dist, vector<string> &answer, map<string, vector<pair<string, bool>>> &board)
{
    if(cnt == dist) {
        answer.push_back(start);
        result = answer; 
        return true;
    }

    FOR(i, board[start].size())
    {
        if(!board[start][i].second)
        {
            answer.push_back(start);
            board[start][i].second= true;
            if(dfs(board[start][i].first, cnt+1, dist, answer, board))
            {
                return true;
            }
            answer.pop_back();
            board[start][i].second = false;

        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    map<string, vector<pair<string, bool>>> board;
    vector<string> listVector;
    for(vector<string> v : tickets){
        board[v[0]].push_back({v[1], false});
        listVector.push_back(v[0]);
    }
    FOR(i, listVector.size())
    {
        sort(board[listVector[i]].begin(), board[listVector[i]].end());
    }

    dfs("ICN", 0, tickets.size(), answer, board);
        
    return answer;
}

int main()
{
    vector<vector<string>> tickets =
        // {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
        {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}};
    vector<string> answer = solution(tickets);
    FOR(i, answer.size())
        cout << answer[i] << " ";
    cout << endl;
    return 0;
}