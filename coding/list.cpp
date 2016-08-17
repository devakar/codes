#include <iostream>
#include "stdlib.h"
using namespace std;

struct node
{
	int data;
	struct node *next;
};

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

//insert the node at begining of the linked list
void insert_beg(struct node **head,int item)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->next=(*head);
	(*head)=temp;  
}

//insert the node at the end of linked list
void insert_end(struct node **head,int item)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	struct node *last=(*head);
	temp->data=item;
	temp->next=NULL;
	
	if(*head==NULL)
	  {
	   (*head)=temp;
	   return;
	  }
	   
	while(last->next!=NULL)
	{
		last=last->next;
	}
	last->next=temp;
}

//insert the node after a given node
void insert_node(struct node *node,int item)
{
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  temp->data=item;
  temp->next=node->next;
  node->next=temp;
}

//get nth node in list
int getNth(struct node *head,int index)
{
	struct node *temp=head;
	int count=0;
	while(temp!=NULL)
	{
		if(count==index)
		return (temp->data);
		
		count++;
		temp=temp->next;
	}
}

//delete a node ,only pointer to that node is given ,head pointer is not given
void del_point(struct node *pointer)
{
	struct node *temp=pointer;
	temp->data=temp->next->data;
    temp=temp->next;
    pointer->next=temp->next;
    free(temp);
}


//get the middle element of the linked list
int middle(struct node *head)
{
	struct node *slow=head;
	struct node *fast=head;

	if(head!=NULL)
	{

	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}

	return slow->data;
	}
}

//get nth node from last
int nFromLast(struct node *head, int n)
{
	struct node *fast=head;
	struct node *slow=head;
	int c=0;

	if(head!=NULL)
	{
		while(c<n)
		{
			if(fast==NULL)
			{
				cout<<"n is more than the length of linked list"<<endl;
				return -1;
			}
			fast=fast->next;
			c++;
		}

	}

	while(fast!=NULL)
	{
		fast=fast->next;
		slow=slow->next;
	}
	return slow->data;
}

//delete the linked list
void deleteList(struct node **head)
{
	struct node *temp1=*head;
	struct node *temp2;

	if(head!=NULL)
	{
		while(temp1!=NULL)
		{
			temp2=temp1->next;
			free(temp1);
			temp1=temp2;
		}
	}
	*head=NULL;
}


//count occurences of an element
int countOccur(struct node *head, int item)
{
	struct node *temp=head;
	int ocur=0;
	if(head!=NULL)
	{
		while(temp!=NULL)
		{
			if(temp->data==item)
				ocur++;

			temp=temp->next;
		}
	}
	return ocur;
}


//reverse the linked list without using using recursion
void reverse(struct node **head)
{
	struct node *prev=NULL;
	struct node *curr=*head;
	struct node *suc;

	while(curr!=NULL)
	{
		suc=curr->next;
		curr->next=prev;
		prev=curr;
		curr=suc;
    }
    *head=prev;
}

//reverse the linked list using recursion
void recReverse(struct node **head)
{
	struct node *first=*head;
	struct node *rest=first->next;

	if(rest==NULL)
		return;
	recReverse(&rest);
	first->next->next=first;
	first->next=NULL;
	*head=rest;
}

//function to detect loop in linked list
int detectLoop(struct node *head)
{
	struct node *slow=head;
	struct node *fast=head;

	while(slow && fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;

		if(slow==fast)
		{
			cout<<"Loop exists"<<endl;
			return 1;
		}
	}

	return 0;
}


//function to detect and remove loop from the linked list



void removeLoop(struct node *head, struct node *loopNode)
{
	struct node *cur=head;
	struct node *temp1=loopNode;
	struct node *temp2=loopNode;

	unsigned int k=1;

	while(temp1->next!=temp2)
	{
		temp1=temp1->next;
		k++;
	}

	for(int i=0;i<k;i++)
	{
		cur=cur->next;
	}
    
    temp2=head;

	while(cur!=temp2)
	{
		cur=cur->next;
		temp2=temp2->next;
	}

	cur=cur->next;

	while(cur->next!=temp2)
	{
		cur=cur->next;
	}

	cur->next=NULL;


}


