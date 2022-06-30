#include <iostream>
#include <stack>
#include <string>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

bool solution(string s)
{
    bool answer = false;
    stack<char> St;

    for(char c : s)
    {
        if(c == '(')
            St.push(c);
        else
        {
            if(St.empty())
                return answer;
            else
                St.pop();
        }
    }
    if(St.empty()) answer = true;
    return answer;
}

int main()
{
    string s = 
                // "()()";
                // "(())()";
                // ")()(";
                // "(()(";

    cout << solution(s);
    return 0;
}