#include<iostream>
using namespace std;
struct node
{
	int val;
	struct node* next;
};
struct node* createList()
{
	char ch='y';
	struct node* first=NULL;
	struct node* ptr=NULL;
	struct node* prev=NULL;
	int v;
	do
	{
		prev=ptr;
		cout<<"enter the value for the node:";
		cin>>v;
		ptr = new struct node;
		if(ptr==NULL)
		{
			cout<<"overflow";
			return ptr;
		}
		ptr->val=v;
		if(first==NULL)
			first = ptr;
		else
			prev->next=ptr;
		ptr->next=first;
		cout<<"enter next node? :";
		cin>>ch; 
	}while(ch=='y'||ch=='Y');
	return first;
}
void traverseList(struct node* first)
{
	struct node* temp;
	if(first==NULL)
	{
		cout<<"list is empty\n";
		return;
	}
	for(temp=first;temp->next!=first;temp=temp->next)
		cout<<temp->val<<"  ";
	cout<<temp->val;
}
struct node* reverseList(struct node* first)
{
	struct node* temp=NULL;
	struct node* next_p=first->next;
	struct node* save=NULL;
	struct node* save_l=NULL;
	for(save_l=first;save_l->next!=first;save_l=save_l->next);
	for(temp=first;next_p->next!=first;)
	{
		if(temp==first)
			temp->next=save_l;
		save=next_p->next;
		next_p->next=temp;
		temp=next_p;
		next_p=save;
	}
	first=save_l;
	next_p->next=temp;
	return first;
}
struct node* mergeLists(struct node* f1,struct node* f2)
{
	struct node* f3=NULL;
	struct node* t1=f1;
	struct node* t2=f2;
	struct node* t3=NULL;
	struct node* prev=NULL;
	for(t1,t2;t1!=NULL&&t2!=NULL;)
	{
		t3=new struct node;
		if(t3==NULL)
		{
			cout<<"overflow";
			return f3;
		}
		if(f3==NULL)
		{
			f3=t3;
		}
		if(t1->val<t2->val)
		{
			t3->val=t1->val;
			t3->next=NULL;
			t1=t1->next;
			if(prev==NULL)
			{
				prev=t3;
			}
			else
			{
				prev->next=t3;
				prev=prev->next;
			}
			
		}
		else
		{
			
			t3->val=t2->val;
			t3->next=NULL;
			t2=t2->next;
			if(prev==NULL)
				prev=t3;
			else
			{
				prev->next=t3;
				prev=prev->next;
			}
			
		}
	}
	if(t1==NULL)
	{
		for(t2;t2!=NULL;t2=t2->next)
		{
			t3=new struct node;
			if(t3==NULL)
			{
				cout<<"overflow";
				return f3;
			}
			t3->val=t2->val;
			t3->next=NULL;
			prev->next=t3;
			prev=t3;
			
		}
	}
	else
	{
		for(t1;t1!=NULL;t1=t1->next)
		{
			t3=new struct node;
			if(t3==NULL)
			{
				cout<<"overflow";
				return f3;
			}
			t3->val=t1->val;
			t3->next=NULL;
			prev->next=t3;
			prev=t3;
			
		}
	}
	return f3;
}
struct node* deleteNode(struct node* f)
{
	int v;
	struct node* t=f,*prev=NULL,*next=NULL;
	if(f==NULL)
	{
		cout<<"underflow\n";
		return t;
	}
	cout<<"enter the value to be deleted:";
	cin>>v;
	cout<<"\n";
	if(f->val==v)
	{
		if(f->next==f)
		{
			delete f;
			t=NULL;
			return t;
		}
		for(next=f->next;next->next!=f;next=next->next);
		t=f->next;
		next->next=t;
		delete f;
		return t;
	}
	else
	{
		for(t=f;t->next!=f&&t->val!=v;t=t->next)
			prev=t;
		if(t->next==f&&t->val!=v)
		{
			cout<<"cannot delete element because element not found";
			t=f;
			return t;
		}
		else if(t->next==f&&t->val==v)
		{
			
			prev->next=f;
			delete t;
			t=f;
			return t;
		}
		else
		{
			next=t->next;
			delete t;
			prev->next=next;
			t=f;
			return t;
		}
	}
}
struct node* insertNode_b(struct node* f)
{
	struct node* t,*f_last;
	int v;
	t=new struct node;
	if(f==NULL)
	{
		f=t;
		f->next=t;
	}
	if(t==NULL)
	{
		t=f;
		cout<<"overflow\n";
		return t; 
	}
	for(f_last=f;f_last->next!=f;f_last=f_last->next);
	cout<<"enter the value of the node:";
	cin>>v;
	cout<<"\n";
	t->val=v;
	t->next=f;
	f_last->next=t;
	return t;
}
void insertNode_e(struct node* f)
{
	struct node* t;
	int v;
	t=new struct node;
	cout<<"enter the value of the node:";
	cin>>v;
	cout<<"\n";
	for(t=f;t->next!=f;t=t->next);
	t->next=new struct node;
	if(t==NULL)
	{
		cout<<"overflow\n";
		return; 
	}
	t->next->val=v;
	t->next->next=f;
}
void insertNode(struct node* f)
{
	struct node* t,*p,*s;
	int v;
	if(f==NULL)
	{
		cout<<"cannot do this operation in an empty list\n";
		return;
	}
	cout<<"enter value after which new node has to be inserted:";
	cin>>v;
	for(p=f;p->next!=f&&p->val!=v;p=p->next);
	if(p->next==f&&p->val!=v)
	{
		cout<<"value not found. Cannot insert";
		return;
	}
	cout<<"\nenter the value of new node:";
	cin>>v;
	s=p->next;
	t=new node;
	if(t==NULL)
	{
		cout<<"overflow";
		return;
	}
	t->val=v;
	p->next=t;
	t->next=s;
}
int main()
{
	struct node* first1=NULL;
	struct node* first2=NULL;
	struct node* first3=NULL;
	int ch;
	char ch_c='y';
	while(ch_c=='y'||ch_c=='Y')
	{
		cout<<"Enter your choice\n1.Create Linked List\n2.Traverse List\n3.Reverse Linked List\n4.Merge two lists\n5.Delete an element from list\n"
			<<"6.Insert an element in the begining\n7.Insert at end\n8.Insert after an element\nCHOICE:";
		cin>>ch;
		switch(ch)
		{
			case 1: first1=createList();
					break;
			case 2: traverseList(first1);
					break;
			case 3: first1=reverseList(first1);
					traverseList(first1);
					break;
			case 4: cout<<"enter the second list\n";
					first2=createList();
					first3=mergeLists(first1,first2);
					cout<<"lists after merging: ";
					traverseList(first3);
					break;
			case 5: first1=deleteNode(first1);
					traverseList(first1);
					break;
			case 6: first1=insertNode_b(first1);
					traverseList(first1);
					break;
			case 7: insertNode_e(first1);
					traverseList(first1);
					break;
			case 8: insertNode(first1);
					traverseList(first1);
					break;
			default: cout<<"wrong choice\n";
		}
		cout<<"\nDo another operation?:";
		cin>>ch_c;
	}
	
}
