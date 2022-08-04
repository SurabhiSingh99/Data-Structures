#include<iostream>
using namespace std;
const int SIZE=10;
void push(int a[],int l,int s,int *t)
{
	if(*t==l)
	{
		cout<<"overflow\n";
		return;
	}
	if(*t==-1)
		*t=s;
	else
		*t=*t+1;
	cout<<"enter the value: ";
	cin>>a[*t];
}
void pop(int a[],int l,int s,int *t)
{
	if(*t==-1)
	{
		cout<<"underflow\n";
		return;
	}
	a[*t]=0;
	if(*t==s)
		*t=-1;
	else
		*t=*t-1;
}
int peek(int a[],int t)
{
	if(t==-1)
	{
		cout<<"cannot peek from empty list\n";
		return -1;
	}
	return a[t];
}
void print(int a[],int s,int t)
{
	if(t==-1)
	{
		cout<<"no elements to print\n";
		return;
	}
	for(int i=t;i>=s;i--)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}
int main()
{
	int st[SIZE];
	int l1,l2;
	int st1,st2;
	int top1=-1,top2=-1;
	cout<<"enter the length of the first stack: ";
	cin>>l1;
	l1=l1-1;
	st1=0;
	cout<<"enter the length of the second stack: ";
	cin>>l2;
	st2=l1+1;
	l2=l1+l2;
	char ch='y';
	while(ch=='y'||ch=='Y')
	{
		cout<<"a) push in first stack\nb) push in second stack\nc) pop from first stack\nd) pop from second stack\n"
			<<"e) peek from first stack\nf) peek from second stack\ng) print first stack\nh) print second stack\n";
		cin>>ch;
		switch(ch)
		{
			case 'a': push(st,l1,st1,&top1);
						break;
			case 'b': push(st,l2,st2,&top2);
						break;
			case 'c': pop(st,l1,st1,&top1);
						break;
			case 'd': pop(st,l2,st2,&top2);
						break;
			case 'e': peek(st,top1);
						break;
			case 'f': peek(st,top2);
						break;
			case 'g': print(st,st1,top1);
						break;
			case 'h': print(st,st2,top2);
						break;
			default: cout<<"wrong choice\n";
		}
		cout<<"\tcontinue?: ";
		cin>>ch;
	}
}
