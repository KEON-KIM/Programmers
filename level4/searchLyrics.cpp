#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;
int wordCnt = 0;
class Trie {
    private :
        Trie *child[26]{};
        map<int, int> m;
        bool check = false;
    
    public :
        ~Trie()
        {
            for(int i = 0; i < 26; i++) delete child[i];
            map<int, int>().swap(m);
        }
        void insert(const char *word, int n, int wordSize){
            if(*word == '\0') return; 

            int next = *word - 'a';
            m[wordSize]++;
            check = true;
            if(child[next] == 0)
            {
                child[next] = new Trie();
                child[next]->insert(word + 1, n + 1, wordSize - 1);
            }else
                child[next]->insert(word + 1, n + 1, wordSize - 1);

            return;
        }

        void find(const char *word, int wordLength){
            if(*word == '\0')
            {
                if(check == false)
                    { wordCnt++; return; }
                return;
            }

            if(*word == '?')
            {
                wordCnt = m[wordLength];
                return; 
            }

            int next = *word - 'a';
            if(child[next] != 0)
                child[next]->find(word + 1, wordLength - 1);

            return;
        }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Trie trie, r_trie;
    
    FOR(i, words.size())
    {
        trie.insert(words[i].c_str(), 1, words[i].size());
        reverse(words[i].begin(), words[i].end());
        r_trie.insert(words[i].c_str(), 1, words[i].size());
    }
    
    
    FOR(i, queries.size())
    {
        if(queries[i][0] == '?')
        {
            reverse(queries[i].begin(), queries[i].end());
            r_trie.find(queries[i].c_str(), queries[i].size());
        }
        else
            trie.find(queries[i].c_str(), queries[i].size());
        
        if(wordCnt == 0) 
            answer.emplace_back(0);
        else
        {
            answer.emplace_back(wordCnt);
            wordCnt = 0; 
        }        
    }
    return answer;
}
/*vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    answer.resize(queries.size(), 0);
    for(int i = 0; i < queries.size(); i++)
    {
        for(int j = 0; j < words.size(); j++)
        {
            bool flag = true;
            if(words[j].length() != queries[i].length())
                continue;
            
            else
            {
                for(int k = 0; k < words[j].size(); k++)
                {
                    if(queries[i][k] == '?') continue;
                    else if(queries[i][k] != words[j][k]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) answer[i]++;
            }
        }
    }
    return answer;
}*/