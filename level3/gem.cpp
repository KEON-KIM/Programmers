#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    map<string, int> gemMap;
    set<string> num(gems.begin(), gems.end());
    int abs, left, right;
    left = right = 0;

    for(string str : gems){
        gemMap[str]++;
        if(gemMap.size() == num.size()) break;
        right++;
    }
    abs = right - left;  
    answer[0] = left + 1;
    answer[1] = right + 1;

    while(right < gems.size()){
        string str = gems[left];
        gemMap[str]--; left++;

        if(gemMap[str] == 0) // 
        {
            right++;
            for(; right < gems.size(); right++){
                gemMap[gems[right]]++;
                if(str == gems[right])
                    break;
            }
            if(right == gems.size()) break;
        }
        if(abs > right - left){
            answer[0] = left + 1;
            answer[1] = right + 1;
            abs = right - left;
        }

    }

    return answer;
}

int main()
{
	vector<string> gems 
	// = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
	// = {"A","B","B","B","B","B","B","C","B","A"};
	= {"A", "B", "C", "C", "C", "F", "A", "B"};
	// = {"A", "B", "C", "B", "F", "D", "A", "F", "B", "D", "B"};
	// = {"A", "A", "B"};
	// = {"DIA", "EM", "EM", "RUB", "DIA"};
	vector<int> answer = solution(gems);
	for(int i : answer)
		cout << i << "/";
}