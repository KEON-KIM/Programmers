#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
bool isParenthesis(string &s, int idx)
{
    stack<char> St;
    int cur = idx;
    if(s[cur] == '(' || s[cur] == '[' || s[cur] == '{')
        St.push(s[cur]);
    
    else return false;
    
    while(++cur%s.length() != idx)
    {
        if(s[cur%s.length()] == '(' || s[cur%s.length()] == '[' || s[cur%s.length()] == '{')
            St.push(s[cur%s.length()]);

        else
        {
            if(St.empty()) return false;
            
            else if(St.top() == '('  && s[cur%s.length()] == ')')
                St.pop();

            else if(St.top() == '{' && s[cur%s.length()] == '}' )
                St.pop();

            else if(St.top() == '[' && s[cur%s.length()] == ']')
                St.pop();
        }
    }
    if(!St.empty()) return false;
    return true;
}
int solution(string s) {
    int answer = 0;
    for(int i = 0; i < s.length(); i++)
        if(isParenthesis(s, i)) answer ++;
    return answer;
}

int main()
{
    string s = "[](){}";
               // "}]()[{";
               // "[)(]";
               // "}}}";
                // "{}({}";
    cout << solution(s);
    return 0;
}