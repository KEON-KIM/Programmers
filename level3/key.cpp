#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define MAX 61
using namespace std;

int board[MAX][MAX];
void print_board(int n)
{
    n *= 3;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool lock_on(int n)
{
    for(int i = n; i < n*2; i++)
        for(int j = n; j < n*2; j++)
            if(!board[i][j]) return false;
    return true;
}

vector<vector<int>> rotate_key(vector<vector<int>> &key, int n)
{
    vector<vector<int>> temp;

    vector<int> tmp(n);
    for(int i = 0; i < n; i++)
        temp.push_back(tmp);
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            temp[i][j] = key[n - j - 1][i];
        
    return temp;
}
void print(vector<vector<int>> &key)
{
    for(vector<int> v : key)
    {
        for(int i : v)
            cout << i << " ";
        cout << endl;
    }
}
bool push_key(int x, int y, vector<vector<int>> key, vector<vector<int>> &lock)
{
    int n = key.size();
    int m = lock.size();
    queue<pair<int, int>> cash;

    for(int t = 0; t < 4; t++)
    {
        bool flag = false;
        for(int i = x; i < x + n; i++){
            if(flag) break;
            for(int j = y; j < y + n; j++)
            {
                if(key[i-x][j-y] && board[i][j])
                {
                    flag = true;
                    break;
                }
                if(key[i-x][j-y] && !board[i][j]) {
                    cash.push({i, j});
                    board[i][j] = 1;
                }
            }
        }

        if(lock_on(m)) return true;
        while(!cash.empty()) // reset;
        {
            int a = cash.front().first;
            int b = cash.front().second;
            cash.pop();
            board[a][b] = 0;
        }
        key = rotate_key(key, n);
    }

    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    // Init
    int n = lock.size();
    for(int i = n; i < n*2; i++)
        for(int j = n; j < n*2; j++)
            board[i][j] = lock[i - n][j - n];

    for(int i = 1; i < n*2; i++)
    {
        for(int j = 1; j < n*2; j++)
        {
            if(push_key(i, j, key, lock)) return true;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    vector<vector<int>> lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    cout << solution(key, lock);
    return 0;
}