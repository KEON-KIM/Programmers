#include <string>
#include <vector>
#include <cmath>
#include <iostream>

#define MAX 10000000
using namespace std;

typedef long long ll;
ll divisor(ll n)
{
    if(n == 1) return 0;
    for(ll i = 2; i <= sqrt(n); i++)
    {
        if(!(n%i) && n/i <= MAX)
        {
            return n/i;
        }
    }

    return 1;
}
vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(int i = 0; i <= end - begin; i++)
        answer.push_back(divisor(i+begin));
    
    return answer;
}

int main()
{
    vector<ll> answer;
    answer = solution(1, 10);
    for(ll i : answer) cout << i << " ";
    return 0;
}