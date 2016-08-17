#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "stdlib.h"

using namespace std;


void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void selection(int a[], int n)
{
	int min_index;

	for(int i=0;i<n-1;i++)
	{
		min_index=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min_index])
				min_index=j;
		}
		swap(&a[i],&a[min_index]);
	}
}

void bubble(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
				swap(&a[j],&a[j+1]);
		}
	}
}

//insertion sort
void insertion(int a[],int n)
{
	int j,key;

	for(int i=1;i<n;i++)
	{
		j=i-1;
		key=a[i];

		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;

		}
		a[j+1]=key;
	}
}

//insertion sort using binary search
int binarySearch(int a[],int x,int l,int r)
{
	if(r<=l)
		return (a[l]>x)? l : l+1;

	int mid=l + (r-l)/2;

	if(x==a[mid])
		return mid+1;

	if(x > a[mid])
		return binarySearch(a,x,mid+1,r);

	return binarySearch(a,x,0,mid-1);
}


void insertionByBinary(int a[],int n)
{
	int j,key,loc;
	for(int i=1;i<n;i++)
	{
		j=i-1;
		key=a[i];

		loc=binarySearch(a,key,0,j);

		while(j>=loc)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}

void merge(int a[],int l,int m,int r)
{
	int n1,n2,p=0,q=0,k=l;
	n1=m-l+1;
	n2=r-m;

	int b[n1],c[n2];

	for(int i=0;i<n1;i++)
		b[i]=a[i+l];

	for(int j=0;j<n2;j++)
		c[j]=a[m+1+j];

	while(p<n1 && q<n2)
	{
		if(b[p]<c[q])
		{
			a[k]=b[p];
			p++;
		}
		else
		{
			a[k]=c[q];
			q++;
		}
		k++;
	}

	while(p<n1)
	{
		a[k]=b[p];
		p++;
		k++;
	}
cdcdcd
	while(q<n2)
	{
		a[k]=c[q];
		q++;
		k++;
	}
}

void mergesort(int a[],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}

}


//quick sort
int partition(int a[],int l,int r)
{
	int x=a[r];
	int i=l-1;

	for(int j=l;j<r;j++)
	{
		if(a[j]<=x)
		{
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[r]);

	return (i+1);

}

void quickSort(int a[],int l,int r)
{
	if(l<r)
	{
		int p=partition(a,l,r);
		quickSort(a,l,p-1);
		quickSort(a,p+1,r);
	}
}


void quickSortIter(int a[],int l,int r)
{
	int stack[r-l+1];
	int top=-1;

	stack[++top]=l;
	stack[++top]=r;

	while(top>=0)
	{
		r=stack[top--];
		l=stack[top--];
		int p=partition(a,l,r);

		if(l<p-1)
		{
			stack[++top]=l;
			stack[++top]=p-1;
		}

		if(r>p+1)
		{
			stack[++top]=p+1;
			stack[++top]=r;
		}
	}
}





//HEap sort
struct heap
{
	int size;
	int *array;
};

void heapify(struct heap *maxHeap, int index)
{
	int largest=index;
	int left=(index<<1)+1;     // 2*index+1
	int right=(index+1)<<1;    // 2*index+2

	if(left<maxHeap->size && maxHeap->array[left]>maxHeap->array[largest])
	{
		largest=left;
	}

	if(right<maxHeap->size && maxHeap->array[right]>maxHeap->array[largest])
	{
		largest=right;
	}

	if(largest!=index)
	{
		swap(&maxHeap->array[largest], &maxHeap->array[index]);
		heapify(maxHeap,largest);
	}
}

struct heap* bulidHeap(int a[],int n)
{
	struct heap *maxHeap=(struct heap*)malloc(sizeof(struct heap));
	maxHeap->array=a;
	maxHeap->size=n;

	for(int i=(maxHeap->size-2)/2 ;i>=0;i--)
	{
		heapify(maxHeap,i);
	}

	return maxHeap;
}


void heapSort(int a[],int n)
{
	struct heap *maxHeap= bulidHeap(a,n);

	while(maxHeap->size>1)
	{
		swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size-1]);
		maxHeap->size--;
		heapify(maxHeap,0);
	}
}


void bucketSort(float a[],int n)
{
	vector <float> b[n];

    for(int i=0;i<n;i++)
    {
    	int p=n*a[i];
    	b[p].push_back(a[i]);
    }

    for(int i=0;i<n;i++)
    {
    	sort(b[i].begin(),b[i].end());
    }
    
    int index=0;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<b[i].size();j++)
    		a[index++]=b[i][j];
    }

}


