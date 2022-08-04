//evaluating an expression using stack

#include<iostream>
#include<ctype.h>
#include<cstring>
#include<cmath>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
string priority[]={"^","*","/","+","-","%"};
struct node
{
	string val;
	node* next;
}*top1=NULL,*top2=NULL;

node* push(node* top,string v)
{
	node* temp=NULL;
	temp=new node;
	if(temp==NULL)
	{
		cout<<"overflow\n";
		temp=top;
		exit(0);
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
		exit(0);
	}
	temp=top;
	temp=temp->next;
	delete top;
	return temp;	
}

string peek(node* top)
{
	if(top!=NULL)
		return top->val;
	else
		return "&";
}

void traverse(node* top)
{
	node *temp=top;
	int i=1;
	if(top==NULL)
	{
		cout<<"no elements to print\n";
		return;
	}
	for(temp;temp!=NULL;temp=temp->next,i++)
		cout<<"\t"<<"["<<i<<"]-->"<<temp->val<<"\n";
}

node* reverse(node* top)
{
	node *f=NULL;
	string v;
	for(top;top!=NULL;)
	{
		v=peek(top);
		f=push(f,v);
		top=pop(top);
	}
	return f;
}

int check_p(string c)
{
	int i=0;
	for(i;i<6;i++)
		if(c==priority[i])
			break;
	if(i==0)
		return 1;
	if(i==1||i==2)
		return 2;
	if(i==3||i==4)
		return 3;
	if(i==5)
		return 4;
	return 0;
}
int isnum(string s)
{
	char c;
	int flag=1;
	for(int i=0;i<s.length();i++)
	{
		c=s.at(i);
		if(!isdigit(c))
		{
			flag=0;
			break;
		}
	}
	return flag;
}
int ret(string s)
{
	if(s=="+")
		return 1;
	else if(s=="-")
		return 2;
	else if(s=="*")
		return 3;
	else if(s=="/")
		return 4;
	else if(s=="^")
		return 5;
	else if(s=="%")
		return 6;
}
int myatoi(string s)
{
	int res=0,i=0;
	char c;
	for(i;i<s.length();i++)
	{
		c=s.at(i);
		res=res*10+(c-48);
	}
	//cout<<"\n res= "<<res;
	return res;
}
string evaluate(node* t)
{
	int res=0;
	char v;
	node* top=NULL;
	string temp,temp2,temp1;
	for(t;t!=NULL;)
	{
		temp=peek(t);
		//cout<<"temp="<<temp<<"\n";
		if(isnum(temp))
		{
			top=push(top,temp);
			t=pop(t);
		}
		else
		{
			temp2=peek(top);
			//cout<<"temp2="<<temp2;
			top=pop(top);
			temp1=peek(top);
			//cout<<"  temp1="<<temp1<<"\n";
			top=pop(top);
			switch(ret(temp))
			{
				case 1: res=myatoi(temp1)+myatoi(temp2);
				cout<<"add: "<<myatoi(temp1)<<" "<<myatoi(temp2)<<" \n";
						  //res=res-48;
						  break;
				case 2: res=myatoi(temp1)-myatoi(temp2);
					   	  //res=res+48;
					   	  cout<<"subtractig: "<<myatoi(temp1)<<" "<<myatoi(temp2)<<" \n";
						  break;
				case 3: res=myatoi(temp1)*myatoi(temp2);
						  //res=res+48;
						  cout<<"mul: "<<myatoi(temp1)<<" "<<myatoi(temp2)<<" \n";
						  break;
				case 4: res=myatoi(temp1)/myatoi(temp2);
						  //res=res+48;
						  cout<<"div: "<<myatoi(temp1)<<" "<<myatoi(temp2)<<" \n";
						  break;
				case 5: res=pow(myatoi(temp1),myatoi(temp2));
						  //res=res+48;
						  break;
				case 6: res=(myatoi(temp1))%(myatoi(temp2));
						  //res=res+48;
						  break;
			}
			t=pop(t);
			stringstream ss;
			ss<<res;
			temp=ss.str();
			res=0;
			top=push(top,temp);
			//temp1='&';
			//temp2='&';
		}
	}
	return top->val;
}

string eval(string exp)
{
	stringstream ss;
	int len=exp.length(),i=0,pri_p=0,pri_c=0,con=1;
	char c,val;
	string str="\0",tempc;
	for(i;i<len;i++)
	{
		c=exp.at(i);
		if(c=='+'||c=='-'||c=='^'||c=='*'||c=='/'||c=='%'||c==')')
		{
			con=0;	
		}
		if(con==0&&(isdigit(exp.at(i-1)))&&str!="\0")//str!="\0"-->5+(6*2)-(12/2)
		{
			top2=push(top2,str);
			str="\0";	
		}
		else if(isdigit(c)&&con==1)
		{
			//num=num*10+(c-48);
			str=str+c;
		}
		if(c=='(')
		{
			ss<<c;
			str=ss.str();
			//cout<<"opening bracket: "<<str;
			ss.str("");
			top1=push(top1,str);
			str="\0";	
		}
		else if(c==')')
		{
			tempc=peek(top1);
			while(tempc!="(")
			{
				top1=pop(top1); //can be mistake
				top2=push(top2,tempc);
				tempc=peek(top1);
			}
			top1=pop(top1); //for the opening bracket	
			con=1;
		}
		else if(c=='+'||c=='-'||c=='^'||c=='*'||c=='/'||c=='%')
		{
				ss<<c;
				str=ss.str();
				//ss.str(""); //clearing the ss stream
				tempc=peek(top1);
				if(tempc=="+"||tempc=="-"||tempc=="^"||tempc=="*"||tempc=="/"||tempc=="%")
				{
					pri_p=check_p(tempc);
					pri_c=check_p(str);
					if(pri_c>=pri_p) //because higher priority returns lower value
					{
						do
						{
							top1=pop(top1);
							top2=push(top2,tempc);
							tempc=peek(top1);
							pri_p=check_p(tempc);
						}while(pri_c>=pri_p&&pri_p!=0);//(tempc=='+'||tempc=='-'||tempc=='^'||tempc=='*'||tempc=='/'||tempc=='%'));
						top1=push(top1,str);
					}
					else
						top1=push(top1,str);	
				}
				else
				{
					top1=push(top1,str);
				}
				str="\0";
				//num=0;
				ss.str("");
				c='\0';
				con=1;	
		}
		//cout<<i;
	}
	if(con==1&&str!="\0")
	{
		top2=push(top2,str);
	}
	if(top1!=NULL)
	{
		while(top1!=NULL)
		{
			tempc=peek(top1);
			top1=pop(top1);
			top2=push(top2,tempc);
		}	
	}
	top1=reverse(top2);
	top2=NULL;
	traverse(top1);
	tempc=evaluate(top1);
	return tempc;
}
int main()
{
	string exp;
	string v;
	cout<<"enter the expression:";
	getline(cin,exp);
	v=eval(exp);
	cout<<"\nthe answer is:"<<v;	
}
