#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 100001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define RFOR(i, n) for(int i = n; i >= 0; i--)

using namespace std;
int R, C;
void Shift_rc(int moveCnt, vector<vector<int>> &rc)
{
    int del = R - (moveCnt%R);
    FOR(i, del)
        rc.push_back(rc[i]);
    rc.erase(rc.begin(), rc.begin()+del);
}

void Rotate_rc(int moveCnt, vector<vector<int>> &rc)
{
    vector<int> res;
    FOR(i, C) res.push_back(rc[0][i]);
    FOR(i, R-1) res.push_back(rc[i+1][C-1]);
    RFOR(i, C-2) res.push_back(rc[R-1][i]);
    for(int i = R-2; i >= 1; i--) res.push_back(rc[i][0]);

    int rnd = R*C - ((R-2) * (C-2));

    FOR(i, rnd - moveCnt%rnd)
        res.push_back(res[i]);

    res.erase(res.begin(), res.begin() + (rnd - moveCnt%rnd));
    
    int cnt = 0;
    FOR(i, C) rc[0][i] = res[cnt++];
    FOR(i, R-1) rc[i+1][C-1] = res[cnt++];
    RFOR(i, C-2) rc[R-1][i] = res[cnt++];
    for(int i = R-2; i >= 1; i--) rc[i][0] = res[cnt++];
    cout << cnt << "/" << rnd << endl;
}


vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer;
    int cnt = 0; string cp = "X";
    R = rc.size(), C = rc[0].size();
    vector<string> operations_board;
    FOR(i, operations.size()){
        if(cp[0] != operations[i][0])
        {
            operations_board.push_back(cp += (cnt+'0'));
            cp = operations[i][0]; cnt = 0;
        }
        cnt++;
        if(i == operations.size()-1) operations_board.push_back(cp+=(cnt+'0'));
    }

    for(string str : operations_board)
    {
        if(str[0] == 'X') continue;
        if(str[0] == 'S')
        {
            str.erase(str.begin(), str.begin()+1);
            Shift_rc(stoi(str), rc);
        }
        else
        {
            str.erase(str.begin(), str.begin()+1);
            Rotate_rc(stoi(str), rc);
        }
    }

    return rc;
}

int main()
{
    vector<vector<int>> rc
        // = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        // = {{8, 6, 3}, {3, 3, 7}, {8, 4, 9}};
        = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<string> operations
        // = {"Rotate", "ShiftRow"};
        // = {"Rotate", "ShiftRow", "ShiftRow"};
        = {"ShiftRow", "Rotate", "ShiftRow", "Rotate"};

    vector<vector<int>> answer = solution(rc, operations);
    for(vector<int> v : answer)
    {
        for(int i : v) cout << i << " ";
        cout << endl;
    }
    return 0;
}