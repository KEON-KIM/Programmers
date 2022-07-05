#include <string>
#include <cctype>
#include <vector>
#include <iostream>
using namespace std;
const string ivd = "invalid";
string rule1(string str){
    string ret;
    if(str.size()<3) return "-1";
    char c = str[1];
    bool ok=0;
    for(int i=0;i<str.size();i++){
        if(islower(str[i])) ok=1;
        if(i%2==0){
            if(islower(str[i])) return "-1";
            ret+=str[i];
        }else{
            if(c!=str[i]) return "-1";
        }
    }
    if(!ok) return "-1";
    return ret;
}
string allUpper(string str){
    string ret;
    for(auto c : str){
        if(!isupper(c)) return "-1";
        ret+=c;
    }
    return ret;
}
string solution(string sentence) {
    vector<bool> used(26,0);
    string answer = "";
    int it=0;
    while(!sentence.empty()){
        string ret;
        vector<int> pos;
        if(islower(sentence[0])){
            if(used[sentence[0]-'a']) return ivd;
            used[sentence[0]-'a']=1;
            for(int i=0;i<sentence.size();i++){
                if(sentence[i]==sentence[0]) {
                    pos.push_back(i);
                }
            }
            if(pos.size()!=2) return ivd;

            string center = sentence.substr(1,pos.back()-1);
            if(center=="") return ivd;
            ret = rule1(center);
            string target;
            if(ret=="-1") {
                ret=allUpper(center);
                if(ret=="-1"){
                    return ivd;
                }
            }else{
                if(used[sentence[2]-'a']) return ivd;
                used[sentence[2]-'a']=1;
            }
            sentence = sentence.substr(pos.back()+1);
        }else{
            if(sentence.size()==1 || isupper(sentence[1])){
                ret=sentence[0];
                sentence=sentence.substr(1);
            }else{
                for(int i=0;i<sentence.size();i++){
                    if(sentence[1]==sentence[i]) pos.push_back(i); 
                }

                if(pos.size()!=2){
                    if(pos.back()==sentence.size()-1) return ivd;
                    if(islower(sentence[pos.back()+1])) return ivd;
                    string center = sentence.substr(0,pos.back()+2);
                    ret=rule1(center);
                    if(ret=="-1") return ivd;
                    if(used[sentence[1]-'a']) return ivd;
                    used[sentence[1]-'a']=1;
                    sentence=sentence.substr(pos.back()+2);
                }else{
                    ret=sentence[0];
                    sentence=sentence.substr(1);
                }   
            }
        }
        answer+=ret+" ";
    }
    answer.pop_back();
    return answer;
}

int main()
{
    // cout << solution("aHbEbLbLbacWdOdRdLdDc");
    // cout << solution("HELLOWbObRbLbD");
    cout << solution("HaEaLaLObWORLDb");
    // cout << solution("HELLOWORLD");
    return 0;
}

/*#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

// transform(s.begin(), s.end(), s.begin(), ::tolower);
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence);
bool islower(char c)
{
    return 'a'<= c && c <= 'z';
}
bool isupper(char c)
{
    return 'A' <= c && c <= 'Z';
}
bool visited[26] = {false, };
int condition1(int idx, string &sentence, string &answer) // lower 'pAAAp'
{
    string tmp = "";
    if(visited[sentence[idx] - 'a']) return -1;

    visited[sentence[idx++]-'a'] = true;
    while(idx < sentence.length())
    {
        if(islower(sentence[idx]) && islower(sentence[idx+1])) break;
        if(islower(sentence[idx]) && visited[sentence[idx] - 'a']) break;
        tmp += sentence[idx++];
    }
    tmp = solution(tmp);
    answer += tmp;
    return idx;
}
int condition2(int idx, string &sentence, string &answer) //'ApApA'
{
    answer += sentence[idx++];
    if(visited[sentence[idx] - 'a']) return -1;

    visited[sentence[idx]-'a'] = true;
    while(idx < sentence.length())
    {
        if(!islower(sentence[idx]) && !islower(sentence[idx-1])) break;
        if(islower(sentence[idx]) && !visited[sentence[idx] - 'a']) break;
        if(!islower(sentence[idx]))
            answer += sentence[idx];
        idx++;
    }

    return idx - 1;
}
string solution(string sentence) {
    string answer = "";

    int idx = 0;
    bool flag = false;
    while(idx < sentence.length()-1)
    {
        if(islower(sentence[idx])){
            cout << 1 << endl;
            idx = condition1(idx, sentence, answer);
            answer += ' ';
        }
        else
        {
            cout << 2 << endl;
            idx = condition2(idx, sentence, answer);
            answer += ' ';
        }

        cout << "RES : " <<  answer << endl;
        cout << "IDX : " << idx << endl;

        if(idx == -1)
            return "invalid";
        idx++;
    }
    answer.pop_back();
    return answer;
}

int main()
{
     // cout << solution("AxAxAxAoBoBoB");
     // cout << solution("SpIpGpOpNpGJqOqA"); // 
    // cout << solution("HaEaLaLaObWORLDb");
    // cout << solution("pABCpqDEFq");
    // cout << solution("pABCpDqEqF");
    // cout << solution("ApBpCqDEFq");
    // cout << solution("ApBpCDqEqF");
    // cout << solution("aHbEbLbLbOacWdOdRdLdDc");
    cout << solution("HaEaLaLaOWaOaRaLaD");
    // cout << solution("HaEaLaLObWORLDb");

    return 0;
}*/