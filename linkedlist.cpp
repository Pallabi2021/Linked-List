#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
	int data;
	Node* next;
};
class Linkedlist
{
	Node* head;
	public:
		Linkedlist()
		{
			head=NULL;
		}
		void insertNodeAtHead(int data)
		{
			Node* node=(Node*)malloc(sizeof(Node));
			node->data=data;
			node->next=head;
			head=node;
		}
		void insertNodeAtTail(int data)
		{
			if(head==NULL)
			{
				insertNodeAtHead(data);
				return;
			}
			Node* t=head;
			while(t->next !=NULL)
			{
				t=t->next;
			}
			Node* node=(Node*)malloc(sizeof(Node));
			node->data=data;
			node->next=NULL;
			t->next=node;
		}
		void delNodeAtHead()
		{
			if(head==NULL)
			return;
			Node* t=head;
			head=head->next;
			delete(t);
		}
		void delNodeAtTail()
		{
			if(head==NULL)
			return;
			Node* t=head;
			Node* p=t;
			if(head->next==NULL)
			{
				head=NULL;
				return;
			}
			
			while(t->next!=NULL)
			{
				p=t;
				t=t->next;
			}
			p->next=NULL;
			delete t;
		}
		void print()
		{
			Node* t=head;
			while(t!=NULL)
			{
				cout<<t->data<<endl;
                t=t->next;
			}
			
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
			while(t!=NULL)
			{
				count++;
				t=t->next;
				
			}
			return count;
		}
	};
int main()
{
	Linkedlist c=Linkedlist();
	int m=1,n;
	struct Node* head=NULL;
	while(m)
	{
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
				c.reversePrint();
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

			

		
		

