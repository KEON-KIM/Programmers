#include <iostream>
#include <string>
#include <vector>
#include <map>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) 
{
    int answer = 0;
    map<string, int> wantMap;   
    FOR(i, want.size()) wantMap[want[i]] = number[i];
    
    for(int i = 0; i <= discount.size() - 10; i++)
    {
        int cnt = 0;
        map<string, int> tmp;
        for(int j = i; j < i+10; j++) tmp[discount[j]]++;
        for(auto it : tmp)
        {
            if(wantMap[it.first] && wantMap[it.first] <= it.second) cnt++;
        }
        if(cnt == want.size()) answer++;
    }

    return answer;
}

int main()
{
    vector<string> want
        = {"banana", "apple", "rice", "pork", "pot"};
        // = {"apple"};
    vector<string> discount
        = {"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"};
        // = {"banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana"};
    vector<int> number
        = {3, 2, 2, 2, 1};
        // = {10};
    cout << solution(want, number, discount);
    return 0;
}