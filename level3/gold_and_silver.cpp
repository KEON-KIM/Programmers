//Parametric Search Algorithm & binary Search
#include <string>
#include <vector>
#include <iostream>

#define INF 10e5 * 4 * 10e9
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef long long ll;

using namespace std;
ll solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    ll answer = INF;

    ll start = 0;
    ll end = INF; // max

    while (start <= end) {
        ll mid = (start + end) / 2;

        ll gc = 0;
        ll sc = 0;
        ll ac = 0;
        FOR(i, s.size()) {
            ll now_gold = (ll)g[i];
            ll now_silver = (ll)s[i];
            ll now_weight = (ll)w[i];
            ll now_time = (ll)t[i];

            ll move_cnt = mid / (now_time * 2);
            if (mid % (now_time * 2) >= t[i]) move_cnt++; //편도로 1번더 갈 수 있다면 1회 추가

            gc += (now_gold < move_cnt* now_weight) ? now_gold : move_cnt * now_weight;
            sc += (now_silver < move_cnt* now_weight) ? now_silver : move_cnt * now_weight;
            ac += (now_gold + now_silver < move_cnt* now_weight) ? now_gold + now_silver : move_cnt * now_weight;

        }

        if (gc >= a && sc >= b && ac >= a + b) {
            end = mid - 1;
            answer = min(mid, answer);
        }
        else {
            start = mid + 1;
        }

    }

    return answer;
}
int main()
{
    vector<int> g = {70,70,0};
    vector<int> s = {0,0,500};
    vector<int> w = {100,100,2};
    vector<int> t = {4,8,1};
    cout << solution(90, 500, g, s, w, t);
    return 0;
}