#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    if (!citations[0])     
       return 0;

    for (int i = 0; i < citations.size(); i++)    
    {
        if(citations[i] > i) answer++;
        else break;
    }

    return answer;
}

int main()
{
    // vector<int> citations = {3, 0, 6, 1, 5};
    // vector<int> citations = {9, 3, 0, 6, 1, 5, 11, 7, 14};
    vector<int> citations = {9, 3, 0, 6, 1, 5, 11, 8, 14, 14, 16, 15};
    // vector<int> citations = {3, 3, 3, 2, 2, 1, 0};
    // vector<int> citations = {0, 0, 0, 1, 0};
    // 14, 11, 9, 7, 6, 5, 3, 1, 0
    // 16, 15, 14, 14, 11, 9, 8, 6, 5, 3, 1, 0
    cout << solution(citations);
    return 0;
}