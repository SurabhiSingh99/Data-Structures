#include<iostream>
using namespace std;
struct node
{
	int val;
	node* next;
};
node* push(node* top,int v)
{
	node* temp=NULL;
	temp=new node;
	if(temp==NULL)
	{
		cout<<"overflow\n";
		temp=top;
		return temp;
	}
	temp->val=v;
	temp->next=NULL;
	if(top!=NULL)
	{
		temp->next=top;
	}
	top=temp;
	return temp;
}
node* pop(node* top)
{
	node* temp=NULL;
	if(top==NULL)
	{
		cout<<"underflow\n";
		return top;
	}
	temp=top;
	temp=temp->next;
	delete top;
	return temp;	
}
int peep(node* top)
{
	if(top!=NULL)
		return top->val;
	return 0;
}
void traverse(node* top)
{
	node *temp=top;
	if(top==NULL)
	{
		cout<<"no elements to print\n";
		return;
	}
	for(temp;temp!=NULL;temp=temp->next)
		cout<<temp->val;
}
void dec_bin(int d)
{
	node *top=NULL;
	for(d;d>0;d=d/2)
		top=push(top,d%2);
	cout<<"binary equivalent: ";
	traverse(top);
}
int main()
{
	int dec;
	cout<<"enter the number: ";
	cin>>dec;
	dec_bin(dec);
}