void detectAndRemoveLoop(struct node *head)
{
	struct node *slow=head;
	struct node *fast=head;

	while(slow && fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;

		if(slow==fast)
		{
			removeLoop(head,slow);
			
		}
	}

}

//a rcursive function which is used to check linked list is palindrome or not
bool palindromeUtil(struct node **left,struct node *right)
{
	if(right==NULL)
		return true;

	bool p=palindromeUtil(left,right->next);
	if(p==false)
		return false;

	bool p2=((*left)->data==right->data);

	*left=(*left)->next;
	return p2;
}

//function to check linked list is palindrome or not
bool isPalindrome(struct node *head)
{
	return palindromeUtil(&head,head);
}

//insert an element in sorted linked list
void insertSorted(struct node **head, int item)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;

	struct node *cur=(*head);

	if(*head==NULL || (*head)->data>=item)
	{
		temp->next=(*head);
		(*head)=temp;
    
	}
	else
	{
		while(cur->next!=NULL && item > (cur->next)->data)
			cur=cur->next;
        
        temp->next=cur->next;
        cur->next=temp;

	}
}

int lengthOfList(struct node *head)
{
	struct node *temp=head;
	int n=0;
	while(temp!=NULL)
	{
		temp=temp->next;
		n++;
	}
	return n;
}

int getIntersectNode(struct node *head1, struct node *head2,int d)
{
	struct node *temp1=head1;
	struct node *temp2=head2;

	for(int i=0;i<d;i++)
		temp1=temp1->next;

	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->data==temp2->data)
			return temp1->data;
		temp1=temp1->next;
		temp2=temp2->next;
	}
	return -1;

}

//intersection of two linked list
int intersectNode(struct node *head1, struct node *head2)
{
	int n1=lengthOfList(head1);
	int n2=lengthOfList(head2);
	int d=(n1 > n2)?(n1-n2):(n2-n1);


	if(n1>n2)
	{
		return getIntersectNode(head1,head2,d);
	}
	else
	   return getIntersectNode(head2,head1,d); 

}

//print reverse of the linked list
void reversePrint(struct node *head)
{
	if(head==NULL)
		return;
	else
	{
		reversePrint(head->next);
		cout<<head->data<<"\t";
	}
}


//remove thr duplicates from sorted linked list.
void deleteDuplicate(struct node *head)
{
	struct node *temp;
	struct node *cur=head;
    
    if(cur==NULL)
    	return;

    while(cur->next!=NULL)
    {
    	if(cur->data==cur->next->data)
    	{
    		temp=cur->next;
    		cur->next=temp->next;
    		free(temp);
    	}
    	else
    		cur=cur->next;
    }


}


//remove duplicates from unsorted linked list
void deleteDuplicateUnsorted(struct node *head)
{
	struct node *temp;
	struct node *cur1=head;
	struct node *cur2=head;

	while(cur1!=NULL && cur1->next!=NULL)
	{
		cur2=cur1;
		

		while(cur2->next!=NULL)
		{
          if(cur1->data==cur2->next->data)
          {
          	temp=cur2->next;
          	cur2->next=temp->next;
          	free(temp);
          }
          else
          	cur2=cur2->next;
		}
		
		cur1=cur1->next;

	}
}


//iteratively swap pairwise element of linked list
void swapPairIter(struct node* head)
{
	struct node *temp=head;
	while(temp!=NULL && temp->next!=NULL)
	{
		swap(&(temp->data),&(temp->next->data));

		temp=temp->next->next;
	}
}

//recursively swap pairwise elements of the linked list
void swapPairRec(struct node *head)
{
	if(head!=NULL && head->next!=NULL)
	{
		swap(&(head->data),&(head->next->data));
		swapPairRec(head->next->next);
	}
	
}

