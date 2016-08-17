#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef struct tree
{
	int data;
	struct tree *left=NULL;
	struct tree *right=NULL;
}Tree;

Tree* newNode(int item)
{
	Tree* new_node = new Tree;
	new_node->data=item;
	new_node->left=NULL;
	new_node->right=NULL;

	return new_node;
}


//Convert a given Binary Tree to Doubly Linked List | Set 3
void bt2dll_3(Tree* root, Tree** head)
{
	if(!root)
		return;
	static Tree* prev=NULL;

	bt2dll_3(root->left,head);

	if(!prev)
		*head=root;
	else
	{
		root->left=prev;
		prev->right=root;
	}
	prev=root;

	bt2dll_3(root->right,head);
}

//print the data of DLL
void printdll(Tree* head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->right;
	}
}

int main()
{
	Tree* root=newNode(1);

	root->left=newNode(2);
	root->right=newNode(3);

	root->left->left=newNode(4);
	root->left->right=newNode(5);

	root->right->left=newNode(6);
	root->right->right=newNode(7);

	Tree* head=NULL;

	bt2dll_3(root,&head);

	printdll(head);

	return 0;
}