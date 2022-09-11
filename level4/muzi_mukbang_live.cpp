#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef pair<int ,int> pii;
int solution(vector<int> food_times, long long k) {
    int answer = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pQue;
    FOR(i, food_times.size())
        pQue.push({food_times[i], i});
    
    while()
    {
        
    }

    return answer;
}

int main()
{
    vector<int> food_times = {3, 1, 2};
    cout << solution(food_times, 5) << endl;
    return 0;
}