#include<all.h>
bool near(const string& a, const string& b)
{
	int diff=0;
	for(int i=0; i!=a.size(); ++i)
		if(a[i]!=b[i])
			if(++diff>1)
				return false;
	return true;
}
int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList)
{
	if(beginWord==endWord)
		return 1;
	wordList.insert(endWord);
	unordered_set<string> se{beginWord};
	int distance=0;
	while(!se.empty())
	{
		++distance;
		unordered_set<string> us;
		for(const auto& s: se)
		{
			if(s==endWord)
				return distance;
			for(auto it=wordList.begin(); it!=wordList.end();)
				if(near(*it, s))
				{
					us.insert(move(*it));
					it=wordList.erase(it);
				}
				else
					++it;
		}
		swap(se, us);
	}
	return 0;
}
int main()
{
	
}
