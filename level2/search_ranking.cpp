#include <iostream>
#include <string>
#include <vector>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;
void print(vector<int*> board)
{
	for(int* row : board)
	{
		FOR(i, 5)
		{
			cout << row[i] << " ";
		}cout << endl;
	}
}

int countMenu(vector<int*> board, int* row)
{
	int count = 0;
	for(int *lrow : board)
	{
		FOR(i, 5)
		{
			if(i < 4){
				if(!row[i]) continue;
				if(lrow[i] != row[i]) break;
			}
			else
			{
				if(lrow[i] < row[i]) break;
				else count++;
			}
		}
	}
	return count;
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int*> board; // language, stack, ec, sf, score;
    for(string str : info)
    {
    	int idx = 0;
    	string tmp = "";
    	int *row = new int[5]; 
    	FOR(i, str.length())
    	{
    		if(str[i] == ' ' || i == str.length()-1) 
    		{
    			cout << tmp << " / " << idx<< endl;
    			if(!idx)
    			{
    				if(tmp == "java")
    					row[idx] = 1;
    				else if(tmp == "cpp")
    					row[idx] = 2;
    				else if(tmp == "python")
    					row[idx] = 3;
    				else
    					cout << "err1";
    			}

    			else if(idx == 1)
    			{
    				if(tmp == "backend")
    					row[idx] = 1;
    				else if(tmp == "frontend")
    					row[idx] = 2;
    				else
    					cout << "err2";
    			}

    			else if(idx == 2)
    			{
    				if(tmp == "junior")
    					row[idx] = 1;
    				else if(tmp == "senior")
    					row[idx] = 2;
    				else
    					cout << "err3";
    			}

    			else if(idx == 3)
    			{
    				if(tmp == "chicken")
    					row[idx] = 1;
    				else if(tmp == "pizza")
    					row[idx] = 2;
    				else
    					cout << "err4";
    			}

    			else if(idx == 4){
    				tmp += str[i];
    				row[idx] = stoi(tmp); 
    			}

    			idx++;
    			tmp = "";
    			continue;
    		}
    		tmp += str[i];
    	}
    	board.push_back(row);
    }
    
    for(string str : query)
    {
    	int idx = 0;
    	string tmp = "";
    	int *row = new int[5]; 
    	FOR(i, str.length())
    	{
    		if(str[i] == ' ' || i == str.length()-1) 
    		{
    			cout << tmp << " / " << idx<< endl;
    			if(!idx)
    			{
    				if(tmp == "java")
    					row[idx] = 1;
    				else if(tmp == "cpp")
    					row[idx] = 2;
    				else if(tmp == "python")
    					row[idx] = 3;
    			}

    			else if(idx == 1)
    			{
    				if(tmp == "backend")
    					row[idx] = 1;
    				else if(tmp == "frontend")
    					row[idx] = 2;
    			}

    			else if(idx == 2)
    			{
    				if(tmp == "junior")
    					row[idx] = 1;
    				else if(tmp == "senior")
    					row[idx] = 2;
    			}

    			else if(idx == 3)
    			{
    				if(tmp == "chicken")
    					row[idx] = 1;
    				else if(tmp == "pizza")
    					row[idx] = 2;
    			}

    			else if(idx == 4){
    				tmp += str[i];
    				row[idx] = stoi(tmp); 
    			}

    			if(tmp != "and") idx++;
    			tmp = "";
    			
    			continue;
    		}
    		tmp += str[i];
    	}
    	answer.push_back(countMenu(board, row));
    }
    cout << "====ANSWER == "<<endl;
    for(int i : answer) cout << i <<  " ";
    cout << endl; 
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
	solution(info, query);
	return 0;
}