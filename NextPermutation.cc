#include<all.h>
void nextPermutation(vector<int>& nums)
{
	int a;
	int i = nums.size()-2;
	for(; i>=0; --i)
	{
		if(nums[i]<nums[i+1])
		{
			a=i;
			break;
		}
	}
	if(i<0)
	{
		reverse(nums.begin(), nums.end());
		return;
	}
	auto pa = nums.begin()+a;
	auto bigger = lower_bound(pa+1, nums.end(), *pa, greater<int>())-1;
	iter_swap(pa , bigger);
	reverse(pa+1, nums.end());
	return ;
}
int main()
{
	vector<int> v;
	int a;
	while(cin>>a)
		v.push_back(a);
	nextPermutation(v);
	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;
}
