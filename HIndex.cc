#include<all.h>
int hIndex(vector<int>& citations)
{
	if(citations.empty())
		return 0;
	map<int,int> ma;
	for(auto i:citations)
		++ma[i];
	auto it=ma.crbegin();
	int point=0;
	for(; it!=ma.crend(); ++it)
	{
		point+=it->second;
		if(point>=it->first)
			break;
	}
	if(it==ma.crend())
		return point;
	return max(it->first, point-it->second);
}
int main()
{
	vector<int> v;
	int a;
	while(cin>>a)
		v.push_back(a);
	cout<<hIndex(v)<<endl;
}
