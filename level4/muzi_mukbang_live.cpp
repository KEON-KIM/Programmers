#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
 
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;
 
typedef pair<int, int> pii;
typedef long long ll;
int solution(vector<int> food_times, ll k) {
    ll cnt = 0, before = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pQue;
    
    FOR(i, food_times.size())
    {
        cnt += food_times[i];
        pQue.push({food_times[i], (i + 1)});
    }

    if (cnt <= k) return -1;
    while ((pQue.top().first - before) * pQue.size() <= k) 
    {
        k -= (pQue.top().first - before) * pQue.size();
        before = pQue.top().first;
        pQue.pop();
    }

    vector<pii> res;
    while (!pQue.empty()) 
    {
        res.push_back({pQue.top().second, pQue.top().first});
        pQue.pop();
    }
    sort(res.begin(), res.end());
    return res[k % res.size()].first;
}

int main()
{
    vector<int> food_times = {3, 1, 2};
    cout << solution(food_times, 5) << endl;
    return 0;
}