#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define MAX 1001
#define INF 100001
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;
vector<int> tree[MAX];
bool visited[MAX] = {false, };
typedef pair<int, pair<int, int>> pipii;

void dfs(int idx, int dep, vector<vector<int>> &answer)
{
    answer[0].push_back(idx);

    if(dep < MAX){
        FOR(i, tree[dep].size())
        {
            if(!visited[tree[dep][i]]){
                visited[tree[dep][i]] = true;
                dfs(tree[dep][i], dep+1, answer);
            }
        }
    }
   
    answer[1].push_back(idx);
}

auto bigger = [](pipii &A, pipii &B) -> bool
{
    if(A.first == B.first)
        return A.second.first > B.second.first;
    else
        return A.first < B.first;
};
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer = {{}, {}};
    priority_queue<pipii, vector<pipii>, decltype(bigger)> pQue(bigger); //y, {x, index}
    
    FOR(i, nodeinfo.size()){
        pQue.push({nodeinfo[i][1],{nodeinfo[i][0], i+1}});
        cout << "?" << endl;
    }
    int depth = -1;
    int curh = INF;
    while(!pQue.empty())
    {
        int height = pQue.top().first;
        int width = pQue.top().second.first;
        int index = pQue.top().second.second;
        pQue.pop();
        // cout << curh <<"/" << depth<< endl;
        // cout << height << "/" << width << "/" << index << endl;
        if(curh > height)
        {
            curh = height;
            depth++;
        }

        tree[depth].push_back(index);
    }   
    cout << depth << endl;
    FOR(i, depth+1)
    {
        FOR(j, tree[i].size())
        {
            cout << tree[i][j] << " ";
        }cout << endl;
    }
    int root = tree[0][0];
    dfs(root, 1, answer);

    return answer;
}

int main()
{
    vector<vector<int>> nodeinfo 
        = {{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}};

    vector<vector<int>> answer
        = solution(nodeinfo);

    FOR(i, answer[0].size())
    {
        cout << answer[0][i] << " ";
    }cout << endl;

    FOR(i, answer[0].size())
    {
        cout << answer[1][i] << " ";
    }cout << endl;
    return 0;
}