#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n > s)
    {
        answer.push_back(-1);
        return answer;
    }
    int num = 0;
    int q = s / n;
    int r = s % n;
    if(s % n != 0) num = 1;
    for(int i = 0; i < n; i++)
    {
        if(i >= n - r) answer.push_back(q + 1);
        else answer.push_back(q);
    }
    
    return answer;
}
int main()
{
    vector<int> answer = solution(14, 206);
    for(int i : answer) cout << i << " ";
    cout << endl;
    return 0;
}