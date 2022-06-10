#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());
    int l = 0, r = people.size() - 1;
    
    while(l<r)
    {
        int sum = people[l] + people[r];
        if(sum>limit)
            l++;
        else 
        {
            l++;
            r--;
        }
        answer++;
    }
    if(l == r) answer++;

    return answer;
}

int main()
{
    vector<int> people = {70, 50, 80, 50};
    cout << solution(people, 100);
    return 0;
}