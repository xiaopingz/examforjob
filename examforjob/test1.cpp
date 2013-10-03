#if 1
#include<iostream>

//microsoft test(2013.9.28)
/*
		Given a singly linked list L:(L0,L1,L2,...,Ln-1,Ln).
		Write a program to reorder it so that it becomes(L0,Ln,L1,Ln-1,Ln-2,...).
		Notes:
		1. Space Complexity should be O(1);
		2. Only the ".next" field of a node is modifiable.
*/
struct Node
{
	int val_;
	Node * next;
	Node(int n):val_(n),next(NULL){};
};

typedef Node* list;

list generateList(int *a, int len)
{
	list p = new Node(a[0]);
	list head = p;
	for( int i=1;i<len;++i )
	{
		Node * q = new Node(a[i]);
		p->next	= q;
		p = q;
	}
	return head;
}

list reOrder(list L)
{
	//ÿ�ν����һ���ڵ���뵽����ͷ�ĺ���һ��λ��
	if( !L->next )
		return L;
	int count = 1;
	Node * vhead = L, * p = vhead, *q = p;
	while(p->next)
	{
		++count;
		q = p;
		p = p->next;
	}
	if( count%2!=0 )	
		count /= 2;
	else
		count = count/2 - 1;//����ط���Ҫע�⣬��Ȼ�ͻ����
	for( ;count>0;--count )
	{
		p->next = vhead->next;
		vhead->next = p;
		vhead = p->next;
		q->next = NULL;
		p = vhead;
		while(p->next)
		{
			q = p;
			p = p->next;
		}
	}
	return L;
}

//��ת����
list reverse(list L)
{
	if( !L->next )
		return L;
	Node * p = L->next, * t = p->next;
	L->next	= NULL;
	while(p)
	{
		p->next	=	L;
		L		=	p;
		p		=	t;
		if(p)
			t =	p->next;
	}
	return L;
}

list reOrder2(list L)
{
	//ƽ�ֳ����Σ���η�ת��Ȼ�����β��뵽ǰ�ο�϶�У�ʱ�临�Ӷȴ�O(n*n)��ΪO(n)
	if( !L->next )
		return L;
	int count = 1;
	Node * p = L , *q = L;
	while( p->next )
	{
		++count;
		p = p->next;
	}
	count /= 2;
	while( count>0 )
	{
		p = q;
		q = q->next;	//�س�����
		--count;
	}
	p->next = NULL;	//notice!
	q = reverse(q);
	p = L;
	while(p)
	{
		Node * t = q->next;
		q->next	= p->next;
		p->next = q;
		p = q->next;
		q = t;
	}
	return L;
}

void showList(list L)
{
	std::cout<<std::endl;
	while(L)
	{
		std::cout<<L->val_<<" ";
		L = L->next;
	}
}

void main()
{
	int a[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	list L = generateList(a,12);
	showList(L);
	//L = reOrder(L);
	//showList(L);
	L = reOrder2(L);
	showList(L);
}



#endif