#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef struct qinfo{
    int x,y,dir,cnt;
};
typedef struct ainfo{
    int x,y;
};

int pairCnt = 0;
int N = 0,M = 0;

bool inRange(int x, int y){
    return (0 <= x && x < M && 0 <= y && y < N);
}

bool BFS(int start_x, int start_y, int end_x, int end_y, vector<string> &boards){
    
    pair<int, int> nextdir[4] = {{1,0},{0,1},{-1,0},{0,-1}};
    
    queue<qinfo> q;
    q.push({start_x, start_y, -1, 0});
    while(!q.empty()){
        int now_x = q.front().x; int now_y = q.front().y;
        int cnt = q.front().cnt; int dir = q.front().dir;
        q.pop();
        
        for(int i=0;i<4;i++){
            if(dir != -1 && abs(dir - i) == 2) // 역방향일 때
                continue;
            
            int next_x = now_x + nextdir[i].first;
            int next_y = now_y + nextdir[i].second;
            int next_cnt = (dir == i || dir == -1) ? cnt:cnt+1;
            
            if(inRange(next_x, next_y)){
                if(next_cnt <= 1)
                {
                    if(boards[next_x][next_y] == '*')
                        continue;
                    
                    else if(boards[next_x][next_y] == '.')
                        q.push({next_x, next_y, i, next_cnt});
                    
                    else 
                        if(next_x == end_x && next_y == end_y)
                            return true;
                }
            }
        }
    }
    return false;
}

string solve(vector<vector<ainfo>> &arr, vector<string> &boards){
    
    string ans = "";
    bool flag = true;
    
    while(flag){
        
        flag = false;
        for(int i=0;i<arr.size();i++){
            if(arr[i].size() > 1){
                if(BFS(arr[i][0].x, arr[i][0].y, arr[i][1].x, arr[i][1].y, boards)){
                    boards[arr[i][0].x][arr[i][0].y] = boards[arr[i][1].x][arr[i][1].y] = '.'; 
                    arr[i].clear(); 
                    pairCnt -= 2; 
                    ans += char(i + int('A')); 
                    flag = true;
                    break;
                }    
            }
        }   
    }
    
    if(pairCnt == 0) 
        return ans;
    else 
        return "IMPOSSIBLE";
}

string solution(int m, int n, vector<string> board) {
    
    string answer = "";
    vector<vector<ainfo>> arr(26, vector<ainfo>());
    
    pairCnt = 0;
    M=m; N=n;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if('A' <= board[i][j] && board[i][j] <= 'Z'){
                arr[int(board[i][j]) - int('A')].push_back({i,j});
                pairCnt++; 
            }
        }
    }
                
    return answer = solve(arr,board);
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
        /*= {"M.*.M...DU",
           "....AR...R",
           "...E..OH.H",
           ".....O...Z",
           ".E..A..Q.Z",
           "Q....LL.*.",
           ".D.N.....U",
           "GT.T...F..",
           "....FKS...",
           "GN....K..S"};*/
        = {"*A.",
            "***",
            "***"};
    cout << solution(3, 3, board);
    return 0;
}