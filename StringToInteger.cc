#include<all.h>
int myAtoi(string str)
{
	auto ia=str.cbegin();
	while(*ia==' '&&ia!=str.cend())
		++ia;
	if(ia==str.cend())
		return 0;
	int flag=1;
	if(*ia=='-')
		flag=-1, ++ia;
	else if(*ia=='+')
		++ia;
	int re=0;
	auto it=ia;
	for(;it!=str.cend(); ++it)
		if(*it>'9'||*it<'0')
			break;
		else
		{
			re*=10;
			re+=(*it-'0');
		}
	auto size=it-ia;
	if(re<0||size>10||(size==10&&*ia>'2'))
		if(flag==1)
			return numeric_limits<int>::max();
		else
			return numeric_limits<int>::min();
	return re*flag;
}
int main()
{
	string a;
	cin>>a;
	cout<<myAtoi(a)<<endl;
}
