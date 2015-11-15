#include<all.h>
int reverse(int x)
{
	int flag=1;
	if(x==numeric_limits<int>::min())
		return 0;
	if(x<0)
		flag = -1, x=-x;
	vector<int> v;
	while(x)
	{
		v.push_back(x%10);
		x/=10;
	}
	if(v.size()==10&&v[9]>2)
		return 0;
	int y=0;
	for(int i:v)
		y*=10, y+=i;
	if(y<0)
		return 0;
	return y*flag;
}
int main()
{
	int a;
	cin>>a;
	cout<<reverse(a)<<endl;
}
