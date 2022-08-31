#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();
    int turn = len - 1; //조이스틱을 한 방향으로 쭉 움직였을 때
    for (int i = 0; i < len; i++) {
        if (name[i] - 'A' < 14) answer += name[i] - 'A';
        else answer += 'Z' - name[i] + 1;

        int ind = i + 1;
        while (ind < len && name[ind] == 'A') ind++;

        turn = min(turn, 
        	i + len - ind + min(i, len - ind));
    }

    answer += turn;
    return answer;
}

int main()
{
 	// string name = "JEROEN"; 
 	// string name = "JAN";
 	string name = "ABACADAEAFAGAHAIAJAKAL";
	cout << solution(name);
	return 0;
}
/*#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define MAX 21
#define ALPHA 26
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int solution(string name) {
    int answer = 0;
    int l, r; l = MAX; r = 0;
    int len = name.length() - 1;
    FOR(i, name.length())
    {
    	// cout << name[i] - 'A' << endl;
    	int key = abs(ALPHA - (name[i] - 'A')) > name[i] - 'A'? 
    				name[i] - 'A' : abs(ALPHA - (name[i] - 'A'));
    	// cout << "KEY : " << key << endl;
    	answer += key;
    	if(i && name[i] != 'A')
    	{
    		l = min(l, i);
    		r = max(r, i);
    	}
    }
    if(r > (len+1) - l)
    	answer += (len+1) - r;
    else
    	answer += r;

    return answer;
}*/