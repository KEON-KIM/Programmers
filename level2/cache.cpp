#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
class Node
{
    private : 
        
    public :
        Node* beforeNode = nullptr;
        Node* nextNode = nullptr;

        string value;
        Node(){};
        Node(string str){value = str;};
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
            head.nextNode = &tail;
            tail.beforeNode = &head;
        }
        void insert(string str)
        {
            Node* node = new Node(str); // new node; 

            if(head.nextNode == &tail)
            {
                node->beforeNode = &head;
                node->nextNode = &tail;
                head.nextNode = node;
                tail.beforeNode = node;
            }
            else
            {
                node->nextNode = head.nextNode;
                node->beforeNode = &head;
                head.nextNode->beforeNode = node;
                head.nextNode = node;
            }
            s++;
        }

        void pop()
        {
            Node* node = tail.beforeNode->beforeNode;
            if(node == 0) return;
            tail.beforeNode = node;
            node->nextNode = &tail;

            s--;
        }


        Node* top()
        {
            if(!s) return 0;
            return head.nextNode;
        }
        int find(string str)
        {   
            int idx = 0;
            Node* cursor = head.nextNode;
            while(str != cursor->value)
            {
                if(idx >= s) return -1;
                cursor = cursor->nextNode;
                idx++;
            }
            return idx;
        }
        bool delete_node(string str)
        {
            Node* cursor = head.nextNode;
            if(!s) return false;
            while(str != cursor->value)
            {
                if(cursor == &tail || str == cursor->value)
                    break;
                cursor = cursor->nextNode;
            }
            if(cursor == &tail) return false;

            Node* next = cursor->nextNode;
            Node* before = cursor->beforeNode;
            delete cursor;
            next->beforeNode = before;
            before->nextNode = next;
            s--;

            return true;
        }

        int size()
        {
            return s;
        }

};
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    Linkedlist ll = Linkedlist();
    for(string  str : cities)
    {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        if(ll.delete_node(str)){
            answer+=1;
            ll.insert(str);
        }
        else
        {
            answer+=5;
            ll.insert(str);
            if(ll.size() > cacheSize)
                ll.pop();
        }
    }
    // cout << ll.top()->value << endl;
    // cout << ll.top()->value << endl;
    // ll.pop();
    // cout << ll.top()->value << endl;
    return answer;
}

int main()
{
    vector<string> cities
        // = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
        = {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"};
    cout << solution(3, cities);
    return 0;
}