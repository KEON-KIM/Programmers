#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int cnt;
    string temp = "";
    for(int i = 0; i < s.length(); i+=cnt)
    {
        if(s[i] - '0' >= 0 && s[i] - '0' < 10)
        {
            temp += s[i];
            cnt = 1;
        }
        else
        {
            if(s[i] == 'z')
            {
                cnt = 4;
                temp += '0';
            }
            else if(s[i] == 'o')
            {
                cnt = 3;
                temp += '1';
            }
            else if(s[i] == 't')
            {
                if(s[i+1] == 'h')
                {
                    cnt = 5;
                    temp += '3';
                }
                else
                {
                    cnt = 3;
                    temp += '2';
                }
            }
            else if(s[i] == 'f')
            {
                if(s[i+1] == 'i') temp += '5';
                else temp += '4';
                cnt = 4;
            }
            else if(s[i] == 's')
            {
                if(s[i+1] == 'i')
                {
                    cnt = 3;
                    temp += '6';
                }
                else
                {
                    cnt = 5;
                    temp += '7';
                }
            }
            else if(s[i] == 'e')
            {
                cnt = 5;
                temp += '8';
            }
            else 
            {
                cnt = 4;
                temp += '9';
            }
            
        }
    }
    answer = stoi(temp);
    return answer;
}

int main()
{
    string s
        // = "one4seveneight";  //1478
        // = "23four5six7"; // 234567
        = "2three45sixseven"; //  234567
        // = "123";   // 123
    cout << solution(s);
    return 0;
}