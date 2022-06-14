#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    answer.resize(2);
    int n = brown + yellow;
    for(int i = 3; i <= sqrt(n); i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i * j == n)
            {
                if(j - 2 < 1) continue;
                else
                {
                    if(((i - 2) * (j - 2)) == yellow) {
                        answer[0] = i;
                        answer[1] = j;
                        if(i < j)
                        {
                            int tmp = answer[0];
                            answer[0] = answer[1];
                            answer[1] = tmp;
                        } 
                        return answer;
                    }
                } 
            }
        }
    }
    return answer;
}

int main()
{
    vector<int> answer = solution(24, 24);
    cout << answer[0] << " / "<< answer[1] << endl;
    return 0;
}