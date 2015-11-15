#include<all.h> 
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
	int length1=0, length2=0;
	ListNode *p=l1;
	while(p)
	{
		++length1;
		p=p->next;
	}
	p=l2;
	while(p)
		++length2, p=p->next;
	ListNode *re =length1>length2?l1:l2;
	int flag=0;
	p=re;
	while(l1&&l2)
	{
		p->val=l1->val+l2->val+flag;
		if(p->val>=10)
			p->val-=10, flag=1;
		else
			flag=0;
		p=p->next;
		l1=l1->next;
		l2=l2->next;
	}
	while(p)
	{
		p->val+=flag;
		if(p->val>=10)
			p->val-=10, flag=1;
		else
		{
			flag=0;
			break;
		}
		p=p->next;
	}
	if(!p&&flag)
	{
		ListNode* q=re;
		while(q->next)
			q=q->next;
		q->next=new ListNode(1);
	}
	return re;
}
int main()
{
	int a,b;
	ListNode *ha=new ListNode(0);
	ListNode *hb=new ListNode(0);
	ListNode *p=ha, *q=hb;
	while(cin>>a)
	{
		if(a>9)
			break;
		p->next=new ListNode(a);
		p=p->next;
	}
	while(cin>>b)
	{
		if(b>9)
			break;
		q->next=new ListNode(b);
		q=q->next;
	}

	ListNode *re = addTwoNumbers(ha->next, hb->next);
	while(re)
	{
		cout<<re->val;
		re=re->next;
	}
	cout<<endl;
}
