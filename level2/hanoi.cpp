#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int from, int pass, int to, vector<vector<int>> &answer)
{
    if(n == 1)
        answer.push_back({from, to});
    
    else
    {
        hanoi(n-1, from, to, pass, answer);
        answer.push_back({from, to});
        hanoi(n-1, pass, from, to, answer);
    }

}
vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 2, 3, answer);
    return answer;
}

int main()
{
    vector<vector<int>> answer
        = solution(3);

    for(vector<int> v : answer)
        cout << v[0] << " / " << v[1] << endl;
    
    return 0;
}