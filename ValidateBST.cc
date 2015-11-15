#include<all.h>
struct TreeNode
{
	int val;
	TreeNode *left, *right;
};
void dfs(TreeNode* root, vector<int>& v)
{
	if(root->left)
		dfs(root->left, v);
	v.push_back(root->val);
	if(root->right)
		dfs(root->right, v);
}
bool isValidBST(TreeNode* root)
{
	vector<int> v;
	dfs(root, v);
	return is_sorted(v.begin(),v.end())&&adjacent_find(v.begin(), v.end())==v.end();
}
int main()
{

}
