#include<iostream>
#define MAX 50
using namespace std;
int n=-1;
struct node
{
	int pri;
	int val;
};
struct node a[MAX];
void insert()
{
	int j,i;
	int p;
	if(n==MAX-1)
	{
		cout<<"overflow\n";
		return;
	}
	cout<<"enter the priority: ";
	cin>>p;
	if(n==-1)
	{
		a[0].pri=p;
		cout<<"enter the value: ";
		cin>>a[0].val;
	}
	else
	{
		for(j=0;j<=n&&p>a[j].pri;j++);
		for(i=n;i>=j;i--)
		{
			a[i+1].pri=a[i].pri;
			a[i+1].val=a[i].val;
		}
		a[j].pri=p;
		cout<<"enter the value: ";
		cin>>a[j].val;
	}
	n++;
}
void traverse()
{
	if(n<0)
	{
		cout<<"queue empty";
		return;
	}
	for(int i=0;i<=n;i++)
		cout<<"["<<a[i].pri<<"] -> "<<a[i].val<<"\n";
}
void del()
{
	if(n<0)
	{
		cout<<"no elements to delete\n";
		return;
	}
	int i;
	for(i=0;i<n;i++)
	{
		a[i].pri=a[i+1].pri;
		a[i].val=a[i+1].val;
	}
	a[i].pri=0;
	a[i].val=0;
	n--;
}
int main()
{
	char ch='y';
	do
	{
		cout<<"a) insert\nb) delete\nc) print\nCHOICE: ";
		cin>>ch;
		switch(ch)
		{
			case 'a': insert();
						break;
			case 'b': del();
						break;
			case 'c': traverse();
						break;
			default : cout<<"wrong choice\n";
		}
		cout<<"\tcontinue? ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
}
