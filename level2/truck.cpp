#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int>> Que;
    int cur = 1, W = truck_weights[0], time = 1;
    Que.push({truck_weights[0], 0});
    while(!Que.empty()){
    	if(abs(time - Que.front().second) >= bridge_length){ // 모두 푸시 했을 경우
    		W -= Que.front().first;
    		// time += (time - bridge_length);
    		Que.pop();
    	}
    	// cout << W <<" / " << truck_weights[cur] << endl;
    	if(cur < truck_weights.size() && weight >= W + truck_weights[cur])
    	{
    		// cout << "TIME : " << time << endl;
    		Que.push({truck_weights[cur], time++});
    		W += truck_weights[cur++];
    	}
    	else 
    		time++;
    }
    return time;
}

int main()
{
	vector<int> truck_weights = {7,4,5,6};
	// vector<int> truck_weights = {10};
	// vector<int> truck_weights = {10,10,10,10,10,10,10,10,10,10};
	cout << solution(2, 10, truck_weights);
	return 0;
}