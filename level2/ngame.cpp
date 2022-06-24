#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 10101
using namespace std;

char mod[16] = {'0', '1', '2', '3', '4', '5', '6', '7', 
                '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string func(int number, int n)
{
    string str = "";
    while(number >= n)
    {
        str += mod[number % n];
        number /= n;
    }
    if(number) 
        str += mod[number];
    reverse(str.begin(), str.end());
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string board = "0";
    int num = 0;
    while(board.length() < MAX)
    {
        string s = func(num, n);
        board+=s;
        num++;
    }
    for(int i = p-1; i < MAX; i+= m)
    {
        if(answer.length() == t) break;
        answer += board[i];
    }
    return answer;
}

int main()
{
    // cout << solution(16,16,2,1) << endl;
    cout << func(6542, 16) << endl;
    return 0;
}