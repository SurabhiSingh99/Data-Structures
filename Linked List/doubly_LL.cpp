#include<iostream>
using namespace std;
struct node
{
	int val;
	struct node* next;
	struct node* prev;
};
node* createList()
{
	struct node* temp=NULL,*p=NULL,*f=NULL;
	char ch='y';
	int v;
	while(ch=='y'||ch=='Y')
	{
		temp=new node;
		if(temp==NULL)
		{
			cout<<"overflow\n";
			return f;
		}
		if(f==NULL)
		{
			f=temp;
		}
		cout<<"enter the value of the node:";
		cin>>v;
		temp->val=v;
		temp->next=NULL;
		if(p==NULL)
			temp->prev=NULL;
		else
		{
			temp->prev=p;
			p->next=temp;
		}
		p=temp;
		cout<<"enter another node?:";
		cin>>ch;
	}
	return f;
}
void traverseList(node* f)
{
	node* temp;
	if(f==NULL)
	{
		cout<<"no elements to print\n";
		return;
	}
	for(temp=f;temp!=NULL;temp=temp->next)
		cout<<temp->val<<"  ";
	cout<<"\n";
}
struct node* insert_b(node* f)
{
	node* temp=NULL;
	int v;
	temp=new node;
	if(temp==NULL)
	{
		cout<<"overflow\n";
		temp=f;
		return temp;
	}
	cout<<"enter the value of the node:";
	cin>>v;
	temp->val=v;
	temp->prev=NULL;
	if(f==NULL)
	{
		f=temp;
		temp->next=NULL;
		return temp;
	}
	temp->next=f;
	f->prev=temp;
	f=temp;
	return f;
	
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
		//temp->prev=NULL;
		f=temp;
	}
	temp->next=NULL;
	for(prev=f;prev->next!=NULL;prev=prev->next);
	temp->prev=prev;
	if(prev!=f)
		prev->next=temp;
	return f;
}
node* insert(node *f)
{
	node *temp=NULL,*prev=NULL;
	int v,p=2;
	cout<<"enter the position on which to insert: ";
	cin>>v;
	if(v<0)
	{
		cout<<"wrong number entered\n";
		return f;
	}
	else if(v==0)
	{
		cout<<"no node inserted\n";
		return f;
	}
	else if(v==1)
	{
		f=insert_b(f);
	}
	else
	{
		for(prev=f->next;p!=(v-1)&&prev!=NULL;p++,prev=prev->next);
		
		if(prev==NULL)
		{
			cout<<"list is not long enough\n";
			return f;
		}
		temp=new node;
		if(temp==NULL)
		{
			cout<<"overflow\n";
			return f;
		}
		cout<<"enter the value of the node: ";
		cin>>v;
		temp->val=v;
		temp->next=prev->next;
		temp->prev=prev;
		prev->next=temp;
		if(prev->next!=NULL)
		{
			prev->next->prev=temp;
		}
	}
	return f;
}
int count(node* f)
{
	int c=0;
	for(node* t=f;t!=NULL;c++,t=t->next);
	return c;
}
node* delete_b(node *f)
{
	if(f==NULL)
	{
		cout<<"underflow\n";
		return f;
	}
	if(f->next!=NULL)
	{
		f=f->next;
		delete f->prev;
		f->prev=NULL;
	}
	else
	{
		delete f;
		f=NULL;
	}
	return f;
}
node* delete_e(node* f)
{
	if(f==NULL)
	{
		cout<<"underflow\n";
		return f;
	}
	if(f->next==NULL)
	{
		delete f;
		return NULL;
	}
	node *t=NULL;
	for(t=f;t->next!=NULL;t=t->next);
	t->prev->next=NULL;
	delete t;
	return f;
}
node* delete_node(node *f)
{
	int v,p=2;
	node *temp=NULL,*prev=NULL;
	cout<<"enter the position of the node to be deleted: ";
	cin>>v;
	if(v<0)
	{
		cout<<"wrong number entered\n";
		return f;
	}
	else if(v==0)
	{
		cout<<"no node deleted\n";
		return f;
	}
	else if(v==1)
	{
		f=delete_b(f);
	}
	else
	{
		for(temp=f->next;p!=v&&temp!=NULL;p++,temp=temp->next);
		if(temp==NULL)
		{
			cout<<"list is not long enough\n";
			return f;
		}
		temp->prev->next=temp->next;
		if(temp->next!=NULL)
			temp->next->prev=temp->prev;
	}
	return f;
}
int main()
{
	struct node* first=NULL;
	int c;
	first=createList();
	//first=insert_b(first);
	//first=insert(first);
	c=count(first);
	cout<<"number of elements= "<<c<<"\n";
	first=delete_node(first);
	traverseList(first);
}
