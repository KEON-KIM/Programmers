#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isSkill[26] = {false, };
bool cmp(string str, string tmp)
{
    int cmp_idx = 0;
    int before = -1;
    for(int i = 0; i < tmp.length(); i++)
    {
        if(before != -1 && before == (tmp[i] - 'A')) continue;
        if(str[cmp_idx] != tmp[i]) return false;
        else
        {
            cmp_idx++;
            before = (tmp[i] - 'A');
        }
    }
    return true;
}
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(char c : skill)
        isSkill[c - 'A'] = true;
    
    for(string str : skill_trees)
    {
        string tmp = "";
        for(char c : str)
        {
            if(isSkill[c - 'A'])
                tmp += c;
        }
        if(cmp(skill, tmp)) 
            answer++;
        
    }
    return answer;
}

int main()
{
    string skill = "CBD";
    vector<string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};
    cout << solution(skill, skill_trees);
    return 0;
}