//move the last element to first in the linked list
void moveLastToFirst(struct node **head)
{
	struct node *temp=*head;
	while(temp->next!=NULL)
		temp=temp->next;

	swap(&((*head)->data),&(temp->data));
}


//recursive function to get a list which is intersection of two lists
struct node *sortedIntersection(struct node *a, struct node *b)
{
	if(a==NULL || b==NULL)
		return NULL;

	if(a->data > b->data)
		return sortedIntersection(a,b->next);

	if(a->data < b->data)
		return sortedIntersection(a->next,b);

	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=a->data;

	temp->next = sortedIntersection(a->next, b->next);
	return temp;
}


//non-recursive function to get a list which is intersection of two lists
struct node *NrSortedIntersection(struct node *a, struct node *b)
{
	struct node *c=NULL;
	
	while(a!=NULL && b!=NULL)
	{
		if(a->data == b->data)
		{
			insert_end(&c,a->data);

			a=a->next;
			b-b->next;
		}
		if(a->data < b->data)
			a=a->next;
		if(a->next > b->next)
			b=b->next;
	}

	return c;
}

//iterative functio to delete alternate nodes in linked list
void delAlt(struct node *head)
{
	struct node *prev=head;
	struct node *cur;

	while(prev!=NULL && prev->next != NULL)
	{
		cur=prev->next;
		prev->next=cur->next;
		free(cur);
		prev=prev->next;

	}


}


//recursive function to delete alternate nodes in linked list
void recDelAlt(struct node *head)
{
	if(head==NULL)
		return;
	if(head->next==NULL)
		return;

	struct node *temp=head->next;
	head->next=temp->next;
	free(temp);
	recDelAlt(head->next);

}

//alternative split the linked list
void altSplit(struct node *head, struct node **a, struct node **b)
{
	struct node *cur=head;
	
	while(cur)
	{
		insert_end(a,cur->data);
		cur=cur->next;
		if(cur)
		{
			insert_end(b,cur->data);
		    cur=cur->next;
		}
		
	}
}

//merge two sorted linked list
void mergeSorted(struct node *a, struct node *b, struct node **c)
{
	struct node *acur=a;
	struct node *bcur=b;

	while(acur && bcur)
	{
		if(acur->data < bcur->data)
		{
			insert_end(c,acur->data);
			acur=acur->next;
		}
		else
		{
			insert_end(c,bcur->data);
			bcur=bcur->next;
		}
	}

	while(acur)
	{
		insert_end(c,acur->data);
			acur=acur->next;

	}

	while(bcur)
	{
		insert_end(c,bcur->data);
			bcur=bcur->next;
	}
}


//check whether two link list are identical or not
bool isIdentical(struct node *a, struct node *b)
{
	if(!a && !b)
		return true;
	if(a && !b)
		return false;
    if(!a && b)
    	return false;
    if(a->data != b->data)
    	return false;

    return isIdentical(a->next,b->next);
}


//split function to be used in mergesort
void split(struct node *head,struct node **left,struct node **right)
{
	struct node *slow;
	struct node *fast;

	if(!head || !(head->next))
	{
		*left=head;
		*right=NULL;
	}
	else
	{
		slow=head;
		fast=slow->next;

		while(fast)
		{
			fast=fast->next;
			if(fast)
			{
				slow=slow->next;
				fast=fast->next;
			}
		}
		*left=head;
		*right=slow->next;
		slow->next=NULL;

	}


}


//merge sorted linked list 
struct node *sortedMerge(struct node *a,struct node *b)
{
	struct node *c=NULL;

	if(!a)
		return b;
	if(!b)
		return a;
	if(a->data <= b->data)
	{
		c=a;
		c->next=sortedMerge(a->next,b);
	}
	else
	{
		c=b;
		b->next=sortedMerge(a,b->next);
	}

	return c;

}


