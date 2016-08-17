#include <iostream>
#include <cstdlib>
#include <climits>
#include <stack>
#include <queue>
#include <algorithm>


using namespace std;

//structure of a tree
typedef struct tree 
{
	int data;
	struct tree *left;
	struct tree *right;
}Tree;


//create a new node
Tree* newNode(int item)
{
	Tree* tr=new Tree;
	tr->data=item;
	tr->left=NULL;
	tr->right=NULL;

	return tr;
}


//find the maximum element in the binary tree
int findMax(Tree* root)
{
	if(!root)
		return INT_MIN;

	int res=root->data;
	int lres=findMax(root->left);
	int rres=findMax(root->right);

	if(lres > res)
		res=lres;

	if(rres > res)
		res=rres;

	return res;
}


//find the minimum element in the binary tree
int findMin(Tree* root)
{
	if(!root)
		return INT_MAX;

	int res=root->data;
	int lres=findMin(root->left);
	int rres=findMin(root->right);

	if(lres < res)
		res=lres;

	if(rres < res)
		res=rres;

	return res;
}

//iterative search for a key int tree (using level order technique)
bool findKeyLevel(Tree* root,int key)
{
	if(!root)
		return false;

	queue <Tree* > qu;

	qu.push(root);

	while(!qu.empty())
	{
		Tree *tr=qu.front();

		if(tr->data == key)
			return true;

		qu.pop();

		if(tr->left)
			qu.push(tr->left);

		if(tr->right)
			qu.push(tr->right);
	}

	return false;

}

//iterative search for a key int tree (using pre order technique)
bool findKeyPre(Tree* root, int key)
{
	if(!root)
		return false;

	stack <Tree* > st;

	st.push(root);

	while(!st.empty())
	{
		Tree* tr=st.top();

		if(tr->data==key)
			return true;
        
        st.pop();
		if(tr->left)
			st.push(tr->left);
		if(tr->right)
			st.push(tr->right);
	}

	return false;
}

//iterative search for a key int tree (using in order technique)
bool findKeyIn(Tree* root,int key)
{
	if(!root)
		return false;

	stack <Tree* > st;

	Tree* cur=root;

	while(cur || !st.empty())
	{
		if(cur)
		{
			st.push(cur);
			cur=cur->left;
		}
		else if(!st.empty())
		{
			cur=st.top();

			if(cur->data == key)
				return true;

			st.pop();
			cur=cur->right;
		}
	}
	return false;
}

//function to check a node is leaf node
bool isLeaf(Tree* root)
{
	if(!root)
		return false;
	if(!root->left && !root->right)
		return true;

	return false;
}

//find the sum of all left leaves
int leftLeaveSum(Tree* root)
{
	//if(!root)
		//return 0;

	int res=0;

	if(root)
	{
		if(isLeaf(root->left))
		{
			res+=(root->left)->data;

		}

		else
			res+=leftLeaveSum(root->left);

		res+=leftLeaveSum(root->right);
	}

	return res;
}


//check the tree is full binary tree or not
bool isFull(Tree* root)
{
	if(!root)
		return true;

	if( (root->left && !root->right) || (!root->left && root->right) )
		return false;

	isFull(root->left);
	isFull(root->right);
}


//vertex cover for the tree
int vertexcover(Tree* root)
{
	if(!root || (!root->left && !root->right))
		return 0;

	int incl=1+vertexcover(root->left)+vertexcover(root->right);
	int excl=0;
	if(root->left)
		excl+=1+vertexcover(root->left->left)+vertexcover(root->left->right);
	if(root->right)
		excl+=1+vertexcover(root->right->left)+vertexcover(root->right->right);

	return min(incl,excl);
}


//remove half nodes from the tree
Tree* removeHalfNodes(Tree* root)
{
	if(!root)
		return NULL;

	root->left=removeHalfNodes(root->left);
	root->right=removeHalfNodes(root->right);

	if(!root->left && !root->right)
		return root;

	if(!root->left)
	{
		Tree* new_node=root->right;
        delete(root);
        return new_node;
	}

	if(!root->right)
	{
		Tree* new_node=root->left;
		delete(root);
		return new_node;
	}

	return root;
}

//inoreder traversal using recursion
void inorder(Tree* root)
{
	if(root)
		{
			inorder(root->left);
	        cout<<root->data<<" ";
	        inorder(root->right);
		}
	
}

//print nodes of level in linewise non-recursive
/*void printLevelLine(Tree* root)
{
	queue <Tree* > q;
	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{
		Tree* temp=q.front();

		if(temp==NULL)
		{
			if(!q.empty())
			{
				cout<<endl;
			    q.pop();
			    q.push(NULL);
			}
			
		}
		else
		{
			cout<<temp->data<<" ";
			q.pop();
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}

	}
}*/



//main driver function
int main()
{
	Tree* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    inorder(root);


    //Tree* newRoot=NULL;

    //cout<<"The maximum element in the binary tree is : "<<findMax(root)<<endl;
    //cout<<"The minimum element in the binary tree is : "<<findMin(root)<<endl;

    /*findKeyLevel(root,6)?cout<<"Found"<<endl : cout<<"Not Found"<<endl;
    findKeyLevel(root,12)?cout<<"Found"<<endl : cout<<"Not Found"<<endl;

    findKeyPre(root,6)?cout<<"Found"<<endl : cout<<"Not Found"<<endl;
    findKeyPre(root,12)?cout<<"Found"<<endl : cout<<"Not Found"<<endl;

    findKeyIn(root,6)?cout<<"Found"<<endl : cout<<"Not Found"<<endl;
    findKeyIn(root,12)?cout<<"Found"<<endl : cout<<"Not Found"<<endl;*/

    //cout<<"The sum of left leave is : "<<leftLeaveSum(root)<<endl;

    //isFull(root) ? cout<<"Tree is full binary true"<<endl : cout<<"Tree is not full binary tree"<<endl;

    //cout<<"The number of vertex in vertex cover of the tree "<<vertexcover(root)<<endl;

    //newRoot=removeHalfNodes(root);

    
    //cout<<endl;
    //inorder(newRoot);
    //cout<<endl;

   // printLevelLine(root);

    return 0;
}