#include <vector>
#include <string>
#include <iostream>

#define MAX 102
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;
bool visited[MAX] = {false, };
int solution(vector<string> arr)
{
    int answer = 0;

    FOR(i, arr.size())
    {
        if(arr[i] == "-")
        {
            int num;
            vector<string> tmp;
            for(int j = i+1; j < arr.size(); j++) tmp.push_back(arr[j]);
            if(!visited[i])
            {
                visited[i] = true;
                num = solution(tmp);
                if( num < stoi(arr[i+1]))
                    return answer - num;
                else
                {
                    answer -= stoi(arr[i+1]);
                    i++;
                }
            }
            
        }
        else if(arr[i] == "+") continue;
        else answer += stoi(arr[i]);
    }

    return answer;
}

int main()
{
    vector<string> arr 
    // = {"1", "-", "3", "+", "5", "-", "8"};
    // = {"5", "-", "3", "+", "1", "+", "2", "-", "4"};
    = {"5", "-", "10", "-", "2", "-", "4", "+", "6", "+", "3", "-", "7", "+", "6", "+", "1"};
    cout << solution(arr);
    return 0;
}