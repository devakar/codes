#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <vector>

using namespace std;

//structure of single linked list
typedef struct node
{
	int data;
	struct node* next;
}Node;

//structure of single linked list having two data points
typedef struct line
{
	int x,y;
	struct line* next;
}line;


//insert the item at the beigning of the single linked list.
void insert_beg(Node** head,int item)
{
	Node* newnode=new Node;
	newnode->data=item;
	newnode->next=(*head);
	(*head)=newnode;
}

//print the data of the linked list.
void print(Node* head)
{
	while(head)
	{
		cout<<head->data<<"\t";
		head=head->next;
	}
	cout<<endl;
}


//check whether a triplet from three linked list exists such their sum gives the given value.
void isSumInTriplet(Node* head1, Node* head2,Node* head3,int sum)
{
	Node* a=head1;
	int newsum;
	
	while(a)
	{
		Node* b=head2;
	    Node* c=head3;

	    while(b && c)
	    {
	    	newsum=a->data + b->data +c->data;
	    	if(sum== newsum)
	    	{
	    		cout<<"there exists a triplet "<<a->data<<", "<<b->data<<" and "<<c->data<<" whose summation is "<<sum<<endl;
	    		return;
	    	}
	    		
	    	else if(sum<newsum)
	    		c=c->next;
	    	else
	    		b=b->next;
	    }
	    a=a->next;

	}

	cout<<"there is no such triplet whose summation is "<<sum<<endl;
}


//rotate the linked list in anti clock wise by k items.
void rotate_anticlock(Node** head, int k)
{
	Node* temp=(*head);
	Node* knode=NULL;
	Node* end=NULL;
	int c=1;

	while(c<k && temp)
	{
		temp=temp->next;
		c++;
	}

	if(!temp)
		return;

	knode=temp;

	while(temp->next)
	{
		temp=temp->next;
	}

	end=temp;

	end->next=(*head);
	*head=knode->next;
	knode->next=NULL;
}



//count the number of nodes in the linked list , an utility used in addList function.
int getCount(Node* head)
{
	int c=0;
	while(head)
	{
		c++;
		head=head->next;
	}
	return c;
}

//swap the pointers ,used in swapping the head pointer of the linked list
void swapPointer(Node** a,Node** b)
{
	Node* t=*a;
	*a=*b;
	*b=t;
}

//add number represented by linked list of same size
Node* addSameSize(Node* a, Node*b, int* carry)
{
   if(!a)
   	return NULL;

   int sum;

   Node* c=new Node;

   c->next=addSameSize(a->next, b->next,carry);

    sum=a->data + b->data + *carry;
	*carry=sum/10;
	sum=sum%10;

	c->data=sum;

	return c;
	
}

//add carry to remaining portion of longer list
void addCarryToRemaining(Node* a, Node* cur, int* carry, Node** c)
{
	int sum;

    if(a!=cur)
    {
    	addCarryToRemaining(a->next,cur,carry,c);
    	sum=a->data + *carry;
    	*carry = sum/10;
    	sum=sum%10;

    	insert_beg(c,sum);
    }
}

//add two numbers represented by linked list such that head contain most significant digits.
void addList(Node* a, Node* b, Node** c)
{
	Node* cur;
	if(!a)
	{
		*c=b;
		return;
	}

	else if(!b)
	{
		*c=a;
		return;
	}

	int n1=getCount(a);
	int n2=getCount(b);

	int carry=0;

	if(n1==n2)
	{
		*c=addSameSize(a,b,&carry);
              
	}

	else
	{
		int d=abs(n1-n2);

	if(n1<n2)
	{
		swapPointer(&a,&b);

	}

	for(cur=a;d--;cur=cur->next);

	*c=addSameSize(cur,b,&carry);

    addCarryToRemaining(a,cur,&carry,c);

	}
	
    if(carry)
    	insert_beg(c,carry);
}

//get last node of the linked list node
Node* getTail(Node* head)
{
	Node* temp=head;
	while(temp->next)
		temp=temp->next;

	return temp;
}

