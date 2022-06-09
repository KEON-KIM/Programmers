#include <iostream>
#include <string>
#include <vector>
#include <map>

#define MAX 31

using namespace std;

int len, board[MAX];
/*int dfs(int idx, int dep, int n)
{
    int ans = 0;
    if(dep == n+1)
        return 1;

    for(int i = idx; i < len; i++)
        ans += board[i] * dfs(i + 1, dep+1, n);

    return ans;
}*/

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    len = clothes.size();
    map<string, int> clothesMap;
    for(vector<string> v : clothes)
    {
        if(clothesMap[v[1]] == 0)
            clothesMap[v[1]] = 1;
        else
            clothesMap[v[1]]++;
    }
    for(auto it : clothesMap)
    {
        answer *= (it.second+1);
    }
    /*int idx = 0;
    for(auto it : clothesMap)
    {
        board[idx] = it.second;
        idx++;
    }

    answer = len;
    len = clothesMap.size();
    for(int n = 1; n < len; n++){
        answer += dfs(0, 0, n);
        // cout << "N : " << n << " : " << dfs(0, 0, n) << endl;
    }*/

    return answer-1;
}

int main()
{
    // vector<vector<string>> clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    // vector<vector<string>> clothes = {{"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}};
    vector<vector<string>> clothes = {{"A", "face"}, {"B", "face"}, {"C", "face"},{"D", "headgear"}, {"E", "headgear"}, {"F", "eyewear"}};
    // vector<vector<string>> clothes = {{"A", "eyewear"}, {"B", "eyewear"}, {"C", "eyewear"},{"D", "eyewear"}, {"E", "eyewear"}, {"F", "eyewear"}, {"G", "eyewear"}, {"H", "eyewear"}, {"I", "eyewear"}};
    cout << solution(clothes);
    return 0;
}