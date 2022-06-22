#include <iostream>
#include <string>
#include <vector>
#include <map>

#define MAX 1001
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> board;//index, numbering;
    for(int i = 0; i < 26; i++)
    {
        string tmp = "A";
        tmp[0] += i;
        board.insert({tmp, i+1});
    }
    char* next = &msg[0];
    while(*next)
    {
        // cout << "====next ====" << endl;
        string str = "";
        str += *next;
        while(*next++ && board[str])
        {
            str += *next;
        }           
        board[str] = board.size(); 
        str.pop_back();
        *next--;

        answer.push_back(board[str]);
    }

    // for(auto it : board)
    //     cout << it.first << " / " << it.second << endl;

    return answer;
}

int main()
{
    string msg 
        // = "KAKAO";
        = "TOBEORNOTTOBEORTOBEORNOT";
        // = "ABABABABABABABAB";
    vector<int> ans = solution(msg);
    for(int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}