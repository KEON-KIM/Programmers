#include <iostream>
#include <vector>
#include <string>

#define RFOR(i, n) for(int i = n-1; i >= 0; i--)
using namespace std;

typedef long long ll;
ll solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    ll answer = 0;

    ll rs, re, cs, ce;
    rs = re = x; cs = ce = y;
    RFOR(i, queries.size())
    {
        int dir = queries[i][0];
        int dist = queries[i][1];
        if(dir == 0) // 열 증가
        { 
            ce += dist;
            if(cs) cs += dist;
            if(ce >= m) ce = m - 1; 
        }
        else if(dir == 1) // 열 감소
        {
            cs -= dist;    
            if(cs < 0) cs = 0;
            if(ce != m - 1) ce -= dist;    
        } 
        else if(dir == 2)  // 행 증가
        { 
            re += dist;
            if(rs) rs += dist;
            if(re >= n ) re = n - 1;
        } 
        else  // 행 감소
        { 
            rs -= dist;    
            if(rs < 0) rs = 0;
            if(re != n - 1) re -= dist;   
        }

        if(rs > n - 1 || re < 0 || cs > m - 1 || ce < 0)  // 범위 밖
            return answer; // return 0;
    }

    answer = (re - rs + 1) * (ce - cs + 1); // boundary
    return answer;
}

int main()
{
    int n = 2;
    int m 
        // = 2;
        = 5;
    int x = 0;
    int y 
        // = 0;
        =1;
    vector<vector<int>> queries
        // = {{2,1},{0,1},{1,1},{0,1},{2,1}};
        = {{3,1},{2,2},{1,1},{2,3},{0,1},{2,1}};
    cout << solution(n, m, x, y, queries);
    return 0;
}