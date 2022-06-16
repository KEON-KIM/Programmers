#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX 1000002
using namespace std;

// bool isPrime[MAX];
// void Eratosthenes()
// {
//     isPrime[0] = 0;
//     isPrime[1] = 0;
//     for(int i = 2; i < MAX; i++)
//     {
//         if(isPrime[i])
//         {            
//             for(int j = 2; j * i < MAX; j++)
//             {
//                 isPrime[i*j] = false;
//             }
//         }
//     }
// }
bool isPrime(long long num) {
    if(num == 1) 
        return false;
    else if(num == 2) 
        return true;
    
    for(long long i=2; i<= sqrt(num); ++i) 
    {
        if(num % i == 0) {
            return false;
        }
    }

    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string res = "";

    while(n > 1)
    {
        res += ((n%k) + '0');
        n /= k;
    }
    if(n > 0) res += (n + '0');
    reverse(res.begin(), res.end());
    
    string tmp = "";
    for(int i = 0; i < res.length(); i++)
    {
        if(res[i] == '0' || i == res.length() - 1)
        {
            if(res[i] != '0' && i == res.length() - 1) 
                tmp += res[i];

            long long idx = stol(tmp);
            if(isPrime(idx))
                answer++;
            
            tmp = "";
            continue;
        }

        tmp += res[i];
    }
    return answer;
}


int main()
{
    // cout << solution(524287,2);
    // cout << solution(437674, 3);
    cout << solution(110011, 10);

    return 0;
}