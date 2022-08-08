#include <cstring>
#include <vector>
#include <cmath>
#include <iostream>

#define MAX 1000001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define RFOR(i, n) for(i = n-1; i >= 0; i--)

using namespace std;
vector<string> solution(vector<string> s) {
    vector<string> answer;
    for(string str : s)
    {
        int cnt = 0;
        string tmp = "";
        FOR(i, str.size())
        {
            tmp += str[i];
            if(tmp.size() >= 3 && tmp.substr(tmp.size()-3) == "110")
            {
                cnt++;
                tmp.erase(tmp.size() - 3, 3);
            }
        }
        int idx;
        RFOR(idx, tmp.size())
            if(tmp[idx] == '0') break;

        FOR(i, cnt)
            tmp.insert(idx+1, "110");

        answer.push_back(tmp);
    }
    
    return answer;
}

int main()
{
    vector<string> s
        = {"1110","100111100","0111111010"};
    vector<string> answer;
    answer = solution(s);
    for(string str : answer)
        cout << str << endl;
    return 0;
}