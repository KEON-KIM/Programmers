#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define MAX 100002
#define FOR(i, n) for(int i = 0; i < n; i++)
int solution(int n, vector<int> money) 
{
    int answer = 0;
    int board[MAX];
    FOR(i, money.size())
    {
        int m = money[i];
        if(!(n%m)) board[0] = 1;
        else board[0] = 0;

        for(int j = 1; j <= n; j++)
        {
            if(j - m < 0) continue;
            board[j] += board[j - m];
        }
    }

    return board[n];
}

int main()
{
    vector<int> money = {1, 2, 5};
    cout << solution(5, money);
    return 0;
}