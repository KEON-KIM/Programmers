#include <string>
#include <vector>
#include <map>
#include <iostream>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

bool isBanned(string str, string banned)
{
    FOR(i, str.length())
    {
        if(banned[i] == '*') continue;
        if(str[i] != banned[i])
            return false;
    }
    return  true;
}
void print(map<string, int> &visited)
{
    for(auto it : visited)
        cout << it.first << "/" << it.second << " ";
    cout << endl;
}
void dfs(int N, int idx, vector<vector<string>> &userlist, map<string, int> &visited, map<string, int> &set_visited)
{
    if(idx == N){
        string userset = "";
        print(set_visited);
        for(auto it : visited) 
            if(it.second) userset += it.first;
        set_visited[userset]++;
        return;
    }
    for(string user : userlist[idx])
    {
        if(!visited[user])
        {
            visited[user]++;
            dfs(N, idx+1, userlist, visited, set_visited);
            visited[user]--;
        }
    }

    return;
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    vector<vector<string>> userlist;

    for(string banned : banned_id)
    {
        vector<string> tmp;
         for(string str : user_id)
            if(str.length() == banned.length() 
                && isBanned(str, banned))
                tmp.push_back(str);
        
        userlist.push_back(tmp);
    }
    //print()
    // for(vector<string> v : userlist)
    // {
    //     for(string str : v)
    //         cout << str << " ";
    //     cout << "===="<< endl;
    // }

    map<string, int> visited;
    map<string, int> set_visited;
    if(userlist.size() && userlist[0].size()){
        FOR(i, userlist[0].size())
        {
            visited[userlist[0][i]]++;
            dfs(banned_id.size(), 1, userlist, visited, set_visited);
            visited[userlist[0][i]]--;
        }
    }
    // answer = answer>2? answer/2 : answer
    return set_visited.size();
}

int main()
{
    vector<string> user_id 
        // = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
        // = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
        = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id
        // = {"fr*d*", "abc1**"};
        // = {"*rodo", "*rodo", "******"};
        = {"fr*d*", "*rodo", "******", "******"};

    cout << solution(user_id, banned_id);
    return 0;
}