void countSort(int a[],int n,int k)
{
	int c[k];
	int b[n];
	for(int i=0;i<k;i++)
		c[i]=0;

	for(int i=0;i<n;i++)
		c[a[i]]++;

    for(int i=1;i<k;i++)
    	c[i]+=c[i-1];


	for(int i=n-1;i>=0;i--)
	{
		b[c[a[i]]-1]=a[i];
		c[a[i]]--;
	}
	
	for(int i=0;i<n;i++)
	    cout<<b[i]<<" ";	

}

//Minimum length Unsorted Subarray, sorting which makes the complete array sorted
void printUnsorted(int a[],int n)
{
	int l,r,min=10000,max=-1,i,j,p,q,s,e;
	for(i=0; i<n-1; i++)
	{
		if(a[i]>a[i+1])
			break;
	}

	for(j=n-1;j>0;j--)
	{
		if(a[j]<a[j-1])
			break;
	}

	
     
     s=i;
     e=j;

	for(int k=i;k<=j;k++)
	{
		if(a[k]>max)
			max=a[k];
		if(a[k]<min)
			min=a[k];
	}
   
	for(p=i-1; p<=0; p--)
	{
		if(a[p]>min)
			s=p;
		

	}

	for(q=j+1; q<n; q++)
	{
		if(a[q]<max)
			e=q;
	}

	cout<<"start index is :"<<s<<endl;
	cout<<"end index is :"<<e<<endl;
}


//to Find k closest elements to a given value
//function to get cross over point
int crossOver(int a[],int l,int r,int x)
{
	if(a[l]>x)
		return l;

	if(a[r]<x)
		return r;

	int mid=l+(r-l)/2;

	
	if(a[mid]<=x && a[mid+1]>x)
		return mid;

	if(a[mid]<x)
		return crossOver(a,mid+1,r,x);

	return crossOver(a,l,mid-1,x);

}

//function to print k closest element to the given value
void kClosest(int a[],int x,int k,int n)
{
	int i=crossOver(a,0,n-1,x);
	int j=i+1;

	if(a[i]==x)
		i--;

	int c=0;

	while(i>=0 && j<n && c<k)
	{
		if((a[j]-x)<(x-a[i]))
		{
			cout<<a[j]<<"\t";
			c++;
			j++;
		}

		else
		{
			cout<<a[i]<<"\t";
			c++;
			i--;
		}
	}

	while(i>=0 && c<k)
	{
		cout<<a[i]<<"\t";
			c++;
			i--;
	}

	while(j<n && c<k)
	{
		cout<<a[j]<<"\t";
			c++;
			j++;

	}

}



//function to Sort n numbers in range from 0 to n^2 – 1 in linear time
//modification of count sort
void modCountSort(int a[], int n, int e)
{
	int c[n],final[n];
	for(int i=0;i<n;i++)
		c[i]=0;

	for(int i=0;i<n;i++)
	{
		c[(a[i]/e) % n]++;
	}

	for(int i=1; i<n;i++)
		c[i]+=c[i-1];

	//for(int i=0;i<n;i++)
	//	cout<<c[i];

	for(int i=n-1; i>=0; i--)
	{
		final[c[(a[i]/e)%n]-1]=a[i];
		c[(a[i]/e)%n]--;
	}

	for(int i=0;i<n;i++)
		a[i]=final[i];

   
     
}

//function which calls the modified count sort to sort n numbers in range from 0 to n^2-1 in linear time
void sortInRange(int a[],int n)
{
	modCountSort(a,n,1);
	modCountSort(a,n,n);
	
}


//search in almosted sorted array
int searchInAlmostSorted(int a[], int l, int r, int key)
{
	if(r>=l)
	{
		int mid=l+(r-l)/2;

	if(key==a[mid])
		return mid;

	if(key==a[mid-1])
		return mid-1;

	if(key==a[mid+1])
		return mid+1;

	if(key<a[mid])
		return searchInAlmostSorted(a,l,mid-2,key);

	
	return searchInAlmostSorted(a,mid+2,r,key);
	}
	

	return -1;
}



void sortInWave(int a[],int n)
{
	sort(a,a+n);
	int i=0;
	while(i<n)
	{
		swap(&a[i],&a[i+1]);
		i+=2;
	}


    for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}

void closestPair(int a[],int b[],int k,int n,int m)
{
	int mindif=INT_MAX;
	int l=0,rl,rr;
	int r=m-1;

	while(l<n && r>=0)
	{
		if(abs(a[l]+b[r]-k)<mindif)
		{
			rl=l;
			rr=r;
			mindif=abs(a[l]+b[r]-k);
			
		}
			

		if(a[l]+b[r]<k)
			l++;
		else
			r--;
	}

	cout<<"The closest pair is "<<a[rl]<<" and "<<b[rr]<<endl;
}

