#include<iostream>
using namespace std;
struct node
{
	int val;
	struct node* next;
};
struct header
{
	int no_el;
	struct node* ptr;
};
void createList(struct header* f)
{
	node* prev=NULL,*temp=NULL;
	char ch='y';
	int v;
	while(ch=='y'||ch=='Y')
	{
		temp=new node;
		if(temp==NULL)
		{
			cout<<"overflow\n";
			return;
		}
		if(f->ptr==NULL)
		{
			f->ptr=temp;
		}
		else
		{
			prev->next=temp;
		}
		cout<<"enter the value of node:";
		cin>>v;
		temp->val=v;
		temp->next=NULL;
		prev=temp;
		f->no_el++;
		cout<<"enter next element?:";
		cin>>ch;	
	}
	return;
}
void traverseList(struct header* f)
{
	if(f->ptr==NULL)
	{
		cout<<"no elements to print\n";
		return;
	}
	struct node* temp;
	for(temp=f->ptr;temp!=NULL;temp=temp->next)
		cout<<temp->val<<"  ";
	cout<<"\n";
	return;
}
void insert_b(header* f)
{
	struct  node* save=NULL,*temp=NULL;
	int v;
	temp=new node;
	if(temp==NULL)
	{
		cout<<"overflow\n";
		return;
	}
	f->no_el++;
	save=f->ptr;
	f->ptr=temp;
	cout<<"enter the value of the node:";
	cin>>v;
	temp->val=v;
	if(f->ptr==NULL)
		temp->next=NULL;
	else
		temp->next=save;
}
void insert_e(header* f)
{
	node* temp=NULL,*last=NULL;
	int v;
	temp=new node;
	if(temp==NULL)
	{
		cout<<"overflow\n";
		return;
	}
	f->no_el++;
	cout<<"enter the value of the node:";
	cin>>v;
	temp->val=v;
	temp->next=NULL;
	if(f->ptr==NULL)
	{
		f->ptr=temp;
	}
	else
	{
		for(last=f->ptr;last->next!=NULL;last=last->next);
		last->next=temp;
	}
}
void insert(header* f)
{
	node* temp=NULL,*prev=NULL,*save=NULL;
	int v;
	if(f->ptr==NULL)
	{
		cout<<"cannot perform this operation in an empty list\n";
		return;
	}
	temp=new node;
	if(temp==NULL)
	{
		cout<<"overflow";
		return;
	}
	cout<<"enter the value of the node after which new node is to be inserted:";
	cin>>v;
	for(prev=f->ptr;prev->next!=NULL&&prev->val!=v;prev=prev->next);
	if(prev->next==NULL&&prev->val!=v)
	{
		cout<<"cannot insert. Element not found\n";
		return;
	}
	else 
	{
		f->no_el++;
		cout<<"enter the value of the node to be inserted:";
		cin>>v;
		temp->val=v;
		save=prev->next;
		prev->next=temp;
		temp->next=save;
	}
}
void deleteNode(header* f)
{
	node* temp=NULL,*prev=NULL,*save=NULL;
	int v;
	if(f->ptr==NULL)
	{
		cout<<"cannot delete from empty list\n";
		return;
	}
	cout<<"enter the value of the node to be deleted:";
	cin>>v;
	for(temp=f->ptr;temp->next!=NULL&&temp->val!=v;temp=temp->next)
		prev=temp;
	if(prev==NULL)
	{
			save=temp->next;
			delete temp;
			f->ptr=save;
			f->no_el--;
	}
	else if(temp->val==v)
	{
		save=temp->next;
		prev->next=save;
		delete temp;
		f->no_el--;
	}
	else
	{
		cout<<"element not found\n";
		return;
	}
}
void reverseList(header* f)
{
	struct node* temp=NULL;
	struct node* next_p=f->ptr->next;
	struct node* save=NULL;
	struct node* save_l=NULL;
	for(temp=f->ptr;next_p->next!=NULL;)
	{
		if(temp==f->ptr)
			temp->next=NULL;
		save=next_p->next;
		next_p->next=temp;
		temp=next_p;
		next_p=save;
	}
	f->ptr=next_p;
	if(next_p!=NULL)
		next_p->next=temp;
	if(save==NULL)
		temp->next=NULL;
}
int main()
{
	struct header* first=new header;
	first->ptr=NULL;
	first->no_el=0;
	createList(first);
	cout<<first->no_el<<"\n";
	traverseList(first);
	//insert_b(first);
	//cout<<first->no_el<<"\n";
	//traverseList(first);
	//insert_e(first);
	//cout<<first->no_el<<"\n";
	//insert(first);
	//cout<<first->no_el<<"\n";
	//traverseList(first);
	//deleteNode(first);
	reverseList(first);
	traverseList(first);
	return 0;
	
}
