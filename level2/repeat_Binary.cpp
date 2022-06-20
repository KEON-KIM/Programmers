#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string itob(int len)
{
    string binary = "";
    while(len != 1)
    {
        binary += len%2 + '0';
        len /= 2;
    }
    if(len) binary += len + '0';
    reverse(binary.begin(), binary.end());

    return binary;
}
vector<int> solution(string s) {
    vector<int> answer;
    answer.resize(2);
    while(s.length() != 1)
    {
        int len = s.length();
        string tmp = "";
        for(char c : s)
        {
            if(c == '0')
                answer[1]++;
            else
                tmp+=c;
        }
        answer[0]++;
        s = itob(tmp.length());
        cout << s << endl;
    }
    return answer;
}

int main()
{
    vector<int> answer;
    string s 
        // = "110010101001";
        // = "01110";
        = "1111111";
    answer = solution(s);
    cout << answer[0] << " / " << answer[1] << endl;
    return 0;
}