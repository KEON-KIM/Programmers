#include <iostream>
#include <queue>

using namespace std;

int solution(int n)
{
    int ans = 0;
    while(n > 1)
    {
        ans += n%2;
        n /= 2;
        cout << "N : " << n << endl;
    }
    if(n)ans += 1;
    else ans += 2;

    return ans;
}

int main()
{
    //5, 6, 5000
    cout << solution(5);
    return 0;
}