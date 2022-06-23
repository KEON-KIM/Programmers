#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct datas
{
    int index;
    int number;
    string head;
    string tail;
    datas(int i, string h, string n, string t)
    {
        this->index = i;
        this->head = h;
        this->number = stoi(n);
        this->tail = t;
    }
    // void print()
    // {
    //     cout << this->head << " / " << this->number << " / " << this->tail << endl;
    // }   
    /*int cmp(string str1, string str2) // 0 : == / -1 : > / 1 : <
    {
        bool isDigit = false;
        int len = min(str1.length(), str2.length());
        if(str1[0] - '0' < 10 && str1[0] - '0' > -1) isDigit = true;
        if(isDigit)
        {
            int n1 = stoi(str1);
            int n2 = stoi(str2);
            if(n1 == n2)
                return 0;
            else if(n1 < n2)
                return 1;
            else
                return -1;
            // if(n1 == n2)
            // {
            //     if(str1.length() == str2.length()) {
            //         cout << "(==)n1 == n2 : " <<  str1 << " / " << str2 << endl;
            //         return 0;
            //     }
            //     else if(str1.length() < str2.length()){
            //         cout << "(<)n1 == n2 : " <<  str1 << " / " << str2 << endl;
            //         return 1;
            //     }
            //     else{
            //         cout << "(>)n1 == n2 : " <<  str1 << " / " << str2 << endl;
            //         return -1;
            //     }
            // }
            // else
            // {
            //     if(n1 < n2){
            //         cout << "(<)n1 != n2 : " <<  str1 << " / " << str2 << endl;
            //         return 1;
            //     }
            //     else{
            //         cout << "(>)n1 != n2 : " <<  str1 << " / " << str2 << endl;
            //         return -1;
            //     }
            // }
        }

        else
        {
            transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
            transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

            if(str1 < str2)
                return 1;
            else if(str1 == str2)
                return 0;
            else
                return -1;
        }
    }*/
    /*bool operator<(datas &right)
    {
        int h = cmp(this->head, right.head);
        cout << h << endl;
        if(!h)
        {
            int n = cmp(this->number, right.number);
            if(!n)
                return false;
            else if(n == 1)
                return true;
            else
                return false;
        }

        else if(h == 1)
            return true;

        else
            return false;
    }*/
};

bool compare(const datas& f1, const datas& f2) {
    if (f1.head == f2.head) {
        if (f1.number == f2.number) {
            return f1.index < f2.index;
        }
        else {
            return f1.number < f2.number;
        }
    }
    else {
        return f1.head < f2.head;
    }
}
 

vector<string> solution(vector<string> files) 
{
    vector<string> answer;
    vector<datas> datas_set;
    for(int t = 0; t < files.size(); t++)
    {
        string str = files[t];
        string tmp = "";
        string line[3];

        int idx = 0;
        bool num_flag = false;
        for(int i = 0; i < str.length(); i++)
        {
            if(idx < 2)
            {
                if(str[i] - '0' < 10 && str[i] - '0' > -1 && idx < 2) // digit 
                {
                    if(!num_flag)
                    {
                        num_flag = true;
                        line[idx] = tmp;
                        tmp.clear();
                        tmp += str[i];
                        idx++;
                    }
                    else
                        tmp+= str[i];
                }
                else // word
                {
                    if(num_flag)
                    {
                        num_flag = false;
                        line[idx] = tmp;
                        tmp.clear();
                        tmp += str[i];
                        idx++;
                    }
                    else
                        tmp+=str[i];
                }
            }
            else
            {
                tmp+=str[i];
                if(i == str.length()-1 && idx >=2)
                    line[idx] = tmp;
            }
        }
        cout << t << endl;
        datas_set.push_back(datas(t, line[0], line[1], line[2]));
    }

    sort(datas_set.begin(), datas_set.end(), compare);
    for(datas d : datas_set)
    {
        string tmp = d.head + to_string(d.number) + d.tail;
        answer.push_back(tmp);
    }
    
    return answer;
}

int main()
{
    vector<string> answer;
    vector<string> files 
        // = {"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"};
        // = {"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"};
        = {"muzi1.png1", "MUZI1.png2", "MUZI1.png3", "muzi1.png4"};
    answer = solution(files);
    for(string str : answer)
        cout << str << endl;
    return 0;
}