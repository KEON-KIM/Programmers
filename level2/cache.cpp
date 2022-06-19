#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
class Node
{
    private : 
        
    public :
        Node* beforeNode;
        Node* nextNode;

        string value;
        Node(){};
        Node(string str){value = str;}
        void print()
        {
            cout << value;
        }
};
class Linkedlist
{
    private :
        int s = 0;
        Node head;
        Node tail;

    public : 
        Linkedlist()
        {
            head = Node();
            tail = Node();
            cout << "CREATE" << endl;
        }
        void insert(string str)
        {
            Node node = Node(str); // new node;

            if(head.nextNode == 0)
            {
                node.beforeNode = &head;
                node.nextNode = &tail;
                head.nextNode = &node;
                tail.beforeNode = &node;
                cout << "FIRST IN : " << head.nextNode->value << endl;
            }

            else
            {
                cout << "BEFORE : " << &head.nextNode << "/" << &node<< endl;
                node.nextNode = head.nextNode;
                node.beforeNode = &head;
                head.nextNode->beforeNode = &node;
                head.nextNode = &node;
                cout << "AFTER IN" << endl;
                cout << "NEXT : "<< head.nextNode->value << endl;
                cout << "NEXT : "<< head.nextNode->nextNode->value << endl;
            }
            s++;
        }

        void pop()
        {
            Node* node = head.nextNode->nextNode;
            if(node == 0) return;
            head.nextNode = node;
            node->beforeNode = &head;

            s--;
        }


        Node* top()
        {
            if(!s) return 0;
            return head.nextNode;
        }

        int size()
        {
            return s;
        }

};
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    Linkedlist ll = Linkedlist();
    ll.insert("sex");
    cout << "=============" << endl;
    ll.insert("fuck");
    cout << "=============" << endl;
    ll.insert("kkk");
    cout << "=============" << endl;
    // cout << ll.top()->value << endl;
    // ll.pop();
    // cout << ll.top()->value << endl;
    return answer;
}

int main()
{
    vector<string> cities;
    solution(3, cities);
    return 0;
}