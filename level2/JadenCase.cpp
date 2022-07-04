#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";

    string tmp;
    vector<string> info;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    istringstream ss(s);

    while(getline(ss, tmp, ' '))
        info.push_back(tmp);

    for(int i = 0; i < info.size(); i++)
    {
        if(info[i] == "") {
            cout << "FUCK " << endl;
            continue;
        }
        int val = info[i][0] - 'a';
        if(val >= 0 && val <= 26)
            info[i][0] = 'A' + val;

        // if(i == info.size() - 1)
        //     return answer += info[i];
        answer += info[i] + ' ';
    }

    while(answer[answer.length()-1] == ' ')
        answer.pop_back();
    
    return answer;
}

int main()
{
    string s 
        // = "3people unFollowed    me k tomato  fasdf f dddd    fd d  d ";
        // = "for the last week";
        = "have a good  time";
    cout << solution(s);
    return 0;
}