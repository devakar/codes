#include <iostream>
#include <algorithm>

using namespace std;

typedef struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
	struct tree* next;
}tree;

//utility function to assign next pointer of every node
void connectRec(tree* root)
{
	if(!root)
		return;

	if(root->left)
		root->left->next=root->right;

	if(root->right)
		root->right->next=(root->next)?root->next->left:NULL;

	connectRec(root->left);
	connectRec(root->right);
}

//connect the nodes of same level via next pointer .It works for complete binary tree.
void connect(tree* root)
{
	if(!root)
		return;
	root->next=NULL;
	connectRec(root);
}


//utilty function to get the leftmost next for the node
tree* getNext(tree* root)
{
	tree* temp=root->next;

	while(temp)
	{
		if(temp->left)
			return temp->left;
		if(temp->right)
			return temp->right;

		temp=temp->next;
	}
	return NULL;
}


//utility function to assign next pointer of every node
void connectRec2(tree* root)
{
	if(!root)
		return;

	if(root->next)
		connectRec2(root->next);

	if(root->left)
	{
		if(root->right)
		{
			root->left->next=root->right;
			root->right->next=getNext(root);
		}
		else
			root->left->next=getNext(root);

		connectRec2(root->left);
	}

	else if(root->right)
	{
		root->right->next=getNext(root);
		connectRec2(root->right);
	}

	else
		connectRec2(root->next);
		
}


//connect the nodes of same level via next pointer for all binary tree by recursion
void connect2(tree* root)
{
	if(!root)
		return;
	root->next=NULL;
	connectRec2(root);
}

//connect the nodes of same level via next pointer for all binary tree by iteration
void connect3(tree* root)
{
	if(!root)
		return;

	root->next=NULL;

	while(root)
	{
		tree* r=root;

		while(r)
		{
			if(r->left)
			{
				if(r->right)
				    r->left->next=r->right;
				else
					r->left->next=getNext(r);
			}
			if(r->right)
				r->right->next=getNext(r);

			r=r->next;
		}

		if(root->left)
			root=root->left;
		else if(root->right)
			root=root->right;
        else
        	root=getNext(root);
	}
}

//connect the nodes where next points to inorder successor of that node
void connectInorder(tree* root)
{
	if(!root)
		return;
	static tree* suc=NULL;

	connectInorder(root->right);
	root->next=suc;
	suc=root;
	connectInorder(root->left);
}

//utility function to connect the nodes to its inorder successor
void connectInorder2Rec(tree* root,tree** suc)
{
	if(!root)
		return;
	connectInorder2Rec(root->left,suc);
	root->next=*suc;
	*suc=root;
	connectInorder2Rec(root->right,suc);
}

//connect the nodes where next points to inorder successor of that node without using static variable
void connectInorder2(tree* root)
{
	if(!root)
		return;
	tree * suc=NULL;
	connectInorder2Rec(root,&suc);
}


//traverse the nodes of tree by the next pointer
void traverse(tree* root)
{
	tree* temp1=root;
	tree* temp2=root;

	while(temp1)
	{
		temp2=temp1;
		while(temp2)
		{
			cout<<temp2->data<<" ";
			temp2=temp2->next;
		}
		cout<<endl;
		temp1=temp1->left;
	}

}


//create a newnode in the tree
tree* newnode(int val)
{
	tree* node=new tree;
	node->data=val;
	node->left=NULL;
	node->right=NULL;
	node->next=NULL;

	return node;
}


int main()
{
	tree *root = newnode(10);
    root->left        = newnode(8);
    root->right       = newnode(2);
    root->left->left  = newnode(3);
    root->right->right       = newnode(90);


	tree *root2 = newnode(10);
    root2->left        = newnode(8);
    root2->right       = newnode(2);
    root2->left->left  = newnode(3);
    root2->right->right       = newnode(90);

    tree *root3 = newnode(10);
    root3->left        = newnode(8);
    root3->right       = newnode(2);
    root3->left->left  = newnode(3);
    root3->right->right       = newnode(90);

    tree *root4 = newnode(10);
    root4->left        = newnode(8);
    root4->right       = newnode(2);
    root4->left->left  = newnode(3);
    root4->right->right       = newnode(90);

    tree *root5 = newnode(10);
    root5->left        = newnode(8);
    root5->right       = newnode(2);
    root5->left->left  = newnode(3);
    root5->right->right       = newnode(90);

    tree *ptr = root4->left->left;
    tree *ptr2 = root4->left->left;

	connect(root);
	traverse(root);
	cout<<endl;
	connect2(root2);
	traverse(root2);
	cout<<endl;
	connect3(root3);
	traverse(root3);
	cout<<endl;
	connectInorder(root4);
	while(ptr)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<endl;

	while(ptr2)
	{
		cout<<ptr2->data<<" ";
		ptr2=ptr2->next;
	}
	cout<<endl;
}
