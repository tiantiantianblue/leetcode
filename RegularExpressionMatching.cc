#include<all.h>
bool match(const string& s, int sb, const string& p, int pb, vector<vector<int>>& unmatch)
{
	if(sb==s.size()&&pb==p.size())
		return true;
	if(unmatch[sb][pb])
		return false;
	if(pb+1<p.size()&&p[pb+1]=='*')
	{
		if(p[pb]=='.')
		{
			for(int i=sb; i<=s.size(); ++i)
				if(match(s, i, p, pb+2, unmatch))
					return true;
		}
		else
		{
			if(sb<s.size()&&s[sb]==p[pb])
			{
				if(match(s, sb, p, pb+2, unmatch)||match(s, sb+1, p, pb, unmatch))
					return true;
			}
			else if(match(s, sb, p, pb+2, unmatch))
				return true;
		}
	}
	else if(sb<s.size()&&(p[pb]=='.'||p[pb]==s[sb])&&match(s, sb+1, p, pb+1, unmatch))
			return true;
	unmatch[sb][pb]=true;
	return false;
}
bool isMatch(string s, string p)
{
	vector<int> v(p.size()+1);
	v[p.size()]=1;
	vector<vector<int>> unmatch(s.size()+1, v);
	return match(s, 0, p, 0, unmatch);
}
int main()
{
	string s,p;
	cin>>s>>p;
	cout<<isMatch(s,p)<<endl;
}
