#include <string>
#include <vector>
#include <iostream>

#define MAX 1002

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    int board[MAX][MAX] = {0, };
    int x = 0, y = 0, num = 1;
    int cycle = 0;
    while(!board[x][y])
    {
        for(int j = cycle; j < n; j++)
            board[x++][y] = num++;
        x--;
        y++;
        cycle++;

        for(int j = cycle; j < n; j++)
            board[x][y++] = num++;
        x--;
        y -= 2;
        cycle++;

        for(int j = cycle; j < n; j++)
            board[x--][y--] = num++;
        x += 2;
        y++;
        cycle++;

    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            answer.push_back(board[i][j]);

    return answer;
}

int main()
{
    vector<int> answer = solution(6);
    for(int i : answer)
        cout << i << " ";
    cout << endl;
    return 0;
}