#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define MAX 1001
#define INF 100001
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;
vector<int> tree[MAX];
bool visited[MAX] = {false, };
typedef pair<int, pair<int, int>> pipii;

void dfs(int idx, int dep, vector<vector<int>> &answer)
{
    answer[0].push_back(idx);

    if(dep < MAX){
        FOR(i, tree[dep].size())
        {
            if(!visited[tree[dep][i]]){
                visited[tree[dep][i]] = true;
                dfs(tree[dep][i], dep+1, answer);
            }
        }
    }
   
    answer[1].push_back(idx);
}



struct Node{
    int x, y, index;
    Node* left;
    Node* right;
    Node(int a, int b, int c){this->x = a; this->y = b; this->index = c;}
};
bool bigger(Node a, Node b)
{
    if(a.y == b.y)
        return a.x < b.x;
    return a.y > b.y;
}
void addNode(Node* parent, Node* child)
{
    if(child-> x < parent->x)
    {
        if(parent->left == nullptr)
            parent->left = child;
        else
            addNode(parent->left, child);
    }
    else
    {
        if(parent->right == nullptr)
            parent->right = child;
        else
            addNode(parent->right, child);
    }
}
void preOrder(vector<int> &answer, Node* root)
{
    if(root == nullptr) return;
    answer.push_back(root->index);
    preOrder(answer, root->left);
    preOrder(answer, root->right);
}

void postOrder(vector<int> &answer, Node* root)
{
    if(root == nullptr) return;
    postOrder(answer, root->left);
    postOrder(answer, root->right);
    answer.push_back(root->index);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer = {{}, {}};
    vector<Node> node;
    
    FOR(i, nodeinfo.size())
    {
        Node* tmp = new Node(nodeinfo[i][0], nodeinfo[i][1], i+1);
        node.push_back(*tmp);
    }

    sort(node.begin(), node.end(), bigger);
    Node* root = &node[0];
    for(int i = 1; i < node.size(); i++)    
        addNode(root, &node[i]);

    preOrder(answer[0], root);
    postOrder(answer[1], root);

    return answer;
}

int main()
{
    vector<vector<int>> nodeinfo 
        = {{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}};

    vector<vector<int>> answer
        = solution(nodeinfo);

    FOR(i, answer[0].size())
    {
        cout << answer[0][i] << " ";
    }cout << endl;

    FOR(i, answer[0].size())
    {
        cout << answer[1][i] << " ";
    }cout << endl;
    return 0;
}