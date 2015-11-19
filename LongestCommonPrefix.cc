#include<all.h>
string longestCommonPrefix(vector<string>& strs)
{
	sort(strs.begin(), strs.end(), [](const string& a, const string&b){return a.size()<b.size();});
	if(strs.empty())
		return "";
	string common=strs[0];
	for(const string& s:strs)
	{
		for(int i=0; i!=common.size(); ++i)
		{
			if(common[i]!=s[i])
			{
				common=common.substr(0,i);
				break;
			}
		}
	}
	return common;
}
int main()
{

}
