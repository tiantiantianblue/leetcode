#include<all.h>
vector<vector<int>> threeSum(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	unordered_map<int, int> ma;
	for(auto i:nums)
		++ma[i];
	vector<vector<int>> re;
	int old=1;
	for(auto it=nums.cbegin(); it!=nums.cend(); ++it)
	{
		if(*it>0)
			break;
		if(*it==old)
			continue;
		for(auto jt=it+1; jt!=nums.cend(); ++jt)
		{
			int third = 0-*it-*jt;
			if(third<*jt)
				break;

			int count= ma.count(third);

			//auto pa = equal_range(nums.begin(), nums.end(), third);
			//int count = pa.second-pa.first;
			if(count>(*it==third)+(*jt==third))
				re.push_back({*it, *jt, third});
		}
		old=*it;
	}
	return re;
}

int main()
{
	vector<int> v={0, 0, 0};
	for(auto a:threeSum(v))
	{
		for(auto i:a)
			cout<<i<<" ";
		cout<<endl;
	}
}
