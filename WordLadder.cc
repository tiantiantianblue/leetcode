#include<all.h>
int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList)
{
	if(beginWord==endWord)
		return 1;
	wordList.insert(endWord);
	vector<string> layer{beginWord};
	int distance=0;
	while(!layer.empty())
	{
		++distance;
		vector<string> next_layer;
		for(auto& s: layer)
		{
			if(s==endWord)
				return distance;
			for(int i=0; i!=s.size(); ++i)
			{
				char old = s[i];
				for(char c='a'; c<='z'; ++c)
				{
					s[i]=c;
					unordered_set<string>::const_iterator it;
					if((it = wordList.find(s))!=wordList.end())
					{
						next_layer.push_back(s);
						wordList.erase(it);
					}
				}
				s[i]=old;
			}
		}
		swap(layer, next_layer);
	}
	return 0;
}
int main()
{
	
}
