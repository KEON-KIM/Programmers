#include <string>
#include <vector>

using namespace std;

string init(string word)
{
	if (word.size() < 5)
    {
		for (int i = 0; i < 5; i ++)
		{
			if(i >= word.size())
				word.push_back('-');
		}
    }

    return word;
}

int solution(string word) {
    int answer = 0;
    int cases = 1;
    int size = word.size();
    char dic[6] ={'A' , 'E' , 'I', 'O', 'U', '-' };
    
	word = init(word);

	for(int i = word.size()-1; i >= 0; i--)
	{
		for(int j = 0; j <= 5; j++)
		{
			if(word[i] == dic[j] && word[i] != '-')
				answer += cases * j;
		}
		if(i == word.size()-1)
			cases = 6;
		else
			cases = (cases * 5) + 1;
	}
	answer += size;

    return answer;
}

int main()
{
	string word = "AAAAE";
					// "AAAE"	10
					// "I"	1563
					// "EIO"
	solution(word);
	return 0;
}