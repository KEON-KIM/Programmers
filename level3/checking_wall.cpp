#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 201
#define INF 999999
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = INF;
    int s = weak.size();
    
    FOR(i, s-1)
        weak.push_back(weak[i] + n);

    do
    {
    	FOR(i, s)
        {
            int cnt = 0;
            bool flag = true;
            int cur = dist[cnt] + weak[i];
            
            for(int j = i + 1; j < s + i; j++)
            {
                if(cur < weak[j])
                {
                    if(cnt + 1 == dist.size()) 
                    {   
                        flag = false;
                        break;
                    }
                    else
                        cur = weak[j] + dist[++cnt];   
                }
            }
            if(flag)
                answer = min(answer, cnt + 1);  
        }
    }while(next_permutation(dist.begin(), dist.end()));
    
    if(answer == INF) return -1;
    return answer;
}

int main()
{
	vector<int> weak
		= {1, 5, 6, 10};
		// = {1, 3, 4, 9, 10};
	vector<int> dist
		= {1, 2, 3, 4};
		// = {3, 5, 7};
	cout << solution(12, weak, dist);
}