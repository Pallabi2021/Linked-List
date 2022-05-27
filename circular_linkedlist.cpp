#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
class CircularLinkedlist
{
	Node* head;
	Node* tail;
	public:
		CircularLinkedlist()
		{
			head=NULL;
			tail=NULL;
		}
		void insertNodeAtHead(int data)
		{
			if(head==NULL)
			{
				Node* node=(Node*)malloc(sizeof(Node));
				node->data=data;
				head=node;
				node->next=head;
				tail=head;
				return;
			}
			Node* node=(Node*)malloc(sizeof(Node));
			node->data=data;
			node->next=head;
			tail->next=node;
			head=node;
		}
		void insertNodeAtTail(int data)
		{
			if(head==NULL)
			{
				Node* node=(Node*)malloc(sizeof(Node));
				node->data=data;
				head=node;
				node->next=head;
				tail=head;
				return;
			}
			Node* node=(Node*)malloc(sizeof(Node));
			node->data=data;
			node->next=head;
			tail->next=node;
			tail=node;
		}
		void delNodeAtHead()
		{
			if(head==NULL)
			return;
			if(head==tail)
			{
				delete(head);
				head=tail=NULL;
				return;
			}
			Node* t=head;
			tail->next=head->next;
			head=head->next;
			delete(t);
		}
		void delNodeAtTail()
		{
			if(head==NULL)
			return;
			if(head==tail)
			{
				delete(head);
				head=tail=NULL;
				return;
			}
			Node* t=head;
			Node* p=t;
			while(t->next!=tail)
			{
				t=t->next;
			}
			t->next=head;
			p=tail;
			delete p;
			tail=t;
		}
		void print()
		{
		   	if(head==NULL)
			{
				return;
			}
			Node* t=head;
			do
			{
				cout<<t->data<<"->";
                t=t->next;
			}while(t!=head);
			
		}
		void reversePrint(Node* head)
		{
			if(head==NULL)
			{
				return;
			}
			reversePrint(head->next);
            cout<<head->data<<endl;
		}
		void reversePrint()
		{
			reversePrint(head);          
		}
		int countnode()
		{
			Node* t=head;
			int count=0;
			do
			{
				t=t->next;
				count++;
				
			}while(t!=head);
			return count;
		}
	};
int main()
{
	CircularLinkedlist c=CircularLinkedlist();
	int m=1,n;
	struct Node* head=NULL;
	while(m)
	{
		cout<<endl;
	    cout<<"1 to insert at beginning"<<endl;
		cout<<"2 to insert at tail"<<endl;	
		cout<<"3 to delete at head"<<endl;
		cout<<"4 to delete at tail"<<endl;
		cout<<"5 to print"<<endl;
		cout<<"6 to reverse print"<<endl;
		cout<<"7 to count node"<<endl;
		cout<<"0 to close"<<endl;
		cin>>m;
		system("CLS");
		switch(m)
		{
			case 1:
				cout<<"Enter value-";
				cin>> n;
				c.insertNodeAtHead(n);
				break;				
			case 2:
				cout<<"Enter value-";
				cin>> n;
				c.insertNodeAtTail(n);
				break;
			case 3:
				c.delNodeAtHead();
				break;				
			case 4:
			    c.delNodeAtTail();
				break;
			case 5:
				c.print();
				break;
			case 6:
				c.reversePrint(head);
				break;
			case 7:
				n=c.countnode();
				cout<<n<<endl;
				break;
			case 0:
				cout<<"Closing"<<endl;
				break;
			default:
				cout<<"Choice is wrong"<<endl;
				break;
			}
		}
	}

			

		
		

