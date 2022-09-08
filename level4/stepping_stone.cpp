#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int left = 0, right = distance;
    sort(rocks.begin(), rocks.end());

    while(left <= right)
    {
        int mid = (left + right) / 2;
        int prev = 0, cnt = 0;

        for(int i = 0; i < rocks.size(); i++)
        {
            if(rocks[i] - prev < mid) // 삭제해야함
                cnt++; // 삭제 개수 증가 
            else
                prev = rocks[i];
        }
        if(distance - prev < mid)
            cnt ++;
        if(cnt <= n)
        {
            answer = max(mid, answer);
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return answer;
}

int main()
{
    vector<int> rocks
        = {2, 14, 11, 21, 17};
    // = {1, 21, 17, 32, 6, 11, 27, 24};
    cout << solution(25, rocks, 2);
    return 0;
}

/*#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 50001
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef pair<int, int> pii;

pii navi[MAX];
bool visited[MAX] = {false, };
int solution(int distance, vector<int> rocks, int n) {
    const int inf = 1 << 31-1;
    pii val = {inf, inf};
    
    vector<pii> board;
    sort(rocks.begin(), rocks.end());
    FOR(i, rocks.size())
    {
        if(!i)
        {
            board.push_back({rocks[i], rocks[i+1] - rocks[i]});
            val = min(val, {rocks[i], rocks[i+1] - rocks[i]});
        }
        else if(i == rocks.size()-1)
        {
            board.push_back({rocks[i] - rocks[i-1], distance - rocks[i]});
            val = min(val, {rocks[i] - rocks[i-1], distance - rocks[i]});
        }
        else
        {
            board.push_back({rocks[i] - rocks[i-1], rocks[i+1] - rocks[i]});
            val = min(val, {rocks[i] - rocks[i-1], rocks[i+1] - rocks[i]});
        }
        navi[i].first = i-1;
        navi[i].second = i+1; 
    }
    while(n)
    {
        FOR(i, board.size())
        {
            if(!visited[i] && val == board[i]) // 삭제용
            {
                visited[i] = true;
                if(navi[i].first == -1)
                {
                    navi[navi[i].second].first = navi[i].first;
                    board[navi[i].second].first = rocks[navi[i].second];
                }
                else if(navi[i].second == board.size())
                {
                    navi[navi[i].first].second = navi[i].second;
                    board[navi[i].first].second = distance - rocks[navi[i].first];
                }
                else
                {
                    navi[navi[i].second].first = navi[i].first;
                    navi[navi[i].first].second = navi[i].second;
                    board[navi[i].second].first += board[i].second;
                    board[navi[i].first].second += board[i].first;
                }
                break;
            }
        }

        val = {inf, inf};
        FOR(i, board.size())
            if(!visited[i])
                val = min(val, {board[i].first, board[i].second});
        n--;
    }
    FOR(i, board.size())
        cout << visited[i] << " ";
    cout << endl;
    cout << val.first << "/" << val.second << endl;
    return min(val.first, val.second);
}
*/