//sort linked list of 0's , 1's , and 2's. (we can also do by counting no. of 1s,2s,3s and then insert in the list)
void sort_012(Node** head)
{
	Node* tail=getTail(*head);
	Node* cur=(*head);
	Node* temp=(*head);
	Node* prev=NULL;
	Node* newtail=tail;

	if(!(*head))
		return;


	while(cur!=tail)
	{
		Node* nex=cur->next;
		if(cur->data == 0)
		{
			if(cur==*head)
			{
				prev=cur;
				cur=cur->next;

			}
			else
			{
				
				prev->next=cur->next;
				cur->next=*head;
                *head=cur;
                cur=prev->next;
			}

		}

		else if(cur->data==2)
		{
			if(cur==*head)
			{
				newtail->next=cur;
				*head=cur->next;
			    newtail=cur;
			    newtail->next=NULL;
			    cur=(*head);

			}

			else
			{
				prev->next=cur->next;
			    newtail->next=cur;
			    newtail=cur;
			    newtail->next=NULL;
			    cur=prev->next;

			}
			
		}

		else
		{
			prev=cur;
		    cur=cur->next;

		}


        
	}

	if(cur==tail && cur->data==0)
		{
			    prev->next=cur->next;
				cur->next=*head;
                *head=cur;
                cur=prev->next;
		}
}

//delete n nodes after mth node
void deleteNafterM(Node**head, int n, int m)
{
	int n2=0,m2=1;
	Node* cur=*head;

	while(m2!=m && cur)
	{
		cur=cur->next;
		m2++;
	}

	if(!cur)
		return;

	while(n2!=n)
	{
		Node* temp=cur->next;
		cur->next=temp->next;
		free(temp);
		n2++;
	}
}

//swap pairwise nodes by changing links
void swapPairByLink(Node** head)
{
	Node* prev=(*head);
	Node* cur=prev->next;

	if(!(*head) || !((*head)->next))
		return;

	*head=cur;

	while(true)
	{
		Node* nex=cur->next;
		cur->next=prev;

		if(!nex || !nex->next)
		{
			prev->next=nex;
			break;
		}


		prev->next=nex->next;

		prev=nex;
		cur=prev->next;
	}
}


// a linked list of line segments, remove middle points
void removeMiddle(line* start)
{
	line* cur=start;
	line* nex=cur->next;
	line* temp;

	while(cur && nex && cur->y == nex->y && nex->y == nex->next->y)
	{
		temp=cur->next;
		cur->next=temp->next;
		delete temp;
		nex=cur->next;
		
	}

	
    	temp=nex->next;
    	cur=temp->next;
    	
    	nex=cur->next;
    	
        delete temp;


   

    cout<<cur->x<<cur->y<<endl;
    cout<<nex->next->x<<nex->next->y<<endl;

	while(cur && nex && cur->y == nex->y && nex->y == nex->next->y)
	{
		temp=cur->next;
		cur->next=temp->next;
		delete temp;
		nex=cur->next;
		
	}
}
//insert at the beginning of the linked list having two data points
void push(line** start, int p, int q)
{
	line* newnode=new line;
	newnode->x=p;
	newnode->y=q;
	newnode->next=(*start);
	*start=newnode;
}
//print data points of linked list
void printTwo(line* start)
{
	while(start)
	{
		cout<<"("<<start->x<<", "<<start->y<<")"<<endl;
		start=start->next;
	}
}


int main()
{
	Node* head1=NULL;
	Node* head2=NULL;
	Node* head3=NULL;
	Node* head4=NULL;

	/*insert_beg(&head1,20);
	insert_beg(&head1,4);
	insert_beg(&head1,15);
	insert_beg(&head1,10);
	
    print(head1);

    insert_beg(&head2,1);
    insert_beg(&head2,9);
    insert_beg(&head2,9);
    insert_beg(&head2,9);

    print(head2);*/

   /* insert_beg(&head3,0);
    insert_beg(&head3,1);
    insert_beg(&head3,10);
    insert_beg(&head3,21);
    insert_beg(&head3,12);
    insert_beg(&head3,14);
    insert_beg(&head3,22);
    insert_beg(&head3,15);
    insert_beg(&head3,20);
    insert_beg(&head3,30);



    print(head3);*/

    //isSumInTriplet(head1,head2,head3,25);

    //rotate_anticlock(&head1,3);
    //print(head1);

    //addList(head2,head3,&head4);
    //print(head4);

    //sort_012(&head3);

    //deleteNafterM(&head3, 2, 1);

    //swapPairByLink(&head3);
    //print(head3);

    line* start=NULL;

    push(&start, 40,5);
    push(&start, 20,5);
    push(&start, 10,5);
    push(&start, 10,8);
    push(&start, 10,10);
    push(&start, 3,10);
    push(&start, 1,10);
    push(&start, 0,10);

    printTwo(start);

    removeMiddle(start);
    cout<<"After removing middle point in the line segment"<<endl;
    printTwo(start);

	return 0;
}