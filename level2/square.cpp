#include <iostream>
#define FOR(i, n) for(int i = 1; i <= n; i++)

using namespace std;
typedef long long ll;

ll GCD(ll a, ll b)
{
	if(!(a%b)) return b;
	else return GCD(b, a%b);
}

ll solution(int w,int h) 
{
    ll answer = 0;
    ll gcd = GCD(w, h);
    if(gcd > 1)
    {
    	if(w == h)
    		answer = (w * h) - gcd;
    	else
            answer = (w * h) - (w + h - gcd);
    }
    
    else
    	answer = ( w * h ) - (w + h) + 1;

    return answer;
}
int main()
{
	int N, M;
	cin >> N >> M;
	cout << N*M - solution(N, M);
	return 0;
}