#include"all.h"
vector<int> singleNumber(vector<int>& nums) 
{
	unordered_set<int> se;
	unordered_set<int>::iterator it;
	for(int num:nums)
	{
		it=se.find(num);
		if(it==se.end())
			se.insert(num);
		else 
			se.erase(it);
	}
	return vector<int>(se.begin(),se.end());
}
int main()
{
	vector<int> v={1, 2, 1, 3, 2, 5};
	auto v2=singleNumber(v);
	for(auto i:v2)
		cout<<i<<endl;
}
