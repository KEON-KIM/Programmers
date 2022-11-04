#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

string solution(int n, int k, vector<string> cmd) 
{
    string answer(n,'X');
    stack<int> St;
    set<int> board;
    FOR(i, n) board.insert(i);
    set<int>::iterator it = board.find(k);
    for(string str: cmd) 
    {
        if (str[0] == 'U' || str[0] == 'D') 
        {
            int num = stoi(str.substr(2));
            if (str[0] == 'U')
                while(num--)
                    it = prev(it);
            else
                while(num--)
                    it = next(it);
        }

        else if (str[0] == 'C') 
        {
            St.push(*it);
            it = board.erase(it);
            if (it == board.end()) it = prev(it);
        }

        else
        {
            board.insert(St.top());
            St.pop();
        }
    }

    for(int i : board) answer[i] = 'O';
    return answer;
}
int main()
{
	vector<string> cmd
		// = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z"};
		= {"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"};
	cout << solution(8, 2, cmd);
 	return 0;
}
