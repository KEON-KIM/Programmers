#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int result = 0;

int dfs(int n, int p) 
{ 
    if(n == 3 && p == 2) return 1;
    else if( n < 3 || log(n)/log(3) * 2 < p) return 0;
    else if(n==3 && p==3) return 0;

    return dfs(n-1, p+1) + (n%3 == 0 && p > 1? dfs(n/3, p-2) : 0);
}

int solution(int n) {
    int answer = 0;
    return dfs(n-2, 2);
}

int main()
{
	int n;
	cin >> n;
	cout << solution(n);
	return 0;
}