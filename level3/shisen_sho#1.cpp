#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

bool isBreak(pair<int, int> p1, pair<int, int> p2, vector<string> &board)
{
	int minX = min(p1.first, p2.first);
	int minY = min(p1.second, p2.second);
	int maxX = max(p1.first, p2.first);
	int maxY = max(p1.second, p2.second);
	bool flag = true, flag2 = true;
	if(p1.second <= p2.second)
	{
		for(int i = minX+1; i < maxX; i++) if(board[i][minY] != '.') flag = false;
		for(int i = minY; i < maxY; i++) if(board[maxX][i] != '.') flag = false;

		for(int i = minY+1; i < maxY; i++) if(board[minX][i] != '.') flag2 = false;
		for(int i = minX; i < maxX; i++) if(board[i][maxY] != '.') flag2 = false;
	}
	else
	{
		for(int i = minX+1; i < maxX; i++) if(board[i][minY] != '.') flag = false;
		for(int i = maxY; i > minY; i--) if(board[maxX][i] != '.') flag = false;

		for(int i = maxY-1; i > minY; i--) if(board[minX][i] != '.') flag2 = false;
		for(int i = minX; i < maxX; i++) if(board[i][minY] != '.') flag2 = false;
	}
	
	return flag || flag2;
}
void print(vector<string> &board)
{
	cout << "--------------------" << endl;
	for(string str : board)
	{
		for(char c : str)
			cout << c << " ";
		cout << endl;
	}
}

string solution(int m, int n, vector<string> board) {
    string answer = "";
    int cnt = 0;
    bool alpha[26] = {false, };
    vector<pair<int, int>> posVector[26];

    FOR(i, m)
        FOR(j, n)
        {
            if((board[i][j] != '.' && board[i][j] != '*'))
            {
                if(!alpha[board[i][j] - 'A']) cnt++;
                alpha[board[i][j] - 'A'] = true;
                posVector[board[i][j] - 'A'].push_back({i, j});
            }
        }

    int tmp = 0;
    while(tmp != cnt)
    {
        tmp = cnt;
        FOR(i, 26)
        {
            if(alpha[i])
            {            
            	cout << char('A' + i) << endl;
            	
            	if(isBreak(posVector[i][0], posVector[i][1], board))
            	{
            		cnt--;
            		alpha[i] = false;
            		board[posVector[i][0].first][posVector[i][0].second] = '.';
            		board[posVector[i][1].first][posVector[i][1].second] = '.';
            		answer += 'A' + i;
            		print(board);
            		break;
            	}
            }
        }
    }

    if(cnt) answer = "IMPOSSIBLE";
    return answer;
}


int main()
{
    vector<string> board
        /*= {"DBA",
           "C*A", 
           "CDB"};*/
        // = {"NRYN", "ARYA"};
        // = {".ZI.", "M.**", "MZU.", ".IU."};
        // = {"AB", "BA"};
        = {"M.*.M...DU",
           "....AR...R",
           "...E..OH.H",
           ".....O...Z",
           ".E..A..Q.Z",
           "Q....LL.*.",
           ".D.N.....U",
           "GT.T...F..",
           "....FKS...",
           "GN....K..S"};
    cout << solution(10, 10, board);
    return 0;
}