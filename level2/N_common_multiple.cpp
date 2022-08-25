#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int solution(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int answer = arr[arr.size()-1];
    FOR(i, arr.size()-1)
    {
        for(int j = 1; j <= arr[i]; j++)
        {
            if(!((answer*j)%arr[i]))
            {
                cout << "WHAT" << endl;
                answer *= j;
                break;
            }
        }
    }
    return answer;
}

int main()
{
    vector<int> arr
        = {2,6,8,14};
        // = {1,2,3};
    cout << solution(arr);
    return 0;
}