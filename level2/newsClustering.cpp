#include <iostream>
#include <string>
#include <cmath>
#include <map>

#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;
string toChange(string str)
{
	bool flag = false;
	FOR(i, 2)
	{
		if(str[i] >= 'a')
		{
			if(str[i] == ' ' || str[i] > 'z'){ 
				flag = true;
				break;
			}
			continue;
		}

		else if(str[i] >= 'A')
		{
			if(str[i] == ' ' || str[i] > 'Z')
			{
				flag = true;
				break;
			}
			str[i] = 'a' + (str[i] - 'A');
		}

		else {flag = true; break;}
	}
	if(flag) return "";
	return str;
}
int solution(string str1, string str2) {
	float result;
    int answer = 0;
    map<string, int> collector1;
    map<string, int> collector2;
    FOR(i, str1.length() - 1)
    {
    	string tmp = "";
    	tmp += str1[i];
    	tmp += str1[i + 1];
    	string str = toChange(tmp);
    	cout << str << " ";
    	if(str == "") continue;
    	collector1[str]++;
    }
    cout << endl;
    FOR(i, str2.length() - 1)
    {
    	string tmp = "";
    	tmp += str2[i];
    	tmp += str2[i + 1];
    	string str = toChange(tmp);
    	cout << str << " ";
    	if(str == "") continue;
    	collector2[str]++;
    }
    int uni = 0;
    int inter = 0;
    for(auto iter : collector1)
    {
    	if(iter.first == "") continue;
    	if(collector2.find(iter.first) != collector2.end())
    	{
			inter += min(iter.second, collector2[iter.first]);
			uni += max(iter.second, collector2[iter.first]);
    	}
    	else 
    		uni += iter.second;
    }
    for(auto iter : collector2)
    {
    	if(collector1.find(iter.first) != collector1.end()) continue;
    	else uni += iter.second;
    }

    cout << inter << " " << uni << endl;
    if(!uni|| !inter) result = 1.0f;
    else result = (float) inter / (float) uni;
    return floor(result * 65536.0f);
}

int main()
{
	cout << solution("FRANCE", "french") << endl;
	cout << solution("handshake", "shake hands	") << endl;
	cout << solution("aa1+aa2", "AAAA12") << endl;
	cout << solution("E=M*C^2", "e=m*c^2") << endl;
	cout << "===========" << endl;
	cout << solution("A+C","DEF") << endl;
	return 0;
}