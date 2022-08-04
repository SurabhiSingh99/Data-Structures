//inser delete sort search and traverse queue using array
//plus merge by linked list
#include<iostream>
using namespace std;
int SIZE=100;
void insert(int a[],int *f,int *r)
{
	if(*f==-1)
	{
		*f=0;
		*r=0;
	}
	else
	{
		if(*r<99)
			*r=*r+1;
		else
		{
			cout<<"overflow\n";
			return ;
		}
	}
	cout<<"enter the value: ";
	cin>>a[*r];
}
void del(int a[],int *f,int *r)
{
	if(*f==-1)
	{
		cout<<"underflow\n";
		return ;
	}
	else
	{
		if(*f==*r)
			*f=*f-1;
		a[*r]=0;
		*r=*r-1;
	}
}
void sort(int a[],int *f,int *r)
{
	int i;
	for(i=*f;i<*r-1;i++)
	{
		for(int j=*f;j<=*r-i;j++)
		{
			if(a[j]<a[j-1])
			{
				a[j]=a[j-1]+a[j];
				a[j-1]=a[j]-a[j-1];
				a[j]=a[j]-a[j-1];
			}
		}
	}
}
void traverse(int a[],int *f,int *r)
{
	int i;
	for(i=*f;i<=*r;i++)
	{
		cout<<"["<<i<<"]: "<<a[i]<<"\n";
	}
}
void search(int a[],int *f,int *r)
{
	int i,key;
	cout<<"enter the value to be searched: ";
	cin>>key;
	for(i=*f;i<=*r;i++)
	{
		if(a[i]==key)
		{
			cout<<"element found at "<<i+1<<" position\n";
			return;
		}
	}
	cout<<"element not found\n";
}
int main()
{
	int queue[100],front=-1,rear=-1;
	char ch='y';
	do
	{
		cout<<"a. insert\nb. delete\nc. sort\nd. search\ne. traverse\nenter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 'a': insert(queue,&front,&rear);
					   break;
			case 'b': del(queue,&front,&rear);
						break;
			case 'c': sort(queue,&front,&rear);
						break;
			case 'd': search(queue,&front,&rear);
						break;
			case 'e': traverse(queue,&front,&rear);
					   break;
			default : cout<<"wrong input\n";
		}
		cout<<"\tcontinue?: ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
}
