#include <iostream>
#include <cstdlib>
#include <climits>
#include <string>

using namespace std;

//structure for stack
typedef struct satck
{
	int capacity;
	int top;
	char* array;
}Stack;

//create a stack
Stack* createStack(int capacity)
{
	Stack* st=(Stack*)malloc(sizeof(Stack));
	st->capacity=capacity;
	st->top=-1;
	st->array=(char*)malloc(sizeof(capacity*sizeof(char)));

	return st;
}

//check stack is empty or not
int isEmpty(Stack* st)
{
	return (st->top==-1);
}

//check satck is full or not
int isFull(Stack* st)
{
	return (st->top==st->capacity-1);
}

//push an item in stack
void push(Stack* st, char item)
{
	if(isFull(st))
	{
		//cout<<"OverFlow"<<endl;
	}
	else
	{
		st->array[++st->top]=item;
		//cout<<"Pushed item is "<<item<<endl;
	}
}

//pop an item in stack
void pop(Stack* st)
{
	if(isEmpty(st))
	{
		//cout<<"Underflow"<<endl;
	}
	else
	{
		//cout<<"Poped item is "<<st->array[st->top];
		st->array[st->top--];
	}
}

//get top item of the stack
char getTop(Stack* st)
{
	if(isEmpty(st))
	{
		//cout<<"Underflow"<<endl;
		return '0';
	}
	else
	{
		return st->array[st->top];
	}
}

//set precedence order of operator
int getPrecedence(char op)
{
	switch(op)
	{
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '^': return 3;
	}

	return -1;
}

//main driver function
int main()
{
	string s;
	cin>>s;

	int capacity=s.length();
	//cout<<capacity<<endl;

	Stack* st=createStack(capacity);

	for(int i=0;i<capacity;i++)
	{
		if(isalnum(s[i]))
		{
			cout<<s[i];
		}
		else
		{
			if(s[i]=='(')
			{
				push(st,s[i]);
			}

			else if(s[i]==')')
			{
				while(!isEmpty(st) && getTop(st)!='(')
				{
					//if(getTop(st)!='(')
					cout<<getTop(st);
					pop(st);
				}
				pop(st);
			}


			else 
			{
				if( isEmpty(st) || (getPrecedence(s[i]) >= getPrecedence(getTop(st)))   )
					push(st,s[i]);

				else
				{
					while(!isEmpty(st) && (getPrecedence(s[i]) <= getPrecedence(getTop(st))))
					{
						cout<<getTop(st);
					    pop(st);
					}
					
					push(st,s[i]);
				}
			}
			
		}
	}

	while(!isEmpty(st) && getTop(st)!='(')
	{
		cout<<getTop(st);
		pop(st);
	}

   // cout<<getPrecedence('+')<<endl;
    //cout<<isalnum('+')<<endl;

    /*push(st,'a');
	push(st,'b');
	push(st,'c');
	push(st,'d');
	push(st,'e');
	push(st,'f');
	//pop(st);
	//pop(st);
	//pop(st);
	//pop(st);
	cout<<"Top item is "<<getTop(st)<<endl;
	pop(st);
	pop(st);*/


	return 0;


}