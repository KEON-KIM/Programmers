#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(ll i = left; i <= right; i++)
    {
        ll val = max(i%n, i/n);
        answer.push_back(val + 1);
    }
    return answer;
}

int main()
{
    vector<int> answer;
    answer = solution(3, 2, 5);
    for(int i : answer)
        cout << i << " ";
    cout << endl;
    // answer = solution(4, 7, 14);
    return 0;
}