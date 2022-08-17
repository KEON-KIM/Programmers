#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int idx = 0;
    FOR(i, B.size())
    {
        if(B[i] > A[idx])
        {
            idx++;
            answer++;
        }
    }

    return answer;
}

int main()
{
    vector<int> A 
        = {5,1,3,7};
    vector<int> B
        = {2,2,6,8};
    cout << solution(A, B);
    return 0;
}