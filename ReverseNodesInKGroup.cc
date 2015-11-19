#include<all.h>
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};
ListNode* reverseKGroup(ListNode* head, int k)
{
	if(k<=1)
		return head;
	ListNode node(0);
	ListNode *l = &node;
	auto p=head;
	ListNode* pp[2];
	int m=0;
	pp[m]=l;
	while(true)
	{
		m^=1;
		pp[m] = p;
		for(int i=0; i<k-1&&p; ++i,p=p->next);
		if(!p)
		{
			pp[m^1]->next=pp[m];
			return l->next;
		}
		p = pp[m];
		auto q = p->next;
		ListNode* r;
		for(int i=0; i<k-1; ++i)
		{
			r=q->next;
			q->next=p;
			p=q;
			q=r;
		}
		pp[m^1]->next=p;
		p=q;
	}
}
int main()
{
	ListNode head(1);
	auto p=&head;
	for(int i=2; i<=5; ++i)
	{
		p->next=new ListNode(i);
		p=p->next;
	}
	p =&head;
	auto q=reverseKGroup(p, 3);
	while(q)
	{
		cout<<q->val<<" ";
		q=q->next;
	}
	cout<<endl;
}
