#include<iostream>
using namespace std;

struct Node
{
	int val;
	Node *next;	
};
class LinkedList
{
	private :
		Node *start;
	public :
		LinkedList()
		{
			start = NULL;
		}
		void addNode(int v)
		{
			Node *newNode = new struct Node;
			newNode->next = NULL;
			newNode->val = v;
			Node *temp;
			if(start == NULL)				//first node to be added in list
			{
				start = newNode;
				start->next = newNode->next;
				start->val = v;
			}
			else				//addition of nodes afterwards the addition of the very first node
			{
				temp = start;
				while(temp->next!=NULL)
					temp = temp->next;
				temp->next = newNode;
			}
			cout<<"node added "<<newNode->val<<"\n";
		}
		void printList()
		{
			Node *temp;
			if(temp == NULL)
			{
				cout<<"list empty";
				return;
			}
			temp = start;
			while(temp != NULL)
			{
				cout<<temp->val<<" ";
				temp = temp->next;
			}
			cout<<"\n";
		}
		void deleteNode(int v)
		{
			Node *temp = NULL,*prev =NULL;
			temp = start;
			if(start == NULL)
			{
				cout<<"list empty\n";
				return;
			}
			while(temp != NULL)
			{
				if(temp->val == v)
				{
					if(temp == start)				//deletion at first node
					{
						start = temp->next;
					}
					else if(temp->next == NULL)		//deletion of last node
						prev->next = NULL;
					else							//deletion of node between two nodes
						prev->next = temp->next;
					delete temp;
					cout <<"node deleted "<<v<<"\n";
					break;
				}
				prev = temp;
				temp = temp->next;
			}
			if(temp == NULL)
				cout<<"no node exists with the given value\n";
			cout<<"list after deletion :\n";
			printList();
		}
		void insertNode(int v,int new_v)
		{
			Node *temp = NULL,*next = NULL;
			Node *newNode = new struct Node;
			newNode->next = NULL;
			newNode->val = new_v;
			temp = start;
			while(temp !=NULL)
			{
				next = temp->next;
				if(temp->val == v)
				{
					if(temp == start)				//insertion after first node
					{
						start->next = newNode;
						newNode->next = next;
					}
					else if(temp->next == NULL)		//insertion after last node
						temp->next = newNode;
					else							//insertion of node between two nodes
					{
						temp->next = newNode;
						newNode->next = next;
					}							
					cout <<"node inserted "<<new_v<<"\n";
					break;
				}
				temp = temp->next;
			}
			if(temp == NULL)
				cout<<"no node exists with the given value\n";
			cout<<"list after insertion :\n";
			printList();
		}
		void reverse()
		{
			Node *curr = NULL,*prev = NULL, *next = NULL;
			curr = start;
			if(start == NULL)
			{
				cout<<"list empty";
				return;
			}
			while(curr != NULL)
			{
				next = curr->next;			
				curr->next = prev;			
				prev = curr;				
				curr = next;				
			}
			start = prev;
			cout<<"list reversed : \n";
			printList();
		}
};
int main()
{
	LinkedList list1;
	list1.addNode(1);
	list1.addNode(2);
	list1.addNode(3);
	list1.addNode(4);
	list1.addNode(5);
	list1.addNode(6);
	list1.printList();
	list1.deleteNode(1);
	list1.deleteNode(4);
	list1.deleteNode(6);
	list1.insertNode(3,4);
	list1.insertNode(5,6);
	list1.insertNode(2,-2);
	list1.reverse();
}
