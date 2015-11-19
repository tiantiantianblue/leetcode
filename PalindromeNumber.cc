#include<all.h>
bool isPalindrome(int x)
{
	if(x<0||(x>999999999&&x%10>2))
		return false;
	int re=0;
	while(x)
	{
		re*=10;
		re+=x%10;
		x/=10;
	}
	return x==re;
}
