#include <iostream>
#include <cmath>

using namespace std;
int ans = 0;
void dfs(int n, int a, int b)
{
	cout << n << " " << a<< " " << b << endl;
	if(a <= 1 && b <= 1) return;
    if(a <= n/2 && b <= n/2) {dfs(n/2, a, b);} 
    else if( a > n/2 && b > n/2) {dfs(n/2, a-(n/2), b-(n/2)); }
    else{
    	cout << "?" << endl;
    	while(n != 1)
    	{
    		n /=2;
    		ans++;
    	}
    	return;
    }
}
int solution(int n, int a, int b)
{
    int answer = 0;

    
    dfs(n, a, b);
    answer = ans;
    return answer;
}

int main()
{
	cout << solution(8, 4, 7);
	return 0;
}