#include <iostream>
#include <string>
#include <vector>
#include <map>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    answer.resize(2);
    map<string, int> visited;
    string before = words[0];
    for(int i = 0; i < words.size(); i++)
    {
    	if(!i) 
    	{
    		visited[words[i]]++;
    		continue;
    	}
    	if(before[before.size()-1] != words[i][0]) {
    		answer[0] = (i % n) + 1;
    		answer[1] = (i / n )+ 1;
    		// cout << (i+1)/ 2 << endl;
    		break;
    	}
    	if(!visited[words[i]])
    		visited[words[i]]++;
    	
    	else
    	{
    		answer[0] = (i % n) + 1;
    		answer[1] = (i / n )+ 1;
    		break;
    	}
    	before = words[i];
    }
    return answer;
}

int main()
{
	vector<string> words = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};
	// vector<string> words = {"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"};
	// vector<string> words = {"hello", "one", "even", "never", "now", "world", "draw"};
	vector<int> answer = solution(3, words);
	cout << answer[0] << " / " << answer[1] << endl;
	return 0;
}