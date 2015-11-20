#include<all.h>
int lengthOfLIS(vector<int>& nums)
{
	vector<int> min;
	for(int num : nums)
	{
		auto it = lower_bound(min.begin(), min.end(), num);
		if(it!=min.end())
			*it=num;
		else
			min.push_back(num);
	}
	return min.size();
}
int main()
{
	vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
	cout<<lengthOfLIS(nums)<<endl;
}
