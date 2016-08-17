#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

//structure for stack as node of linked list
typedef struct stackNode
{
	int data;
	struct stackNode* next;
}stack;

//create an new node of stack
stack* newNode(int item)
{
	stack* st=(stack*)malloc(sizeof(stack));
	st->data=item;
	st->next=NULL;

	return st;
}

//check stack is empty or not
int isEmpty(stack* head)
{
	return (head==NULL);
}

//push an item to stack
void push(stack** head, int item)
{
	stack* st=newNode(item);
	st->next=(*head);
	*head=st;

	cout<<"Pushed item is "<<item<<endl;
}

//pop an item from the stack
void pop(stack** head)
{
	if(isEmpty(*head))
		cout<<"Underflow"<<endl;
	else
	{
		stack* temp=(*head);
		(*head)=temp->next;
		cout<<"Poped item is "<<temp->data<<endl;
		free(temp);
	}
}


//get the top item from the stack
int getTop(stack* head)
{
	if(isEmpty(head))
	{
		cout<<"Underflow"<<endl;
		return INT_MIN;
	}
	else
		return head->data;
}


//main driver function
int main()
{
	stack* head=NULL;
	push(&head,10);
	push(&head,20);
	push(&head,30);
	cout<<"Top item of the stack is "<<getTop(head)<<endl;
	pop(&head);
	pop(&head);
	pop(&head);
	cout<<"Top item of the stack is "<<getTop(head)<<endl;
	pop(&head);

	return 0;
}