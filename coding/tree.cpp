#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <limits>

using namespace std;

//structure for tree node
typedef struct tree
{
	int data;
	struct tree *left,*right;
}tree;

//function for newnode creation
tree* newnode(int item)
{
	tree* node=new tree;
	node->data=item;
	node->left=NULL;
	node->right=NULL;

	return node;
}

//recursive function to print the data of tree in preorder 
void preorder(tree* root)
{
	if(!root)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}


//recursive function to print the data of tree in inorder 
void inorder(tree* root)
{
	if(!root)
		return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

//recursive function to print the data of tree in postorder
void postorder(tree* root)
{
	if(!root)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

//function to calculate the number of nodes in the tree
int numNodes(tree* root)
{
	if(!root)
		return 0;
	else
		return (numNodes(root->left) + numNodes(root->right) +1);
}

//function to check whether two binary tree are same or not
bool isSame(tree* root1, tree* root2)
{
	if(!root1 && !root2)
		return 1;

	if(root1 && root2)
		return (root1->data==root2->data && isSame(root1->left,root2->left) && isSame(root1->right,root2->right));

	return 0;
}

//function to find depth or maximum height of the tree
int depth(tree* root)
{
	if(!root)
		return 0;
	else
		return (1 + max(depth(root->left), depth(root->right)) );
}

//function to delete the tree
void deleteTree(tree* root)
{
	if(!root)
		return;
	
	deleteTree(root->left);
	deleteTree(root->right);

	delete(root);
	
}

//function to convert tree to its mirror image
void mirrorTree(tree* root)
{
	if(!root)
		return;

	tree* temp=root->right;
	root->right=root->left;
	root->left=temp;
	mirrorTree(root->left);
	mirrorTree(root->right);
}

//utility function for printing the path from root to leaf;
void printrec(tree* root,int a[], int pathlength)
{
	if(!root)
		return;

	a[pathlength]=root->data;
	pathlength++;

	if(!root->left && !root->right)
	{
		for(int i=0;i<pathlength;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}

	else
	{
		printrec(root->left,a,pathlength);
		printrec(root->right,a,pathlength);
	}
}

//function to print element from root to leaf for each path
void printRootToLeaf(tree* root)
{
	int a[100];
	printrec(root,a,0);
}

//utility function to print element of one level
void printlevel(tree* root, int level)
{
	if(!root)
		return;
	if(level==1)
		cout<<root->data<<" ";
	else
	{
		printlevel(root->left,level-1);
		printlevel(root->right,level-1);
	}
	
} 

//function to print data of tree in level order
void levelorder(tree* root)
{
	int h=depth(root);

	for(int i=1;i<=h;i++)
	{
		printlevel(root,i);
		cout<<endl;
	}
}

//function to count the leaf of the tree
int countLeaf(tree* root)
{
	if(!root)
		return 0;
	
	if(!root->left && !root->right)
		return 1;
	
	return (countLeaf(root->left) + countLeaf(root->right));

}

//utility function to print data in spiral way level wise
void printLevelSpiral(tree* root, int level, bool itr)
{
	if(!root)
		return;
	if(level==1)
		cout<<root->data<<" ";
	else if(level > 1)
	{
		if(itr)
		{
			printLevelSpiral(root->left,level-1,itr);
			printLevelSpiral(root->right,level-1,itr);
		}
		else
		{
			printLevelSpiral(root->right,level-1,itr);
			printLevelSpiral(root->left,level-1,itr);
		}
	}
}


//function to print data of the tree in level order of spiral form using recursion
void levelorderSpiral(tree* root)
{
	int h=depth(root);
	bool itr=false;

	for(int i=1;i<=h;i++)
	{
		printLevelSpiral(root,i,itr);
		itr=!itr;
		cout<<endl;
	}
		
}


//iterative function to print data in spiral form of level order traversal
void levelorderSpiralIter(tree* root)
{
	if(!root)
		return;

	stack<tree*> s1;
	stack<tree*> s2;

	s1.push(root);

	while(!s1.empty() || !s2.empty())
	{
		while(!s1.empty())
		{
			tree* temp=s1.top();
			cout<<temp->data<<" ";
			s1.pop();

			if(temp->right)
				s2.push(temp->right);
			if(temp->left)
				s2.push(temp->left);
		}
        cout<<endl;
		while(!s2.empty())
		{
			tree* temp2=s2.top();
			cout<<temp2->data<<" ";
			s2.pop();

			if(temp2->left)
				s1.push(temp2->left);
			if(temp2->right)
				s1.push(temp2->right);
		}
		cout<<endl;
	}
}


//function to check whether the data of a node is equal to sum of data of its children or not (children sum property)
int isSum(tree* root)
{
	if(!root || !root->left && !root->right)
		return 1;

	int leftdata=0, rightdata=0;

	if(root->left)
		leftdata=root->left->data;
	if(root->right)
		rightdata=root->right->data;

	if(root->data == leftdata+rightdata && isSum(root->left) && isSum(root->right))
		return 1;
	else
		return 0;
}

//utility function to increase the data of children node such that tree holds children sum property
void increment(tree* root, int d)
{
	if(root->left)
	{
		root->left->data+=d;
		increment(root->left,d);
	}
	else if(root->right)
	{
		root->right->data+=d;
		increment(root->right,d);
	}
}

//convert the tree in such a way that it holds children sum property and constraint is data of the node can only be increased
void convert(tree* root)
{
	int leftdata=0,rightdata=0;

	if(!root || !root->left && !root->right)
		return;

	else
	{
		convert(root->left);
		convert(root->right);

		if(root->left)
			leftdata=root->left->data;
		if(root->right)
			rightdata=root->right->data;

		int d=leftdata+rightdata-root->data;

		if(d>0)
			root->data=leftdata+rightdata;
		else if(d<0)
			increment(root,-d);
	}
}

//function to calculate the diameter of the tree
int diameter(tree* root)
{
	if(!root)
		return 0;

	return (max(depth(root->left)+depth(root->right)+1, max(diameter(root->left),diameter(root->right))));
}

//function to check whether the tree is balanced or not
int isBalanced(tree *root)
{
	if(!root)
		return 1;

	if(abs(depth(root->left)-depth(root->right))>1)
		return -1;

	return 1;
}

//inorder traversal without using recursion and using stack
void inorderIterStack(tree* root)
{
	stack<tree*> s;
	//s.push(root)
	tree* cur=root;
	while(cur || !s.empty())
	{
		if(cur)
		{
			s.push(cur);
			cur=cur->left;
		}
		else if(!s.empty())
		{
			cur=s.top();
			cout<<cur->data<<" ";
			s.pop();
			cur=cur->right;
		}
      
	}
}

//inorder traversal without using recursion and not using stack (Morris Traversal)
void inorderMorris(tree* root)
{
	tree* cur=root;
	tree* prev;

	if(!root)
		return;

	while(cur)
	{
		if(!cur->left)
		{
			cout<<cur->data<<" ";
			cur=cur->right;
		}

		else
		{
			prev=cur->left;

			while(prev->right && prev->right!=cur)
				prev=prev->right;

			if(!prev->right)
			{
				prev->right=cur;
				cur=cur->left;
			}
			else
			{
				prev->right=NULL;
				cout<<cur->data<<" ";
				cur=cur->right;
			}
		}
	}
}

//function to check whether sum of datas from root to leaf is equal to sum or not
bool isPathSum(tree* root,int sum)
{
	if(!root)
		return (sum==0);

	bool ans=0;
	int subsum=sum-root->data;

	if(subsum==0 && !root->left && !root->right)
		return 1;

	if(root->left)
		ans=ans||isPathSum(root->left,subsum);
	if(root->right)
		ans=ans||isPathSum(root->right,subsum);

	return ans;

}

//search a value in the array in defined range


//build a tree from inorder and preorder traversal sequence
tree* buildTree(int in[], int pr[], int l, int r)
{
	static int prindex=0;

	if(l>r)
		return NULL;
    
    tree* tnode=newnode(pr[prindex]);
    prindex++;

    if(l==r)
    	return tnode;

    int inindex=find(in+l,in+r,tnode->data)-in;

    tnode->left=buildTree(in,pr,l,inindex-1);
    tnode->right=buildTree(in,pr,inindex+1,r);

    return tnode;

}

//duplicate a node in the left side of the node
void duplicateInLeft(tree* root)
{
	if(!root)
		return;

	duplicateInLeft(root->left);
	duplicateInLeft(root->right);

	tree* oldLeft=root->left;
	root->left=newnode(root->data);
	root->left->left=oldLeft;

}

//width at a level of the tree (utility function to get max width of the tree using level order )
int widthLevel(tree* root, int level)
{
	if(!root)
		return 0;

	if(level==1)
		return 1;

	else
		return (widthLevel(root->left,level-1) + widthLevel(root->right,level-1));
}

//maximum width of the tree using levelorder technique
int maxWidthLevel(tree* root)
{
	int h=depth(root);
	int width,maxwidth=0;

	for(int i=1;i<=h;i++)
	{
		width=widthLevel(root,i);
		if(width>maxwidth)
			maxwidth=width;

	}
	return maxwidth;
}

//utility function to get array of width of every level
void widthPre(tree* root,int count[],int level)
{
	if(!root)
		return ;
	count[level]++;
	widthPre(root->left,count,level+1);
	widthPre(root->right,count,level+1);
}

//maximum width of the tree using preorder technique
int maxWidthPre(tree* root)
{
	int h=depth(root);
	int count[h]={0};
	int level=0;

	widthPre(root,count,level);

	return *max_element(count,count+h);
}


//utility function to check whether the tree is foldable or not (Method 1)
bool isFoldableUtil(tree* a, tree* b)
{
	if(!a && !b)
		return 1;
	if(!a || !b)
		return 0;
	return (isFoldableUtil(a->left,a->right) && isFoldableUtil(b->left, b->right));
}

//check whether the tree is foldable or not (Method 1)
bool isFoldable(tree* root)
{
	if(!root)
		return 1;

	return isFoldableUtil(root->left, root->right);
}

//utility function to convert a tree in its mirror image which is used in checking foldable tree
void mirror(tree* root)
{
	if(!root)
		return;
	mirror(root->left);
	mirror(root->right);

	tree* temp=root->left;
	root->left=root->right;
	root->right=temp;

}

//utility function to check the structure of two tree is same or not and it is used in checking foldable tree
bool isSameStructure(tree* a ,tree* b)
{
	if(!a && !b)
		return 1;
	if(!a || !b)
		return 0;
	return (isSameStructure(a->left,b->left) && isSameStructure(a->right,b->right));
}

//check whether the tree is foldable or not (Method 2)
bool isFoldable2(tree* root)
{
	if(!root)
		return 1;
	bool ans;
	mirror(root->left);
	ans=isSameStructure(root->left,root->right);
	mirror(root->left);
	return ans;
}

//print the nodes which are k distance away from the root
void printKFromRoot(tree* root, int k)
{
	if(k>=depth(root))
	{
		cout<<"please enter k less than height of the tree"<<endl;
		return;
	}

	if(k==0)
	{
		cout<<root->data<<" ";
		return;
	}

	printKFromRoot(root->left,k-1);
	printKFromRoot(root->right,k-1);
		
}

//utility function to be used to get the level of the node
int getLevelUtil(tree* root, int key, int level)
{
	if(!root)
		return 0;
	if(root->data==key)
		return level;
    return max(getLevelUtil(root->left,key,level+1) , getLevelUtil(root->right, key, level+1));
}

//get the level of node if the data of the node is given
int getLevel(tree* root, int key)
{
	if(!root)
		return 0;

	return getLevelUtil(root,key,1);
}

//print all the ancestors of a node
bool printAncestors(tree* root, int key)
{
	if(!root)
		return 0;
	if(root->data==key)
		return 1;
	if(printAncestors(root->left,key) || printAncestors(root->right,key))
	{
		cout<<root->data<<" ";
		return 1;
	}
	return 0;
}

//utility function to get the sum of data of all nodes of the tree
int sumTree(tree* root)
{
	if(!root)
		return 0;
	return (root->data + sumTree(root->left) + sumTree(root->right));
}

//check whether tree is Sumtree or not ,data of root should be equal to data of leftsubtree and rightsubtree. It takes O(n^2) time
bool isSumTree(tree* root)
{
	if(!root)
		return 1;
	if(!root->left && !root->right)
		return 1;
	if(root->data==sumTree(root->left)+sumTree(root->right) && isSumTree(root->left) && isSumTree(root->right))
		return 1;
	return 0;
}

//check whether the node is leaf node or not
bool isLeaf(tree* root)
{
	if(!root)
		return 0;

	if(!root->left && !root->right)
		return 1;

	return 0;
}

//check whether tree is Sumtree or not ,data of root should be equal to data of leftsubtree and rightsubtree. It takes O(n) time
bool isSumTree2(tree* root)
{
	if(!root)
		return 1;
	if(isLeaf(root))
		return 1;

	if(isSumTree2(root->left) && isSumTree2(root->right))
	{
		int ls,rs;

        if(!root->left)
       	    ls=0;
       	else if(isLeaf(root->left))
       		ls=root->left->data;
       	else 
       		ls=2*(root->left->data);

       	if(!root->right)
       		rs=0;
       	else if(isLeaf(root->right))
       		rs=root->right->data;
       	else
       		rs=2*(root->right->data);

       	return (root->data == ls+rs);
	}
	return 0;
}

//check whether a tree is a subtree of other or not. It uses function "isSame" which check whether two tree are same or not.
bool isSubtree(tree* T, tree* S)
{
	if(!S)
		return 1;
	if(!T)
		return 0;

	if(isSame(T,S))
		return 1;

	return (isSubtree(T->left,S) || isSubtree(T->right,S));
}


//minimum depth of the tree
int minDepth(tree* root)
{
	if(!root)
		return 0;

    int l = minDepth(root->left);
    int r = minDepth(root->right);

    if (l == 0 && r == 0)
        return 1; // leaf
    

    else if (l == 0) 
        return 1 + r;

    else  if (r == 0)
        return 1 + l;

    else
        return 1 + min(l, r);

}

//change the tree such that it has sum property i.e data of a node is sum of right subtree and left subtree and data of leaves be zero
int changeToSum(tree* root)
{
	if(!root)
		return 0;
	int old=root->data;
	root->data=changeToSum(root->left)+changeToSum(root->right);

	return old+root->data;
}

//driver main function
int main()
{
	tree* root=newnode(20);
	root->left=newnode(3);
	root->right=newnode(7);
	root->left->left=newnode(2);
	root->left->right=newnode(1);
	root->right->left=newnode(4);
    root->right->right=newnode(3);

    //tree* root2=newnode(7);
	//root2->left=newnode(4);
	//root2->right=newnode(3);
	//root2->left->left=newnode(2);
    //root2->right->right=newnode(8)

    //cout<<"The number of nodes in the tree is :"<<numNodes(root)<<endl;

   /* if(isSame(root,root2))
    	cout<<"Both tree are same."<<endl;
    else
    	cout<<"Both tree are not same."<<endl;*/

    //cout<<"The depth of the tree is :"<<depth(root)<<endl;

   /* deleteTree(root2);
    root2=NULL;
    cout<<"The number of nodes after deletion of tree :"<<numNodes(root2)<<endl;*/


    //cout<<"The number of leaf nodes is :"<<countLeaf(root)<<endl;
    
    //cout<<"The preorder traversal of the tree is:"<<endl;
    //preorder(root);
    //cout<<endl<<"The postorder traversal of the tree is:"<<endl;
    //postorder(root);
    //cout<<endl<<"The level oredr traversal of the tree is:"<<endl;
    //levelorder(root);
    //cout<<endl<<"The inorder traversal of the tree is:"<<endl;
    //inorder(root);
    //cout<<endl<<"The inorder traversal of the mirror of the above tree is:"<<endl;
    //mirrorTree(root);
    //inorder(root);
    //cout<<endl;

    //cout<<"The path from root to all leaf are following:"<<endl;
    //printRootToLeaf(root);

    //cout<<"The level order traversal of the tree in spiral form is:"<<endl;
    //levelorderSpiral(root);
    //cout<<endl<<"The level order traversal of the tree in spiral form without using recursion is:"<<endl;
    //levelorderSpiralIter(root);

    //(isSum(root)==1)?(cout<<"The data of root is equal to sum of data of its children") : (cout<<"The data of root is not equal to sum of data of its children");
    //convert(root);
    //cout<<endl;
    //(isSum(root)==1)?(cout<<"The data of root is equal to sum of data of its children") : (cout<<"The data of root is not equal to sum of data of its children");

    //cout<<endl<<diameter(root)<<endl;
    //cout<<isBalanced(root);

    //inorderIterStack(root);
    cout<<endl;
    //inorderMorris(root);
    //cout<<isPathSum(root,1)<<endl;

    //int in[]={2,8,1,5,4,6,3};
    //int pr[]={5,8,2,1,6,4,3};
    //tree* tnode=buildTree(in,pr,0,6);
    //inorder(tnode);
    
    //inorder(root);
    //duplicateInLeft(root);
    //cout<<endl;
    //inorder(root);
    //cout<<maxWidthLevel(root)<<endl;
    //cout<<maxWidthPre(root)<<endl;

    //(isFoldable(root)==1)?cout<<"the tree is foldable"<<endl : cout<<"The tree is not foldable"<<endl;
    //(isFoldable2(root)==1)?cout<<"the tree is foldable"<<endl : cout<<"The tree is not foldable"<<endl;
    

    //printKFromRoot(root,2);
    //cout<<getLevel(root,2)<<endl;
    //printAncestors(root,2);
    //(isSumTree(root)==1)?cout<<"the tree is Sum Tree"<<endl : cout<<"The tree is not Sum Tree"<<endl;
    //(isSumTree2(root)==1)?cout<<"the tree is Sum Tree"<<endl : cout<<"The tree is not Sum Tree"<<endl;

    //(isSubtree(root,root2)==1)?cout<<"the 2nd tree is Subtree of 1st tree"<<endl : cout<<"The 2nd tree is not Subtree of 1st tree"<<endl;
    //cout<<minDepth(root)<<endl;
    changeToSum(root);
    inorder(root);
    cout<<endl;

    return 0;
}

