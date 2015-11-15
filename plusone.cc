#include "all.h"
vector<int> plusOne(vector<int>& digits) 
{
	if(digits.empty())
		return digits;
	int k = digits.size()-1;
	while(digits[k]==9&&k>=0)
		--k;
	++digits[k];
	for(int i=k+1; i!=digits.size(); ++i)
		digits[i]=0;
	if(digits[0]==10)
	{
		digits[0]=1;
		digits.push_back(0);
	}
	return digits;
}
int main()
{
	vector<int> v={1,0};
	auto r = plusOne(v);
	for(int i:r)
		cout<<i<<endl;
}
