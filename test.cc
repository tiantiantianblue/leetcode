#include<all.h>
int main()
{
	set<int> se;
	cout<<sizeof se<<endl;
	for(int i=0; i!=123456; ++i)
		se.insert(i);
	cout<<sizeof se<<endl;
	reverse(se.begin(), se.end());
}
