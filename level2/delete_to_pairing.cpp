#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;
    for(char c : s) {
    	if(!st.empty() && st.top() == c) st.pop();
    	else 	
    		st.push(c);
    }
    cout << st.size() << endl;
    if(st.size()>0) return 0;
    else return 1;

}

int main()
{
	string s = "cdcd";
	cout << solution(s);
	return 0;
}