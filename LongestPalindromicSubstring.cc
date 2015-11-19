#include<all.h>
string longestPalindrome(string s)
{
	int max_length=1;
	int begin=0;
	int size=s.size();
	int mid=size/2;
	int k=0;
	while(2*(mid-k)+1>max_length)
	{
		int mid_left=mid-k-1;
		int i=1;
		for(; i<=mid_left&&s[mid_left-i]==s[mid_left+i]; ++i);
		if(2*i-1>max_length)
			max_length=2*i-1, begin=mid_left-i+1;

		int mid_right=mid+k;
		int j=1;
		for(; j<=size-1-mid_right&&s[mid_right-j]==s[mid_right+j]; ++j);
		if(2*j-1>max_length)
			max_length=2*j-1, begin=mid_right-j+1;
		++k;
	}
	k=0;
	while(2*(size-mid-k)>max_length)
	{
		int mid_left=mid-k;
		int i=0;
		for(; i<=mid_left-1&&s[mid_left-i-1]==s[mid_left+i]; ++i);
		if(2*i>max_length)
			max_length=2*i, begin=mid_left-i;

		int mid_right=mid+k+1;
		int j=0;
		for(; mid_right+j<=size-1&&s[mid_right-j-1]==s[mid_right+j]; ++j);
		if(2*j>max_length)
			max_length=2*j, begin=mid_right-j;
		++k;
	}
	return s.substr(begin, max_length);
}
int main()
{
	string s;
	cin>>s;
	cout<<longestPalindrome(s)<<endl;
}