//merge sort in linked list
void mergeSort(struct node **head)
{
	struct node *cur=*head;
	struct node *left=NULL;
	struct node *right=NULL;

	if(!(*head) || !((*head)->next))
		return;

	split(*head,&left,&right);
	mergeSort(&left);
	mergeSort(&right);

	*head=sortedMerge(left,right);
}


//reverse a linked list in a group of size k
struct node *reverseInGroup(struct node *head, int k)
{
	struct node *cur=head;
	struct node *prev=NULL;
	struct node *nex=NULL;
	int count=0;

	while(cur && count<k)
	{
		nex=cur->next;
		cur->next=prev;
		prev=cur;
		cur=nex;
		count++;
	}

	if(nex)
		head->next=reverseInGroup(nex,k);

	return prev;
}

//reverse a linked list in a group of size of k in alternate manner
struct node *reverseAltInGroup(struct node *head, int k)
{ 
	struct node* current = head;
    struct node* next;
    struct node* prev = NULL;
    int count = 0;   
 
    /*1) reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
       next  = current->next;
       current->next = prev;
       prev = current;
       current = next;
       count++;
    }
   
    /* 2) Now head points to the kth node.  So change next 
       of head to (k+1)th node*/
    if(head != NULL)
      head->next = current;   
 
    /* 3) We do not want to reverse next k nodes. So move the current 
        pointer to skip next k nodes */
    count = 0;
    while(count < k-1 && current != NULL )
    {
      current = current->next;
      count++;
    }
 
    /* 4) Recursively call for the list starting from current->next.
       And make rest of the list as next of first node */
    if(current !=  NULL)
       current->next = reverseAltInGroup(current->next, k); 
 
    /* 5) prev is new head of the input list */
    return prev;

}

//delete the nodes which has lesse value than its right node
void deleteLeftLess(struct node **head)
{
	reverse(head);
	struct node *cur=*head;
	struct node *temp;
	int max=cur->data;
	//cur=cur->next;
	while(cur && cur->next)
	{
		if(cur->next->data > max)
		{
			max=cur->next->data;
			cur=cur->next;
		}
			
		else
		{
			temp=cur->next;
			cur->next=temp->next;
			free(temp);

		}

	}

	reverse(head);
}


//segregate between even and odd nodes such that all even nodes comes first and then odd nodes
void segregateEvenOdd(struct node **head)
{
	struct node *cur=(*head);
	struct node *end=(*head);
	struct node *prev;

	while(end->next!=NULL)
		end=end->next;

	struct node *newEnd=end;

	while(cur!=end && (cur->data)%2 != 0)
	{
		newEnd->next=cur;
		cur=cur->next;
		newEnd->next->next=NULL;
		newEnd=newEnd->next;
	}

	

	if(cur->data % 2 == 0)
	{
		*head=cur;
		while(cur!=end)
		{
			if(cur->data % 2 == 0)
			{
				prev=cur;
				cur=cur->next;
			}

			else
			{
				prev->next=cur->next;
				cur->next=NULL;
				newEnd->next=cur;
				newEnd=newEnd->next;
				cur=prev->next;
			}
		}
	}
    
    else
		prev=cur;

    
	if(newEnd!=end && end->data % 2 !=0)
	{
		prev->next = end->next;
        end->next = NULL;
        newEnd->next = end;
	}


}


//delete a node under given constraint
//1) It must accept pointer to the start node as first parameter and node to be deleted as second parameter i.e., pointer to head node is not global.
//2) It should not return pointer to the head node.
//3) It should not accept pointer to pointer to head node.
void deleteUnderConstraint(struct node *head, struct node *nodeToDelete)
{
	struct node *cur=head;

    if(head==nodeToDelete)
    {
    	cur->data=cur->next->data;
    	nodeToDelete=cur->next;
        cur->next=cur->next->next;
        free(nodeToDelete);
        return;
    }

	while(cur->next!=NULL && cur->next!=nodeToDelete)
	{
		cur=cur->next;
	}

	if(cur->next==NULL)
	{
		cout<<"No such node exists "<<endl;
		return;
	}
	cur->next=cur->next->next;
	free(nodeToDelete);
}


