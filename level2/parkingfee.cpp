#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<string, int>> result;
    map<string, pair<int, bool>> inout;
    map<string, int> timeboard;
    for(string s : records)
    {
        string tmp;
        vector<string> info;
        istringstream ss(s);
        while(getline(ss, tmp, ' '))
            info.push_back(tmp);

        if(info[2][0] == 'I')
        {
            int time
                = (60 * (((info[0][0] - '0') * 10) + (info[0][1] - '0'))) + (((info[0][3] - '0') * 10) + (info[0][4] - '0'));

            inout[info[1]].first = time;
            inout[info[1]].second = true;
        }
        else
        {
            int time
                = (60 * (((info[0][0] - '0') * 10) + (info[0][1] - '0'))) + (((info[0][3] - '0') * 10) + (info[0][4] - '0'));
        
            timeboard[info[1]] += inout[info[1]].first > time? (time + 1440) - inout[info[1]].first : time - inout[info[1]].first;
            inout[info[1]].second = false;
        }
    }
    for(auto it : inout)
        if(it.second.second)
            timeboard[it.first] += 1439 - it.second.first;
    
    for(auto it : timeboard){
        if(fees[0] >= it.second)
            result.push_back({it.first, fees[1]});
        else
        {
            int fee = (it.second - fees[0]) % fees[2] ? (it.second - fees[0])/fees[2] + 1 : (it.second - fees[0])/fees[2];   
            result.push_back({it.first, fees[1] + (fee * fees[3])});
        }
    }
    
    sort(result.begin(), result.end());
    for(pair<string, int> p : result)
        answer.push_back(p.second);
    return answer;
}

int main()
{
    vector<int> fees
        = {180, 5000, 10, 600};
        // = {120, 0, 60, 591};
        // = {1, 461, 1, 10};
    vector<string> records
        = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};
        // = {"16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT","18:00 0202 OUT","23:58 3961 IN"};
        // = {"00:00 1234 IN"};
    vector<int> answer = solution(fees, records);
    for(int i : answer) cout << i << " ";
        cout << endl;
    return 0;
}