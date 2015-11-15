#include<all.h>
bool look(const string& line, int index, int maxWordLength, vector<int> &path, vector<int>& flag,  vector<vector<int>>& vv, vector<string>& re, const unordered_set<string>& dic)
{
	path.push_back(index);
	if(index==line.size())
	{
		string s;
		for(int i=1; i<path.size(); ++i)
			s+=string(line.begin()+path[i-1], line.begin()+path[i])+" ";	
		s.pop_back();
		re.push_back(s);
		return true;
	}
	if(!vv[index].empty())
	{
		for(int i:vv[index])
		{
			look(line, i, maxWordLength, path, flag, vv, re, dic);
			path.pop_back();
		}
	}
	else
	{
		if(flag[index])
			return false;
		for(int i=1; i<=maxWordLength&&(index+i)<=line.size(); ++i)
		{
			if(dic.count(string(line.begin()+index, line.begin()+index+i)))
			{
				if(look(line, index+i, maxWordLength, path, flag, vv, re, dic))
					vv[index].push_back(index+i);
				path.pop_back();
			}
		}
		flag[index]=1;
		return !vv[index].empty();
	}
	return true;
}
vector<string> wordBreak(string s, unordered_set<string>& wordDict) 
{
	int maxWordLength=0;
	for(const string& s:wordDict)
		if(s.size()>maxWordLength)
			maxWordLength=s.size();
	vector<int> flag(s.size(), 0);
	vector<int> path;
	vector<vector<int>> vv(s.size());
	vector<string> re;
	look(s, 0, maxWordLength, path, flag, vv, re, wordDict);	
	return re;
}
int main()
{
	string s;
	cin>>s;
	unordered_set<string> dic;
	string ss;
	while(cin>>ss)
		dic.insert(ss);
	for(auto a:wordBreak(s, dic))
		cout<<a<<endl;
}