void commonInThree(int a[],int b[],int c[],int p,int q,int r)
{
	int x=0,y=0,z=0;


    cout<<"the common element among the three arrays are: "<<endl;
	while(x<p && y<q &&z<r)
	{
		if(a[x]==b[y] && b[y]==c[z])
		{
			cout<<a[x]<<endl;
			x++;
			y++;
			z++;
		}

		else if(a[x]<b[y])
			x++;
		else if(b[y]<c[z])
			y++;
		else
			z++;
	}
}


//sum of two elements of one array which is closest to a given sum
closestInOne(int a[],int l,int r,int sum)
{
	int mindif=INT_MAX;
	int i,j;
	while(l<r)
	{
		if(abs(a[l]+a[r]-sum)<mindif)
		{
			i=l;
			j=r;
			mindif=abs(a[l]+a[r]-sum);
		}
        if(a[l]+a[r]<sum)
        	l++;
        else
        	r--;

	}

	cout<<"The pair closest to the sum is: "<<a[i]<<" and "<<a[j]<<endl;
}
//count number of 1 in an array which is sorted in decreasing order
void count_1(int a[],int l,int r)
{
	if(l<r)
	{
		int mid=l+(r-l)/2;

		if(mid==r || (a[mid]==1 && a[mid+1]==0))
		{
			cout<<"The number of 1's in the array is: "<<mid+1<<endl;
			return;
		}

		if(a[mid]==1)
			count_1(a,mid+1,r);

		count_1(a,l,mid-1);

	}
}



//quick sort for doubly linked list
struct dnode
{
	int data;
	struct dnode *prev;
    struct dnode *next;
};

struct dnode* insert_beg(struct dnode **head,int item)
{
	struct dnode* newnode=(struct dnode*)malloc(sizeof(struct dnode));
	newnode->data=item;
	newnode->prev=NULL;
    if(*head==NULL)
    {
    	newnode->next=NULL;
    	
    }
    else
    {
    	struct dnode* temp=*head;
        newnode->next=temp;
        temp->prev=newnode;

    }
    

    *head=newnode;

}


struct dnode* lastnode(struct dnode* head)
{
	struct dnode *temp=head;
	while(temp->next)
		temp=temp->next;

	
	return temp;
}

struct dnode* partitionList(struct dnode* head, struct dnode* last)
{
	int key=last->data;
	struct dnode* i=head->prev;
	struct dnode* j;

	for(j=head;j!=last;j=j->next)
	{
		if(j->data <= key)
		{
			i= (i==NULL) ? head : i->next;
			swap(i->data, j->data);
		}
	}
	i= (i==NULL) ? head : i->next;
	swap(i->data, last->data);
    return i;
}

void _quickSortDLL(struct dnode* head, struct dnode* last)
{
	if(head && head!=last && head!=last->next)
	{
		struct dnode* p=partitionList(head,last);
		_quickSortDLL(head,p->prev);
		_quickSortDLL(p->next,last);
	}
}

struct dnode* quickSortDoubleLL(struct dnode* head)
{
	struct dnode* last=lastnode(head);

	_quickSortDLL(head,last);
}


void print(struct dnode *head)
{
	struct dnode* temp=head;
	while(temp)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
		
}


//quick sort on single linked list by changing the links
struct node
{
	int data;
	struct node* next;

};

struct node* insert_end(struct node** head, int item)
{
	struct node* temp=*head;
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=item;
	newnode->next=NULL;

	if(*head==NULL)
	{
		*head=newnode;
		return *head;
	}

	while(temp->next)
		temp=temp->next;

	temp->next=newnode;
	return *head;
}

struct node* getTail(struct node* head)
{
	struct node* temp=head;
	while(temp && temp->next)
		temp=temp->next;

	return temp;
}

struct node* partitionSList(struct node* head, struct node* tail, struct node** newhead, struct node** newtail)
{
	struct node* pivot=tail;
	struct node* prev=NULL;
	struct node* cur=head;
	struct node* end=tail;


	while(cur!=pivot)
	{
		if(cur->data < pivot->data)
		{
			if(*newhead==NULL)
				*newhead=cur;
			prev=cur;
			cur=cur->next;
		}
		else
		{   if (prev)
                prev->next=cur->next;
            struct node* temp=cur->next;
			cur->next=NULL;
			end->next=cur;
			end=end->next;
			cur=temp;
			
		}
	}

	if(*newhead==NULL)
		*newhead=pivot;

	*newtail=end;

	return pivot;
}

