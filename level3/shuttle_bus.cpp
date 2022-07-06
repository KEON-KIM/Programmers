#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int ttoi(string t)
{
    int time = (t[0]-'0')*600 + ((t[1]-'0')* 60) + ((t[3]-'0') * 10) + (t[4] -'0');
    return time;
}
string itot(int t)
{
    string time = "";
    time += ('0' + t/600);
    t%=600;
    time += ('0' + t/60);
    t%=60;
    time += ":";
    time += ('0' + t/10);
    t%=10;
    time += ('0' + t);
    return time;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    priority_queue<int, vector<int>, greater<int>> pQue;
    for(string str : timetable)
        pQue.push(ttoi(str));

    int res;
    int start = 540;
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        if(!pQue.empty()) 
        {
            while(pQue.top() <= start && cnt < m)
            {
                if(i == n-1 && cnt == m - 1){ // 막차일 경우
                    if(pQue.size() >= m - cnt)  // 막차에 사람이 가득할 경우
                        return itot(pQue.top()-1); 
                    else // 막차에 무조건 탈 수 있는 경우.
                    {
                        pQue.pop();
                        return itot(pQue.top()+1);
                    }
                }
                
                pQue.pop();
                if(pQue.empty()) break;
                cnt++;
            }
        }
        else
        {
            int t = -1;
            while(!pQue.empty() && pQue.top() <= start)
                t = pQue.top();
            
            if(t != -1)
                return itot(pQue.top()+1);
        }
           
        
        res = start;
        start += t;
        
    }
    answer = itot(res);
    return answer;
}

int main()
{
    vector<string> timetable 
        // = {"08:00", "08:01", "08:02", "08:03"}; // 1, 1, 5
        // = {"09:10", "09:09", "08:00"}; // 2, 10, 2;
        // = {"09:00", "09:00", "09:00", "09:00"}; // 2, 1, 2;
        // = {"00:01", "00:01", "00:01", "00:01", "00:01"}; // 1, 1, 5;
        = {"23:59"}; //1, 1, 1
        // = {"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"}; //10 60 45
    cout << solution(1, 1, 1, timetable);
    return 0;
}