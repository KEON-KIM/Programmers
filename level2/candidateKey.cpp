#include <iostream>
#include <string>
#include <vector>
#include <map>

#define MAX 21
using namespace std;

bool isCandi(vector<vector<string>> relation, vector<string> candidate, int start, int n)
{
    int idx = 0;
    for(vector<string> v : relation)
    {
        if(!idx) {idx++;continue;}
        for(int i = start, k = 0; i < start + n; i++, k++)
        {
            cout << "candidate : "<< candidate[k] << " / " << v[i] << endl;
            if(candidate[k] == v[i]) return false;
        }
        idx++;
    }
    return true;
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    int len = relation[0].size();
    bool visited[21];
    map<string, int> checkMap[21];
    for(int i = 0; i < MAX; i++) visited[i] = false;
    for(int n = 1; n <= len; n++)
    {
        for(int i = 0; i <= len - n; i++)
        {
            if(visited[i]) continue;
            bool flag = false;
            for(int k = 0; k < relation.size(); k++)
            {
                string tmp = "";
                for(int j = i; j < i + n; j++)
                {
                    tmp += relation[k][j];
                }
                
                if(checkMap[n][tmp] == 0){
                    checkMap[n][tmp]++;    
                }
                else 
                {
                    flag = true;
                    checkMap[n][tmp]++;
                }
            }
            if(!flag) 
            {
                visited[i] = true;
                answer++;
            }
        } 
    }   
    for(int i = 1; i <= len; i++)
        for(auto it : checkMap[i])
            cout << it.first << " " << i << endl;
    
    return answer;
}

int main()
{
    vector<vector<string>> relation
    = {{"100","ryan","music","2"},
    {"200","apeach","math","2"},
    {"300","tube","computer","3"},
    {"400","con","computer","4"},
    {"500","muzi","music","3"},
    {"600","apeach","music","2"}};
    cout << solution(relation);
    return 0;
}