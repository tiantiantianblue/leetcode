#include"all.h"
int minDistance(string word1, string word2) 
{
	const size_t size1=word1.size()+1;
	vector<vector<int>> vv(size1);
	const size_t size2=word2.size()+1;
	for(int i=0; i!=size1; ++i)
		for(int j=0; j!=size2; ++j)
			vv[i].push_back(max(i,j));
	for(int i=1; i!=size1; ++i)
		for(int j=1; j!=size2; ++j)
		{
			if(word1[i-1]==word2[j-1])
				vv[i][j]=vv[i-1][j-1];
			else
				vv[i][j]=min({vv[i-1][j]+1, vv[i][j-1]+1, vv[i-1][j-1]+1});
		}
	return vv[size1-1][size2-1];
}
int main()
{
	string a;
	string b;
	cin>>a>>b;
	cout<<minDistance(a,b)<<endl;
}
