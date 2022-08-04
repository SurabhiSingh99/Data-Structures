#include<iostream>
using namespace std;
struct node
{
	int val;
	node* prev;
	node* next;
};
node* createList()
{
	node *f=NULL;
	node *temp=NULL;
	node *prev=NULL;
	int v;
	char ch='y';
	while(ch=='y'||ch=='Y')
	{
		temp=new node;
		if(temp==NULL)
		{
			cout<<"overflow";
			return f;
		}
		if(f==NULL)
			f=temp;
		temp->next=f;
		temp->prev=prev;
		if(prev!=NULL)
			prev->next=temp;
		cout<<"enter the value of the node: ";
		cin>>v;
		temp->val=v;
		prev=temp;
		cout<<"continue? : ";
		cin>>ch;
	}
	return f;
}
void traverse(node* f)
{
	node* temp=NULL;
	if(f==NULL)
	{
		cout<<"no elements to print\n";
		return;
	}
	for(temp=f;temp->next!=f;temp=temp->next)
		cout<<temp->val<<"  ";
	cout<<temp->val<<"\n";
}
node* insert_e(node *f)
{
	node* temp=NULL,*prev=NULL;
	int v;
	temp=new node;
	if(temp==NULL)
	{
		cout<<"overflow\n";
		temp=f;
		return temp;
	}
	cout<<"enter value: ";
	cin>>v;
	temp->val=v;
	if(f==NULL)
	{
		temp->prev=NULL;
		f=temp;
	}
	temp->next=f;
	for(prev=f;prev->next!=f;prev=prev->next);
	temp->prev=prev;
	prev->next=temp;
	return f;
}
node* insert_b(node *f)
{
	node *temp,*last=NULL;
	int v;
	temp=new node;
	if(temp==NULL)
	{
		cout<<"overflow\n";
		return f;
	}
	cout<<"enter value: ";
	cin>>v;
	temp->val=v;
	if(f!=temp&&f!=NULL)
		f->prev=temp;
	temp->prev=NULL;
	temp->next=f;
	if(f==NULL)
		f=temp;
	for(last=f;last->next!=f;last=last->next);
	last->next=temp;
	return temp;
}
void insert(node* f)
{
	node *temp=NULL,*prev=NULL;
	int v;
	if(f==NULL)
	{
		cout<<"cannot insert in empty list\n";
		return ;
	}
	temp=new node;
	if(temp==NULL)
	{
		cout<<"overflow\n";
		return ;
	}
	cout<<"enter the value after which the new node is to be inserted: ";
	cin>>v;
	for(prev=f;prev->val!=v&&prev->next!=f;prev=prev->next);
	if(prev->next==f&&prev->val!=v)
	{
		cout<<"value not found in the list\n";
		return;
	}
	else
	{
		cout<<"enter the value to be inserted: ";
		cin>>temp->val;
		temp->next=prev->next;
		prev->next->prev=temp;
		prev->next=temp;
		temp->prev=prev;
	}
}
void search(node *f)
{
	node* temp=NULL;
	int k,p=1,flag=0;
	cout<<"enter the value to be searched: ";
	cin>>k;
	for(temp=f;temp->next!=f;temp=temp->next)
	{
		if(temp->val==k)
		{
			flag=1;
			break;
		}
		p++;
	}
	if(temp->next==f&&temp->val==k||flag==1)
	{
		cout<<"element found at "<<p<<" position\n";
	}
	else
	{
		cout<<"element not found\n";
	}
}
int main()
{
	node*  first=NULL;
	first=createList();
	//first=insert_e(first);
	//first=insert_b(first);
	//insert(first);
	search(first);
	traverse(first);
}
