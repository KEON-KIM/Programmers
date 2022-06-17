#include <iostream>
#include <string>
#include <vector>
#include <map>

#define INF 1000000001;
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;
typedef long long ll;
vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<int,int>> points;
    ll minX, minY; minX = minY = INF;
    ll maxX, maxY; maxX = maxY = -INF;
    for(int i = 0; i < line.size(); i++)
    {
        for(int j = i + 1; j < line.size(); j++)
        {
            ll adbc = (ll)line[i][0]*line[j][1]-(ll)line[i][1]*line[j][0];
            if(adbc==0)  continue;     
            ll bfed = (ll)line[i][1]*line[j][2]-(ll)line[i][2]*line[j][1];
            ll ecaf = (ll)line[i][2]*line[j][0]-(ll)line[i][0]*line[j][2];
            if((bfed%adbc!=0) || (ecaf%adbc!=0)) continue;  

            bfed/=adbc;     //x
            ecaf/=adbc;     //y
            points.push_back({bfed, ecaf});
            maxX = max(maxX,(ll)bfed);
            maxY = max(maxY,(ll)ecaf);
            minX = min(minX,(ll)bfed);
            minY = min(minY,(ll)ecaf);
        }
    }
    ll sizeX = maxX - minX + 1;
    ll sizeY = maxY - minY + 1;
    string tmp(sizeX, '.');
    answer.assign(sizeY, tmp);
    for(pair<int ,int> p : points)
        answer[maxY-p.second][p.first-minX] = '*';
    
    return answer;
}

int main()
{
    vector<vector<int>> line
        = {{2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12}};
    vector<string> answer = solution(line);
    for(string str : answer)
        cout << str << endl;
    return 0;
}