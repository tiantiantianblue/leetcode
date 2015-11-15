#include<all.h>
void nqueen(int k, int n, vector<int>& v, vector<vector<string>> &vv, const vector<string>& org)
{
	for(int i=0; i<k-1; ++i)
		if(abs(v[k-1]-v[i]) == k-1-i)
			return;
	if(k==n)
	{
		vector<string> vs=org;
		for(int i=0; i!=n; ++i)
			vs[i][v[i]]='Q';
		vv.push_back(vs);
		return;
	}	
	for(int i=k; i!=n; ++i)
	{
		swap(v[k], v[i]);
		nqueen(k+1, n, v, vv, org);
		swap(v[k], v[i]);
	}
}
vector<vector<string>> solveNQueens(int n) 
{
	vector<int> v;
	for(int i=0; i!=n; ++i)
		v.push_back(i);
	string s;
	for(int i=0;i!=n; ++i)
		s+='.';
	vector<string> org;
	for(int i=0; i!=n; ++i)
		org.push_back(s);
	vector<vector<string>> vv;
	nqueen(0, n, v, vv, org);
	return vv;
}
int main()
{
	cout<<solveNQueens(8).size()<<endl;	
}
