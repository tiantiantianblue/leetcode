#include<all.h>
   inline bool near(const string& a, const string& b)
{
	int diff=0;
	for(int i=0; i!=a.size(); ++i)
		if(a[i]!=b[i])
			if(++diff>1)
			return false;
	return true;
}

void getPath(vector<unordered_set<string>> &v, int k, const string& current, vector<string> path,  vector<vector<string>>& paths)
{
	path.push_back(current);	
	if(!k)
	{
		reverse(path.begin(), path.end());
		paths.push_back(move(path));
		return;
	}
	for(const string& s: v[k-1])
	{
		if(near(s,current))
			getPath(v, k-1, s, path, paths);
	}
}
vector<vector<string>> ladderLength(string beginWord, string endWord, unordered_set<string>& wordList)
{
	vector<unordered_set<string>> v;
	wordList.insert(endWord);
	v.push_back(unordered_set<string>{beginWord});
	bool get=false;
	while(!v[v.size()-1].empty())
	{
		unordered_set<string> us;
		for(const auto& s: v[v.size()-1])
		{
			for(auto it=wordList.begin(); it!=wordList.end();)
				if(near(*it, s))
				{
					if(*it==endWord)
					{
						get=true;
						goto find;
					}
					us.insert(move(*it));
					it=wordList.erase(it);
				}
				else
				++it;
		}
		v.push_back(move(us));
	}
find:
	if(!get)
		return vector<vector<string>>();
	v.push_back(unordered_set<string>{endWord});
	cout<<v.size()<<endl;
	vector<string> path;
	vector<vector<string>> paths;
	getPath(v, v.size()-1, endWord, path, paths);	
	return paths;
}
int main()
{
	unordered_set<string> se{"hot", "dot", "dog", "lot", "log"};
	for(auto v:ladderLength("hit", "cog", se))
	{
		for(string s:v)
			cout<<s<<" ";
		cout<<endl;
	}
}
