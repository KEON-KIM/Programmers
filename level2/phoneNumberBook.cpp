#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define NUM 10
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;
class Trie 
{
    private :
        Trie *child[10]{};
        bool check = false;

    public :
        ~Trie()
        {
            FOR(i, NUM)
                delete child[i];
        }

        bool insert(const char* ptn, int wordSize)
        {
            int next = *ptn - '0';
            if(*ptn == '\0') 
            {
                return false;
                // if(child[next] == 0) {cout << "!314" << endl; return false;}
                // else {cout << "@@" << endl;return true;}
            }
            if(child[next] == 0)
            {
                child[next] = new Trie();
                if(wordSize == 1) return false;
                if(child[next]->insert(ptn+1, wordSize - 1))
                    return true;
                else return false;
            }

            else{
                if(wordSize == 1) return true;
                if(child[next]->insert(ptn+1, wordSize - 1))
                    return true;
                else return false;
            }
        }

};


bool solution(vector<string> phone_book) {
    bool answer = true;
    vector<pair<int, string>> book;
    for(string str : phone_book)
        book.push_back({str.length(), str});
    
    Trie trie; 
    sort(book.begin(), book.end(), greater<pair<int, string>>());
    FOR(i, book.size())
    {
        // cout << !trie.insert(&(book[i].second)[0], book[i].second.length()) << endl;
        if(trie.insert(&(book[i].second)[0], book[i].second.length())){
            return false;
        }
    }
    return true;

   

    return answer;
}
int main()
{
    vector<string> phone_book = {"119", "97674223", "1195524421"};
    // vector<string> phone_book = {"123","456","789"};
    // vector<string> phone_book = {"12","123","1235","567","88"};
    // vector<string> phone_book = {"12","4892", "1456", "4817259", "514569", "1456789"};

    cout << solution(phone_book) << endl;
    return 0;
}