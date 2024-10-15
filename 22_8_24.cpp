#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

class intLink
{
	node *header ;
	
	public:
	
	intLink()
	{
		header=nullptr;
	}
	
	void insert(int d)
	{
		node *nn = new node;
		nn->data=d;
			
		if(header==nullptr)
		{
			header=nn;
			return;
		}
		
		node *temp=header;
		
		while(temp->next!=nullptr && header!=nullptr)
		{
			temp=temp->next;
		}
		temp->next=nn;
	}
	void insert(int d,int pos)
	{
		node *nn = new node;
		nn->data=d;
		
		for(int i=0,i<=pos;i++)
		{
			temp=temp->next;
		}
		
	}
	void display()
	{
		node *temp=header;
		while(temp!=NULL)
		{
			cout<<temp->data<<",";
			temp=temp->next;
		}
	}
};

int main()
{
	intLink a;
	
	a.insert(4);
	a.insert(6);
	a.display();
	return(0);
}