//union of two link list
bool isPresent(struct node* a,int item)
{
	struct node* t=a;
	while(t)
	{
		if(item==t->data)
			return true;

		t=t->next;
	}
    return false;
}


struct node* unionOfList(struct node* a,struct node *b)
{
	struct node* c=NULL;
	struct node* temp1=a;
	struct node* temp2=b;

	while(temp1)
	{
		insert_end(&c,temp1->data);
		temp1=temp1->next;
	}
		

	

	while(temp2)
	{
		temp1=a;
		if(isPresent(temp1,temp2->data)==0)
		{
			insert_end(&c,temp2->data);

		}
		
		temp2=temp2->next;

	}
	return c;
}
//union using merge sort
/*struct node* unionByMergesort(struct node* a,struct node* b)
{
	
	mergeSort(&a);
	mergeSort(&b);
	struct node* t1=a;
	struct node* t2=b;
	struct node* c=NULL;

	while(t1 && t2)
	{
		if(t1->data == t2->data)
		{
			insert_end(&c,t1->data);
			t1=t1->next;
			t2=t2->next;
		}

		if(t1->data < t2->data) 
		{
			insert_end(&c,t1->data);
			t1=t1->next;
		}

		if(t1->data > t2->data)
		{
			insert_end(&c,t2->data);
			t2=t2->next;
		}
	}
	return c;
}*/

//intersection of two linked list
struct node* intersectionOfList(struct node* a,struct node* b)
{
	struct node *c=NULL;
	struct node *t1=a;
	struct node *t2=b;

	while(t1)
	{
		t2=b;
		
		if(isPresent(t2,t1->data))
			insert_end(&c,t1->data);
			
		
		t1=t1->next;
	}
	return c;
}

//intersection of two linked list using merge sort
struct node* intersectionByMergesort(struct node* a,struct node* b)
{
	
	mergeSort(&a);
	mergeSort(&b);
	struct node* t1=a;
	struct node* t2=b;
	struct node* c=NULL;

	/*while(t1 && t2)
	{
		if(t1->data == t2->data)
		{
			insert_end(&c,t1->data);
			t1=t1->next;
			t2=t2->next;
		}

		if(t1->data < t2->data) 
		{
			
			t1=t1->next;
		}

		if(t1->data > t2->data)
		{
			
			t2=t2->next;
		}
	}
	return c;*/

	return sortedIntersection(t1,t2);
}

//print the complete linked list
void print(struct node *head)
{
	while(head!=NULL)
	   {
	   	cout<<(head->data)<<"\t";
	   	head=head->next;
	   }
	   cout<<endl;
}



//add two numbers represented by two linked list
void sumList(struct node *head1, struct node *head2)
{
	int sum,carry=0;
	struct node *temp1=head1;
	struct node *temp2=head2;
	struct node *head=NULL;

	while(temp1 && temp2)
	{
		sum=((temp1->data+temp2->data)+carry)%10;
		carry = (temp1->data+temp2->data) /10;

		insert_end(&head,sum);

		temp1=temp1->next;
		temp2=temp2->next;
	}
	while(temp1)
	{
		insert_end(&head,temp1->data+carry);
	}
	while(temp2)
	{
		insert_end(&head,temp2->data+carry);
	}
	if(carry)
		insert_end(&head,carry);

	print(head);
}




