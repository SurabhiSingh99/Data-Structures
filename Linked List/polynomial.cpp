#include<iostream>
#include<cstring>
#include<cmath>
#include<ctype.h>
using namespace std;
struct node
{
	int coeff;
	int power;
	struct node* next;
};
void traverseList(struct node* first)
{
	struct node* temp;
	if(first==NULL)
	{
		cout<<"list is empty\n";
		return;
	}
	for(temp=first;temp!=NULL;temp=temp->next)
	{
		if(temp->coeff>0&&temp!=first)
			cout<<"+";
		cout<<temp->coeff;
		cout<<"x";
		cout<<temp->power;
	}
		
	cout<<"\n";
	
}
struct node* insertNode_e(struct node* f,int val_c,int val_p)
{
	struct node* t,*last;
	t=new node;
	if(t==NULL)
	{
		cout<<"overflow\n";
		t=f;
		return t;
	}
	t->coeff=val_c;
	t->power=val_p;
	t->next=NULL;
	if(f==NULL)
	{
		f=t;
		return t;
	}
	for(last=f;last->next!=NULL;last=last->next);
	last->next=t;
	t=f;
	return t;
}
node* createList(string s,node* f)
{
	node* temp=NULL,*prev=NULL,*first=NULL;
	char c;
	int i,val_c=0,val_p=0,pc=0,pp=0,x=0,neg=0;
	int len=s.length();
	for(i=0;i<len;)
	{
		c=s.at(i);
		
		if(isdigit(c)&&x==0)
		{
			
			if(neg==1)
			{
				val_c=val_c*pow(10,pc)-(c-48);
				
			}
			else
			{
				val_c=val_c*pow(10,pc)+(c-48);
			}
			
			pc++;
			i++;
		}
		else if(isdigit(c)&&x==1)
		{
		
			val_p=val_p*pow(10,pp)+(c-48);
		
			pp++;
			i++;
		}
		if(c=='x')
		{
			if(val_c==0) //when the coeff is 1 i.e. val_c=0
				val_c=1;
			x=1;
			neg=0;
			i++;
		}
		if(c=='+'||c=='-')
		{
			//create new node;
			if(x==1&&val_p==0) //when power of x is 1
				val_p=1;
			if(i!=0)
			{
				first=insertNode_e(first,val_c,val_p);
				x=0;
				val_c=0;
				val_p=0;
				pp=0;
				pc=0;
			} //if first number is not negative i.e first character is not '-' or '+'	
			if(c=='-')
				neg=1;
			i++;
		}
	}
	if(x==1&&val_p==0)
		val_p=1;
	first=insertNode_e(first,val_c,val_p);
	return first;
}
node* add(node* f1,node* f2) //similar to mergesort
{
	node* f3=NULL,*temp=NULL,*t1=f1,*t2=f2,*t3=NULL,*ff=NULL;
	int val_c=0,val_p=0;
	for(t1,t2;t1!=NULL&&t2!=NULL;)
	{
		t3=new node;
		if(t3==NULL)
		{
			cout<<"overflow\n";
			t3=f3;
			return t3;
		}
		if(f3==NULL)
			f3=t3;
		t3->next=NULL;
		if(temp!=NULL)
		{
			temp->next=t3;
		}
		if(t1->power>t2->power)
		{
			t3->coeff=t1->coeff;
			t3->power=t1->power;
			t1=t1->next;
		}
		else if(t1->power==t2->power)
		{
		
			t3->coeff=t1->coeff+t2->coeff; 
			if(t3->coeff==0) //if addition results to 0,discard the element
			{
				delete t3;
				t3=NULL;
			}	
			else
				t3->power=t1->power;
			t1=t1->next;
			t2=t2->next;
		}
		else
		{
			
			t3->coeff=t2->coeff;
			t3->power=t2->power;
			t2=t2->next;
		}
		if(t3!=NULL)
			temp=t3;
	}
	if(t1==NULL)
	{
		while(t2!=NULL)
		{
			t3=new node;
			if(t3==NULL)
			{
				cout<<"overflow\n";
				t3=f3;
				return f3;
			}
			t3->next=NULL;
			if(temp!=NULL)
				temp->next=t3;
			t3->coeff=t2->coeff;
			t3->power=t2->power;
			temp=t3;
			t2=t2->next;
		}
	}
	else
	{
		while(t1!=NULL)
		{
			t3=new node;
			if(t3==NULL)
			{
				cout<<"overflow\n";
				t3=f3;
				return f3;
			}
			t3->next=NULL;
			if(temp!=NULL)
				temp->next=t3;
			t3->coeff=t1->coeff;
			t3->power=t1->power;
			temp=t3;
			t1=t1->next;
		}
	}
	return f3;
}
node* subtract(node* f1,node* f2)
{
	node* f3=NULL,*temp=NULL,*t1=f1,*t2=f2,*t3=NULL;
	int val_c=0,val_p=0;
	for(t1,t2;t1!=NULL&&t2!=NULL;)
	{
		t3=new node;
		if(t3==NULL)
		{
			cout<<"overflow\n";
			t3=f3;
			return t3;
		}
		if(f3==NULL)
			f3=t3;
		t3->next=NULL;
		if(temp!=NULL)
		{
			temp->next=t3;
		}
		if(t1->power>t2->power)
		{
			t3->coeff=t1->coeff;
			t3->power=t1->power;
			t1=t1->next;
		}
		else if(t1->power==t2->power)
		{
		
			t3->coeff=t1->coeff-t2->coeff;
			if(t3->coeff==0)
			{
				delete t3;
				t3=NULL;
			}	
			else
				t3->power=t1->power;
			t1=t1->next;
			t2=t2->next;
		}
		else
		{
			t3->coeff=(-1)*t2->coeff;
			t3->power=t2->power;
			t2=t2->next;
		}
		if(t3!=NULL)
			temp=t3;
	}
	if(t1==NULL)
	{
		while(t2!=NULL)
		{
			t3=new node;
			if(t3==NULL)
			{
				cout<<"overflow\n";
				t3=f3;
				return f3;
			}
			t3->next=NULL;
			if(temp!=NULL)
				temp->next=t3;
			t3->coeff=(-1)*t2->coeff;
			t3->power=t2->power;
			temp=t3;
			t2=t2->next;
		}
	}
	else
	{
		while(t1!=NULL)
		{
			t3=new node;
			if(t3==NULL)
			{
				cout<<"overflow\n";
				t3=f3;
				return f3;
			}
			t3->next=NULL;
			if(temp!=NULL)
				temp->next=t3;
			t3->coeff=t1->coeff;
			t3->power=t1->power;
			temp=t3;
			t1=t1->next;
		}
	}
	return f3;
}
void freeNodes(node* f)
{
	node* t=f;
	for(t;t!=NULL;t=t->next)
		delete t;
}
node* multiply(node* f1,node* f2) //first term multiplied by the second expression then the second term and so on
{
	node* fi=NULL,*f3=NULL,*t1=f1,*t2=f2,*t3=NULL,*previ=NULL,*ti=NULL,*ff=NULL;
	for(t1;t1!=NULL;t1=t1->next)
	{
		for(t2=f2;t2!=NULL;t2=t2->next)
		{
			ti=new node; //storing intermediate result
			if(ti==NULL)
			{
				cout<<"overflow\n";
				return f3;
			}
			if(previ!=NULL)
			{
				previ->next=ti;	
			}
			ti->next=NULL;
			if(fi==NULL)
				fi=ti;
			ti->coeff=t1->coeff*t2->coeff;
			ti->power=t1->power+t2->power;
			previ=ti;
		}
		if(t1==f1)
		{
			f3=ff=fi;
		}
		else
		{
			f3=ff;
			ff=add(f3,fi); //adding intermediate result to previous intermediate result
			freeNodes(f3);
			freeNodes(fi);
		}
		fi=NULL;
		ti=NULL;
		previ=NULL;
	}
	return ff;
}
int main()
{
	string poly1,poly2;
	node* f1=NULL,*f2=NULL,*f3=NULL;
	cout<<"enter the first expression:";
	getline(cin,poly1);
	cout<<"enter the second expression:";
	getline(cin,poly2);
	f1=createList(poly1,f1);
	//traverseList(f1);
	f2=createList(poly2,f2);
	//traverseList(f2);
	//f3=subtract(f1,f2);
	//traverseList(f3);
	//subtract(poly1,poly2);
	f3=multiply(f1,f2);
	traverseList(f3);
}
