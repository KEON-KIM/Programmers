#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

unordered_map<string, string> parent; 
unordered_map<string, int> profit; 
void Rdfs(string name, int money) {
    if (name == "none") return; // 종료, 부모가 없음.

    int notmine = money * 0.1;
    profit[name] += (money - notmine);

    if (notmine < 1) return; 
    Rdfs(parent[name], notmine); // 재귀호출. 부모 노드의 profit 업데이트 하러.
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    FOR(i, referral.size())
    { // 맵 구성
        if (referral[i] == "-") parent[enroll[i]] = "none";
        else parent[enroll[i]] = referral[i];
    }

    FOR(i, seller.size())
        Rdfs(seller[i], amount[i] * 100);

    for (string str : enroll)
        answer.push_back(profit[str]);
    return answer;
}

int main()
{
    vector<string> enroll
        = {"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"};

    vector<string> referral
        = {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"};

    vector<string> seller
        = {"young", "john", "tod", "emily", "mary"};
        // = {"sam", "emily", "jaimie", "edward"};

    vector<int> amount
         = {12, 4, 2, 5, 10};
         // = {2, 3, 5, 4};

    vector<int> answer = solution(enroll, referral, seller, amount);
    for(int i : answer) cout << i << " ";
    cout << endl;
    return 0;
}

/*#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>

#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;
void dfs(string cur, map<string, vector<string>> &graph, map<string, int> &sellcnt, map<string, int> &sellmoeny)
{
    int money = 0;
    vector<int> upper;
    for(string str : graph[cur])
    {
        // vector<int> tmp =
        dfs(str, graph, sellcnt, sellmoeny);
        // for(int i : tmp)
        //     upper.push_back(i * 0.1);
        // upper.push_back(sellmoeny[str] * 0.1);
        sellmoeny[cur] += round(sellmoeny[str] * 0.1);
        sellmoeny[str] -= round(sellmoeny[str] * 0.1);
    }
    if(cur != "-"){
        // upper.push_back(sellcnt[cur] * 100);
        sellmoeny[cur] += (sellcnt[cur] * 100);
    }
    // cout << "CUR : " << cur << " : ";
    // for(int i : upper){
    //     cout << i * 0.9 << " ";
    //     sellmoeny[cur] += round(i * 0.9);
    // }
    // cout << endl;
    // return upper;
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, vector<string>> graph;
    map<string, int> sellcnt;
    map<string, int> sellmoeny;

    FOR(i, enroll.size())
        graph[referral[i]].push_back(enroll[i]);
    
    FOR(i, seller.size())
        sellcnt[seller[i]] += amount[i];

    dfs("-", graph, sellcnt, sellmoeny);
    // vector<int> tmp = graph["sam"];
    

    for(string str : enroll)
        answer.push_back(sellmoeny[str]);
    return answer;
}

int main()
{
    vector<string> enroll
        = {"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"};

    vector<string> referral
        = {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"};

    vector<string> seller
        = {"young", "john", "tod", "emily", "mary"};
        // = {"sam", "emily", "jaimie", "edward"};

    vector<int> amount
         = {12, 4, 2, 5, 10};
         // = {2, 3, 5, 4};

    vector<int> answer = solution(enroll, referral, seller, amount);
    for(int i : answer) cout << i << " ";
    cout << endl;
    return 0;
}*/