int main() {
	/*struct node *head=NULL;
	insert_beg(&head,1);
	insert_beg(&head,2);
	insert_beg(&head,3);
	insert_beg(&head,4);
	insert_beg(&head,5);
	insert_beg(&head,6);
	
	print(head);
	
	cout<<getNth(head,2)<<endl;

	del_point(head->next->next);
	print(head);
    
    
    cout<<middle(head)<<endl;
    cout<<nFromLast(head,3)<<endl;
	
	deleteList(&head);

	insert_beg(&head,7);
	insert_beg(&head,8);
	insert_beg(&head,9);
	insert_beg(&head,8);
	print(head);

	cout<<countOccur(head,8)<<endl;

	reverse(&head);
	print(head);
	recReverse(&head);
	print(head);*/

    struct node *head2=NULL;
	insert_beg(&head2, 2);
    insert_beg(&head2, 4);
    insert_beg(&head2, 5);
    insert_beg(&head2, 1);
    insert_beg(&head2,7);
	insert_beg(&head2,8);
	insert_beg(&head2,9);
	insert_beg(&head2,6);
 
  
    //head2->next->next->next->next->next->next = head2->next->next;
  

	//cout<<detectLoop(head2)<<endl;

	//detectAndRemoveLoop(head2);
	print(head2);

	/*struct node *head3=NULL;
	insert_beg(&head3, 20);
    insert_beg(&head3, 15);
    insert_beg(&head3, 10);
    insert_beg(&head3, 8);
    insert_beg(&head3, 6);
    insert_beg(&head3, 4);
    insert_beg(&head3, 2);
    insert_beg(&head3, 1);
    print(head3);*/

    //isPalindrome(head3)?cout<<"Palindrome"<<endl: cout<<"not Palindrome"<<endl;

    //insertSorted(&head3,9);
    //print(head3);

    struct node*head4=NULL;
   //insert_beg(&head4,1);
    insert_beg(&head4,9);
    insert_beg(&head4,8);
    insert_beg(&head4,7);
    insert_beg(&head4,6);
    insert_beg(&head4,1);
    insert_beg(&head4,4);
    insert_beg(&head4,3);
    insert_beg(&head4,2);
    print(head4);

    //head4->next->next=head3->next->next->next;
    
    //cout<<"intersection of two linked list is "<<intersectNode(head3,head4)<<endl;
	
    //reversePrint(head4);
    cout<<endl;

    //deleteDuplicate(head3);
    //print(head3);

    //deleteDuplicateUnsorted(head4);
    //print(head4);

    //swapPairIter(head3);
    //print(head3);
    //swapPairRec(head4);
    //print(head4);

    //moveLastToFirst(&head4);
    //print(head4);
    
    //struct node *intersect = NULL;
    //intersect=sortedIntersection(head3,head4);
    //print(intersect);

    //struct node *nrintersect=NULL;
    //nrintersect=NrSortedIntersection(head3,head4);
    //print(nrintersect);
    
    //delAlt(head3);
    //print(head3);
    //recDelAlt(head4);
    //print(head4);

    struct node *a=NULL;
    struct node *b=NULL;
    struct node *c=NULL;
    struct node *d=NULL;
    
    //altSplit(head4,&a,&b);
    //print(a);
    //print(b);

    //mergeSorted(a,b,&c);
    //print(c);

    //if(isIdentical(head4,c))
    //	cout<<"Identical"<<endl;
    //else
    //	cout<<"Not Identical"<<endl;
    cout<<endl;
    //mergeSort(&head4);
    //print(head4);
    
    //cout<<endl;
    //head4=reverseInGroup(head4,3);
    //print(head4);

    //cout<<endl;
    
    //head4=reverseAltInGroup(head4,3);
    //print(head4);

    //deleteLeftLess(&head4);
    //print(head4);

    //segregateEvenOdd(&head4);
    //print(head4);

    //sumList(head2,head4);
    //deleteUnderConstraint(head4,head4->next->next);
    //print(head4);
    //cout<<endl;
    //c=unionOfList(head2,head4);
    //print(c);
    cout<<endl;
    //d=intersectionOfList(head2,head4);
    //print(d);
    cout<<endl;

    a=intersectionByMergesort(head2,head4);
    print(a);
    cout<<endl;
    
    
	return 0;
}