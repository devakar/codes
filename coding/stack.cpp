#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

typedef struct stack
{
	unsigned capacity;
	int top;
	int* array;
}STACK;


//create an empty stack
STACK* create_stack(unsigned capacity)
{
	STACK* st=(STACK*)malloc(sizeof(STACK));
	st->capacity=capacity;
	st->top=-1;
	st->array=(int*)malloc(sizeof(capacity*sizeof(int)));
	return st;
}

//check stack is emty or not
int isEmpty(STACK* st)
{
	return (st->top==-1);
}

//check stack is full or not
int isFull(STACK* st)
{
	return (st->top==st->capacity-1);
}

//push an item in the stack
void push(STACK* st,int item)
{
	if(isFull(st))
		cout<<"Overflow"<<endl;
	else
	{
		st->array[++st->top]=item;
		cout<<"Pushed item is "<<item<<endl;
	}

}

//pop an item from stack
void pop(STACK* st)
{
	if(isEmpty(st))
		cout<<"Underflow"<<endl;
	else
	{
		cout<<"Poped item is "<<st->array[st->top]<<endl;
		st->array[st->top--];
	}
}

//get the top item from stack
int getTop(STACK* st)
{
	if(isEmpty(st))
	{
		cout<<"Underflow"<<endl;
		return INT_MIN;
	}
	else
		return st->array[st->top];
}

//main driver function
int main()
{
	unsigned capacity;
	cin>>capacity;
	STACK* st=create_stack(capacity);
	push(st,10);
	push(st,20);
	push(st,30);
	push(st,40);
	push(st,50);
	push(st,60);
	pop(st);
	pop(st);
	pop(st);
	pop(st);
	cout<<"Top item is "<<getTop(st)<<endl;
	pop(st);
	pop(st);

	return 0;
}