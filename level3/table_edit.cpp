#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <stack>

#define MAX 1000001
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;
string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    stack<int> St;
    pair<int, int> board[MAX]; 
     //{up, down}
   
    FOR(i, n)
    {
        answer += 'O';
        board[i].first = i-1;
        if(i < n-1) board[i].second = i+1;
        else board[i].second = -1;
    }

    for(string str : cmd)
    {
        cout << "KEY : " << k << endl;
        istringstream ss(str);
        string buffer;
        vector<string> v;
        while(getline(ss, buffer, ' '))
            v.push_back(buffer);
        
        if(v[0] == "U")
        {
            int next = stoi(v[1]);
            while(next > 0)
            {
                k = board[k].first;
                next--;
            }
            /*while(next > 0)
            {
                if(answer[k-1] == 'O')
                    next--;
                k--;
            }*/
        }
        else if(v[0] == "D")
        {
            int next = stoi(v[1]);
            while(next > 0)
            {
                k = board[k].second;
                next--;
            }
        }
        
        else if(v[0] == "C")
        {
            cout << "BEFORE KEY : " << k << endl;
            answer[k] = 'X';
            St.push(k);
            board[k-1].second = board[k].second;
            board[k+1].first = board[k].first;
            if(board[k-1].second == -1)
                k = board[k].first;
            else
                k = board[k].second;
           /* while(answer[cur] != 'O'){
                if(cur < n - 1)
                    cur++;
                else{
                    cur = k;
                    while(answer[cur] != 'O')
                        if(cur >= 0)
                            cur--;
                }
            }*/
            cout << "AFTER KEY : " << k << endl;
        }
        
        else
        {
            int cur = St.top();
            St.pop();
            board[cur-1].second = cur;
            board[cur+1].first = cur;
            answer[cur] = 'O';
        }
    }

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