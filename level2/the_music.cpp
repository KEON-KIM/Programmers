#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool compare(string str, string m)
{
    for(int i = 0; i < str.length(); i++)
    {
        int cnt = 0;
        for(int j = i; j < m.length() + i; j++)
        {
            if(str[j%str.length()] == '#') {cnt++;continue;}
            if(str[j%str.length()] != m[j - i]) break;
            else 
            {
                if(str[(j+1)%str.length()] == '#' 
                    && str[(j+1)%str.length()] != m[(j-i+1)%m.length()]) break;
                cnt++;
            }
        }
        if(cnt == m.length()) return true;
    }
    return false;
}
string solution(string m, vector<string> musicinfos) 
{
    int maxTime = 0;
    string answer = "(None)";
    vector<string> infoBoard;
    for(int i = 0; i < musicinfos.size(); i++)
    {
        int time = 0, idx = 0;
        string name, music = "", tmp = "";
        for(int j = 0; j < musicinfos[i].length(); j++)
        {
            if(musicinfos[i][j] == ',' || j == musicinfos[i].length()-1)
            {
                if(j == musicinfos[i].length()-1)
                    tmp += musicinfos[i][j];

                if(idx == 0)
                    time -= (((tmp[0] - '0') * 10 + (tmp[1] - '0')) * 60) + (((tmp[3]- '0')*10) + (tmp[4] - '0'));
               
                else if(idx == 1)
                    time += (((tmp[0] - '0') * 10 + (tmp[1] - '0')) * 60) + (((tmp[3]- '0')*10) + (tmp[4] - '0'));

                else if(idx == 2)
                    name = tmp;
                
                else
                {
                    int addTime = 0;
                    for(int t = 0; t < time + addTime - 1; t++)
                    {
                        if(tmp[t%tmp.length()] == '#') 
                        {
                            addTime++;
                            continue;
                        }
                        music += tmp[t%tmp.length()];
                        if(tmp[(t+1)%tmp.length()] == '#')
                            music += '#';
                    }               

                    cout << music << endl;
                    if (m.length() > music.length()) continue;
                    if(compare(music, m) && maxTime < time)
                    {
                        maxTime = time;
                        answer = name;
                    }
                }
                idx++;
                tmp = "";
                continue;
            }
            tmp += musicinfos[i][j];
        }
    }
    return answer;
}
int main()
{
    string m 
        // = "A#"; // "HAPPY"
        // = "CDEFGAC"; // "(None)"
        // = "CCB"; // "FOO"
        // = "ACCBA#BDC#";
        = "CD#";
        // = "ABCDEFG";
        // = "A#AB#";
        // = "CC#BCC#BCC#BCC#B";
        // = "ABC";
    vector<string> musicinfos
        // = {"13:00,13:02,HAPPY,BA#"};
        // = {"12:00,12:06,HELLO,CDEFGA"};
        // = {"03:00,03:10,FOO,CCB#CCB", "04:00,04:08,BAR,ABC"};
        // = {"03:00,03:10,FOO,CCBA#BDC#A"};
        = {"12:00,12:04,HELLO,CD#EFGA"};
        // = {"12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"};
        // = {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"};
        // = {"13:00,13:03,HAPPY,B#A#A"};
        // = {"12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"};
    cout << solution(m, musicinfos);
    return 0;
}