#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

string solution(string s) {
    string answer;
    vector<int> Que;
    string tmp = "";
    FOR(i, s.length())
    {
        if(s[i] == ' ' || i == s.length()-1)
        {
            if(i == s.length()-1)
                tmp += s[i];
            Que.push_back(stoi(tmp));
            tmp = "";
            continue;
        }
        tmp+=s[i];
    }
    sort(Que.begin(), Que.end());
    answer = to_string(Que[0]) + " " + to_string(Que[Que.size()-1]);
    return answer;
}

int main()
{
    string s = 
        // "1 2 3 4";
        "-1 -2 -3 -4";
        // "-1 -1";
    cout << solution(s);
    return 0;
}