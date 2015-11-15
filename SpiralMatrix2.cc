#include<all.h>
void change(int left, int right, int low, int high, int init, vector<vector<int>>& vv)
{
	if(left>right)
		return;
	for(int i=left; i<=right; ++i)
		vv[low][i]=init++;
	++low;
	for(int i=low; i<=high; ++i)
		vv[i][right]=init++;
	--right;
	for(int i=right; i>=left; --i)
		vv[high][i]=init++;
	--high;
	for(int i=high; i>=low; --i)
		vv[i][left]=init++;
	++left;
	change(left, right, low, high, init, vv);
}
vector<vector<int>> generateMatrix(int n)
{
	vector<vector<int>> vv;
	vector<int> v(n);
	for(int i=0; i!=n; ++i)
		vv.push_back(v);
	change(0,n-1,0,n-1,1,vv);
	return vv;
}

int main()
{
	int n;
	cin>>n;
	for(auto v:generateMatrix(n))
	{
		for(auto i:v)
			cout<<i<<" ";
		cout<<endl;
	}
}
