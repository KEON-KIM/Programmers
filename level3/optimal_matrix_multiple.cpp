#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int dp[201][201];
int dfs(int l, int r, vector<vector<int>> &matrix)
{
    if(l == r) return 0;
    int &ret = dp[l][r];

    if(ret!=-1) return ret;
    ret = 2e9;
    for(int i = l; i < r; i++) 
        ret = min(
            ret, dfs(l, i, matrix) 
            + dfs(i + 1, r, matrix) 
            + matrix[l][0] * matrix[i][1] * matrix[r][1]
        );
    return ret;
}

int solution(vector<vector<int>> matrix_sizes) {
    memset(dp, -1, sizeof(dp));
    return dfs(0, matrix_sizes.size()-1, matrix_sizes);
}

int main()
{
    vector<vector<int>> matrix_sizes
        = {{5,3},{3,10},{10,6}};
    cout << solution(matrix_sizes);
    return 0;
}