#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int solution(int n, vector<int> cores) 
{
    int left = -1, mid = 0, right = 2e5;
    while(left+1 < right)
    {
        int cnt = cores.size();
        mid = (left+right)/2;
        for(int i : cores) cnt += mid/i;

        if(cnt < n) left = mid;
        else right = mid;
    }
    
    if(left == -1) return n;
    int cnt = cores.size();
    FOR(i, cores.size()) cnt+= left/cores[i];
    FOR(i, cores.size())
    {
        if(!((left+1)%cores[i])) cnt++;
        if(cnt == n) return i+1;
    }
    return 0;
}


int main()
{
    vector<int> cores = {1, 2, 3};

    cout << solution(6, cores);
    return 0;
}