#include <iostream>
#include <string>
#include <vector>

#define MAX 1000001
using namespace std;

string solution(string number, int k) {
    string answer = "";
    bool visited[MAX] = {false, };
    for(int i = 0; i < number.size(); i++)
    {
        bool flag = false;
        for(int j = i + 1 ; j < i + k + 1; j++)
        {
            if(number[i] < number[j]){
                flag = true;
                break;
            }
        }
        if(!flag) visited[i] = true;
        else k--;
    }
    for(int i = 0; i < number.size() - k; i++)
        if(visited[i]) answer+= number[i];

    return answer;
}

int main()
{
    // string number = "1924";
    // string number = "1231234";
    // string number = "4177252841";
    string number = "100000000";
    cout << solution(number, 2);
    return 0;
}