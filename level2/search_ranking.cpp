#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;
vector<int> board[3][2][2][2];
int findQuery(vector<int> &info, int score)
{
	for(int i : info) cout << i << " ";
	cout << score << endl;
	int result = 0;
	FOR(i, 3)
	{
		if(info[0] != 3 && i != info[0]) continue;
		FOR(j, 2)
		{
			if(info[1] != 3 && j != info[1]) continue;
			FOR(k, 2)
			{
				if(info[2] != 3 && k!= info[2]) continue;
				FOR(l, 2)
				{
					if(info[3] != 3 && l!= info[3]) continue;
					for(int s : board[i][j][k][l])
						if( s >= score) result++;
				}
			}
		}
	}
	return result;
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for(string str : info)
    {
    	int score;
    	string buff;
    	vector<int> tmp;
    	istringstream ss(str);
    	while(getline(ss, buff, ' '))
    	{
    		if(buff == "cpp")
    			tmp.push_back(0);
    		else if(buff == "java")
    			tmp.push_back(1);
    		else if(buff == "python")
    			tmp.push_back(2);
    		
    		else if(buff == "backend")
    			tmp.push_back(0);
    		else if(buff == "frontend")
    			tmp.push_back(1);
    		
    		else if(buff == "junior")
    			tmp.push_back(0);
    		else if(buff == "senior")
    			tmp.push_back(1);

    		else if(buff == "chicken")
    			tmp.push_back(0);
    		else if(buff == "pizza")
    			tmp.push_back(1);

    		else
    			score = stoi(buff);
    	}
    	cout << score << endl;
    	board[tmp[0]][tmp[1]][tmp[2]][tmp[3]].push_back(score);
    }
    cout << "++++++++++++++++++++++++" << endl;
    for(string str : query)
    {
    	int score;
    	string buff;
    	vector<int> tmp;
    	istringstream ss(str);
    	while(getline(ss, buff, ' '))
    	{
    		if(buff == "and") continue;
    		if(buff == "cpp")
    			tmp.push_back(0);
    		else if(buff == "java")
    			tmp.push_back(1);
    		else if(buff == "python")
    			tmp.push_back(2);
    		else if(buff == "-")
    			tmp.push_back(3);

    		else if(buff == "backend")
    			tmp.push_back(0);
    		else if(buff == "frontend")
    			tmp.push_back(1);
    		else if(buff == "-")
    			tmp.push_back(2);

    		else if(buff == "junior")
    			tmp.push_back(0);
    		else if(buff == "senior")
    			tmp.push_back(1);
    		else if(buff == "-")
    			tmp.push_back(2);

    		else if(buff == "chicken")
    			tmp.push_back(0);
    		else if(buff == "pizza")
    			tmp.push_back(1);
    		else if(buff == "-")
    			tmp.push_back(2);
    		else
    			score = stoi(buff);
    	}
    	cout << score << endl;
    	answer.push_back(findQuery(tmp, score));
    }
    return answer;
}

int main()
{
	vector<string> info = {
		"java backend junior pizza 150",
		"python frontend senior chicken 210",
		"python frontend senior chicken 150",
		"cpp backend senior pizza 260",
		"java backend junior chicken 80",
		"python backend senior chicken 50"};

	vector<string> query = {
		"java and backend and junior and pizza 100",
		"python and frontend and senior and chicken 200",
		"cpp and - and senior and pizza 250",
		"- and backend and senior and - 150",
		"- and - and - and chicken 100",
		"- and - and - and - 150"};
	vector<int> answer = solution(info, query);
	for(int i : answer) cout << i << " ";
	return 0;
}