struct node* _quickSortSLL(struct node* head, struct node* tail)
{
	if(!head || head==tail)
		return head;

	
	struct node* prev=NULL;
	struct node* newhead=NULL;
	struct node* newtail=NULL;
	struct node* pivot=partitionSList(head,tail,&newhead,&newtail);

	if(newhead!=pivot)
	{
		struct node* temp=newhead;
		while(temp->next!=pivot)
		{
			//prev=temp;
			temp=temp->next;
		}
		//prev->next=NULL;
		temp->next=NULL;
		newhead=_quickSortSLL(newhead,temp);

		temp=getTail(newhead);
		temp->next=pivot;
			
	}

	pivot->next = _quickSortSLL(pivot->next, newtail);
 
    return newhead;
}

void quickSortSLL(struct node **headRef)
{
    (*headRef) = _quickSortSLL(*headRef, getTail(*headRef));
    return;
}

void print(struct node *head)
{
	struct node* temp=head;
	while(temp)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
		
}





int main()
{
	struct dnode* head=NULL;
    insert_beg(&head,8);
    insert_beg(&head,2);
    insert_beg(&head,7);
    insert_beg(&head,1);
    insert_beg(&head,3);
    insert_beg(&head,5);
    insert_beg(&head,4);

    print(head);
    cout<<endl;

    quickSortDoubleLL(head);
    print(head);
    cout<<endl;


    struct node* head2=NULL;
    insert_end(&head2,8);
    insert_end(&head2,2);
    insert_end(&head2,7);
    insert_end(&head2,1);
    insert_end(&head2,3);
    insert_end(&head2,5);
    insert_end(&head2,4);

    print(head2);
    cout<<endl;
    quickSortSLL(&head2);
    print(head2);
    cout<<endl;

	//int n;
	//cin>>n;
	//int a[n],b[n],c[n],d[n],e[n],f[n];
	//int h[]={10,12,20,30,25,40,32,31,35,50,60};
	//float g[n];
	
	/*for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}*/

	/*for(int i=0;i<n;i++)
	{
		b[i]=c[i]=d[i]=e[i]=f[i]=a[i];
	}

	

	selection(a,n);
	bubble(b,n);
	insertion(c,n);
	mergesort(d,0,n-1);
	quickSort(e,0,n-1);
	heapSort(f,n);

	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}

	cout<<endl;

	for(int i=0;i<n;i++)
	{
		cout<<b[i]<<"\t";
	}
   
    cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<c[i]<<"\t";
	}

	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<d[i]<<"\t";
	}

	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<e[i]<<"\t";
	}


	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<f[i]<<"\t";
	}
    */


   /*for(int i=0;i<n;i++)
	{
		cin>>g[i];
	}
   
   bucketSort(g,n);

   for(int i=0;i<n;i++)
	{
		cout<<g[i]<<"\t";
	}*/


  
   
   //printUnsorted(h,11);
   cout<<endl;
   //countSort(a,n,10);

   /*quickSortIter(a,0,n-1);

   for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}*/




	//int arr[] ={12, 16, 22, 30, 35, 39, 42,45, 48, 50, 53, 55, 56};
	//kClosest(arr,35,4,13);

   /* int arr[]={40, 12, 45, 32, 33, 1, 22};
    sortInRange(arr,7);
    cout<<endl;
    cout<<arr[0]<<" ";
    cout<<arr[1]<<" ";
    cout<<arr[2]<<" ";
    cout<<arr[3]<<" ";
    cout<<arr[4]<<" ";
    cout<<arr[5]<<" ";
    cout<<arr[6]<<endl;*/
    
    
   // int s[] =  {10, 3, 40, 20, 50, 80, 70};
    //cout<<searchInAlmostSorted(s,0,6,90)<<endl;
 
    //sortInWave(s,7);

    //int ar1[] = {10, 28, 26, 9, 30, 15,20};
    //int ar2[] = {6, 7, 20, 30, 80, 100};
    //int ar3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    //int na=(sizeof(ar1)/sizeof(ar1[0]));
	//int nb=(sizeof(ar2)/sizeof(ar2[0]));
	//int nc=(sizeof(ar3)/sizeof(ar3[0]));

    //closestPair(ar1,ar2,38,na,nb);
    //commonInThree(ar1,ar2,ar3,na,nb,nc);
    //closestInOne(ar1,0,na-1,54);

   /* int arr[] = {1, 1, 1, 1, 0, 0, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    count_1(arr,0,n-1);*/

    /*insertionByBinary(ar1,na);
    for(int i=0;i<na;i++)
    	cout<<ar1[i]<<"\t";*/

    


return 0;
}