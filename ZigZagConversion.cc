#include<all.h>
void cc(const string& s, int k, vector<string>& v, int numRows)
{
	for(int i=0; i!=numRows&&k!=s.size(); ++i)
		v[i]+=s[k++];
	for(int j=numRows-2; j>=1&&k!=s.size(); --j)
		v[j]+=s[k++];
	if(k==s.size())
		return;
	cc(s,k,v,numRows);
}
string convert(string s, int numRows) {
	vector<string> v(numRows);
	cc(s, 0, v, numRows);
	string re;
	for(const auto& a:v)
		re+=a;
	return re;
}
int main()
{
	string s;
	cin>>s;
	int n;
	cin>>n;
	cout<<convert(s,n)<<endl;
}
