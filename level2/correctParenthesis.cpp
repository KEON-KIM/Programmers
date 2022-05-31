#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
bool isCorrect(string p)
{
    stack<char> St;
    for(char c : p)
    {
        if(c == '(')
            St.push(c);
        else
        {
            if(St.empty())
                return false;
            else
                St.pop();
        }
    }
    if(!St.empty()) return false;
    return true;
}
string dfs(string p)
{
    cout << p.length() << endl;
    if(!(p.length()))
        return "";

    string u, v; u = v = "";
    int l, r, idx = 0; l = r = 0;
    for(int i = 0; i < p.length(); i++) // u만들기
    {
        if(p[i] == '(') r++;
        else l++;

        u += p[i];
        if(l && l == r) 
        {
            idx = i;
            break;
        }
    }

    for(int i = idx+1; i < p.length(); i++) // v 만들기 
        v += p[i];
    cout << u << " / " << v << endl;
    if(isCorrect(u))
         return u + dfs(v);

    else
    {
        string tmp = "(";
        for(int i = 0; i < u.length(); i++)
        {
            if(!i || i == u.length()-1) continue;
            if(u[i] == '(') tmp += ')';
            else tmp += '(';
        }
        tmp += ')';
        return tmp + dfs(v);
    }
    
}
string solution(string p) {
    string answer = "";
    answer = dfs(p);

    return answer;
}
int main()
{
    // string p = "(()())()";
    // string p = "";
    // string p = ")(";
    string p = "()))((()";
    string answer;
    answer = solution(p);
    cout << answer << endl;
    return 0;
}