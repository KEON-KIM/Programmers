#include <set>
#include <vector>
#include <iostream>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define has(a) (building.find(pred[(a)])!=building.end())
using namespace std;

bool isValid(const set<vector<int>>& building){
    for(auto build:building)
    {
        int x = build[0], y = build[1], a = build[2];
        if(!a) // 기둥
        {
            vector<int> pred[3] = {{x, y-1, 0},{x, y, 1},{x-1, y, 1}};
            if(y == 0 || has(0) || has(1) || has(2)) continue;
            return false;
        }
        else
        {
            vector<int> pred[4] = {{x, y-1, 0}, {x+1, y-1, 0}, {x+1, y, 1}, {x-1, y, 1}};
            if(has(0) || has(1) || (has(2) && has(3)) ) continue;
            return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    set<vector<int>> building;

    for(auto task:build_frame){
        vector<int> v = {task[0], task[1], task[2]};
        if(!task[3]) // 삭제 
        {
            building.erase(v);
            if(!isValid(building)) building.insert(v);
        }
        else // 생성
        {
            building.insert(v);
            if(!isValid(building)) building.erase(v);
        }
    }

    for(auto build : building)
        answer.push_back(build);

    return answer;
}

int main()
{
	int n
		= 5;
	vector<vector<int>> build_frame
		// = {{1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1}};
		= {{0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1}};
	vector<vector<int>> answer = solution(n, build_frame);
	FOR(i, answer.size())
	{
		FOR(j, 3)
		{
			cout << answer[i][j] << ' ';
		}cout << endl;
	}
	return 0;
}
/*#include <iostream>
#include <string>
#include <vector>

#define MAX 105
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

bool pillar[MAX][MAX][MAX] = {false, };
bool bottom[MAX][MAX][MAX] = {false, };
bool isPillarBuild(int x, int y)
{
	if(x == 0 || (x > 0 ? pillar[y][x-1][x] : false)) return true; // 기둥위이거나 바닥위일 경우
	if((y > 0 ? bottom[x][y-1][y] : false ) || bottom[x][y][y+1]) return true; // 지을 어느 곳이든 보가 있는 경우 
	return false;
}
bool isBottomBuild(int x, int y)
{
	if((y > 0 ? bottom[x][y-1][y] : false ) && bottom[x][y+1][y+2]) return true; // 양쪽에 보가 있는 경우 
	if(x > 0 ? (pillar[y][x-1][x] || pillar[y+1][x-1][x]) : false) return true; // 어느쪽이든 기둥이 있는 경우
	return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    FOR(i, build_frame.size())
    {
		int x = build_frame[i][1], y = build_frame[i][0];
    	if(build_frame[i][3]) // 생성
    	{
    		if(!build_frame[i][2]) // 기둥
    		{
    			// cout << "CREATE PILLAR" << endl;
    			if(isPillarBuild(x, y)) // x, y;
    			{
    				// cout << "CLEAR" << endl;
    				pillar[y][x][x+1] = true;
    			}
    		}
    		else // 보
    		{
    			// cout << "CREATE BOTTOM" << endl;
    			if(isBottomBuild(x, y))
    			{
    				// cout << "CLEAR" << endl;
    				bottom[x][y][y+1] = true;
    			}
    		}
    	}
    	else // 삭제 
    	{
    		if(!build_frame[i][2]) // 기둥
    		{
    			// cout << "DELETE PILLAR" << endl;
    			if(pillar[y][x][x+1])
    			{
    				pillar[y][x][x+1] = false;
    				if((pillar[y][x+1][x+2]? isPillarBuild(x+1, y) : true) 
    					&& (( y > 0 && bottom[x+1][y-1][y]) ?isBottomBuild(x+1, y-1) : true ) 
    					&& (bottom[x+1][y+1][y+2] ? isBottomBuild(x+1, y+1) : true)) continue;
    				pillar[y][x][x+1] = true;
    			}
    		}
    		else // 보
    		{
    			// cout << "DELETE BOTTOM" << endl;
    			if(bottom[x][y][y+1])
    			{
    				bottom[x][y][y+1] = false;
    				if( (pillar[y][x][x+1] ? isPillarBuild(x, y)  : true )
						&& (pillar[y+1][x][x+1] ? isPillarBuild(x, y+1) : true)
						&& ((y > 0 && bottom[x][y-1][y]) ? isBottomBuild(x, y-1) : true ) 
						&& (bottom[x][y+1][y+2] ? isBottomBuild(x, y+1) : true )) continue;
    				bottom[x][y][y+1] = true;
    			}
    		}
    	}
    }

    FOR(y, MAX)
    {
    	FOR(x, MAX)
    	{
    		if(pillar[y][x][x+1])
    		{
    			vector<int> tmp;
    			tmp.push_back(y);
    			tmp.push_back(x);
    			tmp.push_back(0);
    			answer.push_back(tmp);
    		}
    		if(bottom[x][y][y+1])
    		{
    			vector<int> tmp;
    			tmp.push_back(y);
    			tmp.push_back(x);
    			tmp.push_back(1);
    			answer.push_back(tmp);
    		}
    	}
    }
    return answer;
}
*/