#include<all.h>
struct ListNode 
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* mergeKLists(vector<ListNode*>& lists) 
{
	ListNode head(0);
	ListNode* p=&head;
	auto comp = [](const ListNode* a, const ListNode* b){return a->val>b->val;};
	priority_queue<ListNode*, vector<ListNode*>,decltype(comp)> pq(comp);
	for(ListNode* node : lists)
		if(node)
			pq.push(node);
	while(!pq.empty())
	{
		ListNode *node=pq.top();
		p->next=node;
		p=p->next;
		pq.pop();
		if(node->next)
			pq.push(node->next);
	}
	return head.next;
}
int main()
{
	vector<ListNode*> v;
	v.push_back(nullptr);
	mergeKLists(v);
}
