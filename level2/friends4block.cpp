#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 31
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N, M;
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> delete_info[MAX];
void print(vector<string> board)
{
    for(string str : board)
        cout << str << endl;
}
int isDestroy(vector<string> &board)
{
    int result = 0;
    FOR(i, board.size() - 1)
    {
        if(board[i].length() < 0) continue;
        cout << i << "/"<< board[i].length()<< endl;
        FOR(j, board[i].length())
        {
            cout << "FUCK" << endl;
            int cnt = 0;
            int c = board[i][j];
            for(int x = i; x < i + 2; x++)
            {
                for(int y = j; y < j + 2; y++)
                {
                    if(x < 0 || x >= board.size() || y < 0 || y >= board.size()) continue;
                    if(board[x][y] == c)
                        cnt++;
                }
            }

            if(cnt == 4)
            {
                cout << i << "break!" << endl;
                delete_info[i].push({j, j+1});
                delete_info[i+1].push({j, j+1});
                /*delete_info[i].first = min(delete_info[i].first, j);
                delete_info[i].second = max(delete_info[i].second, j+1);
                delete_info[i+1].first = min(delete_info[i+1].first, j);
                delete_info[i+1].second = max(delete_info[i+1].second, j+1);*/
                result++;
            }
        }
    }
    return result;
}
int solution(int m, int n, vector<string> board) {
    N = n; M = m;
    int answer = 0;
    vector<string> tmpBoard;
    for(int i = n-1; i >= 0; i--)
    {
        string tmp = "";
        for(int j = m - 1; j >= 0; j--)
            tmp += board[j][i];
        tmpBoard.push_back(tmp);
    }

    while(isDestroy(tmpBoard))
    {
        print(tmpBoard);
        FOR(i, n)
        {
            int del_cnt = 0;
            while(!delete_info[i].empty())
            {  
                int s = delete_info[i].top().first;
                int e = delete_info[i].top().second;
                delete_info[i].pop();

                if(!delete_info[i].empty() && e + 1 >= delete_info[i].top().first)
                {
                    int e2 = delete_info[i].top().second;
                    delete_info[i].pop();
                    cout << "s : " << s << "e2 : " << e2 << endl;
                    delete_info[i].push({s, e2});
                    continue;
                }
                cout <<"delete[" << i << " ] : "<< s << "/" << e << endl;
                tmpBoard[i].erase(tmpBoard[i].begin() + s - del_cnt, tmpBoard[i].begin() + e + 1 -(del_cnt));
                answer += (e - s + 1); del_cnt += (e - s + 1);
            }
            /*cout << delete_info[i].first << "/" << delete_info[i].second << endl;
            if(delete_info[i].first < MAX && delete_info[i].second > 0)
            {
                answer += (delete_info[i].second - delete_info[i].first + 1);
                tmpBoard[i].erase(tmpBoard[i].begin() + delete_info[i].first, tmpBoard[i].begin() + delete_info[i].second+1);
            }*/
        }
        cout << "=============" << endl;
        
    }
    print(tmpBoard);
    return answer;
}
int main()
{
    vector<string> board
        // = {"CCBDE", "AAADE", "AAABF", "CCBBF"};
        // = {"AAAAAAAA", "BBAAAACC", "BBAAAACC"};
        // = {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"};
        /*= {"TTTANT",
           "RRFACC",
           "RRRFCC",
           "TMMRAA",
           "TTMMMF",
           "TTMTTJ"};*/
    = {"DDABBAABBA",
        "AAAAAABBBA",
        "DDACCBBBAA",
        "DDABBBBBAA",
        "AAABBABBBA",
        "CCADDAABBB",
        "CCADDAABBB",
        "BBACCABBBA",
        "BBAAABBBAA",
        "DDABBBBAAA"};
    cout << solution(10, 10, board);
    return 0;
}