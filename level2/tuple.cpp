#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>

#define FOR(i, n) for(int i = 1 ; i < n-1; i++)
using namespace std;
bool cmp(string &str1, string &str2)
{
    return str1.size() < str2.size();
}
vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> visited;
    vector<string> tmpbuffer;

    string buff = "";
    bool isbracket = false;
    // s = string(s.begin()+1, s.end()-1);
    FOR(i, s.size())
    {
        if(s[i] == '{') {isbracket = true; continue;}
        if(s[i] == '}' && i != s.size()-2) {isbracket = false; continue;}
        if((s[i] == ',' && !isbracket) || i == s.size()-2)
        {
            tmpbuffer.push_back(buff);
            buff = "";
            continue;
        }
        buff += s[i];
    }
    sort(tmpbuffer.begin(), tmpbuffer.end(), cmp);
    for(string str : tmpbuffer) {
        string buff;
        cout << str << endl;
        istringstream ss(str);
        while(getline(ss, buff, ','))
        {
            int tmp = stoi(buff);
            if(!visited[tmp]++)
                answer.push_back(tmp);
        }
    }

    return answer;
}

int main()
{
    string s
        = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
        // = "{{1,2,3},{2,1},{1,2,4,3},{2}}";
        // = "{{20,111},{111}}";
        // = "{{123}}";
        // = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
    vector<int> answer = solution(s);
    cout << answer.size() << endl;
    return 0;
}