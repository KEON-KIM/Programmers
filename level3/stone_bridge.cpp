#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isgo(int n, int k, vector<int> &stones)
{
    int count = 0;
    for(int i = 0; i < stones.size(); i++)
    {
        if(stones[i] - n <= 0)
            count++;
        else 
            count = 0;
        
        if(count >= k)
            return true;
    }
    return false;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = 0, right = *max_element(stones.begin(),stones.end());
    int mid;
    while(left <= right)
    {
        mid = ( left + right ) / 2;
        if (isgo(mid, k, stones))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}


int main()
{
    vector<int> stones
        = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    cout << solution(stones, 3);
    return 0;
}