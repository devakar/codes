#include <iostream>
#include <cstdlib>
#include <climits>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

#define MAX 20

using namespace std;

typedef struct tree
{
	int data;
	struct tree *left,*right;
}Tree;

//function for newnode creation
Tree* newNode(int item)
{
	Tree* node=new Tree;
	node->data=item;
	node->left=NULL;
	node->right=NULL;

	return node;
}


/*

//Print level order traversal line by line
void printLevelLine(Tree* root)
{
	if(!root)
	  return;

	queue <Tree* > q;
	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{
		Tree* temp=q.front();

		if(temp==NULL)
		{
			cout<<endl;
			    q.pop();
			    if(q.empty())
			       break;
			    q.push(NULL);
			
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
}


//height of the tree
int height(Tree* root)
{
	if(!root)
		return 0;
	return ( max( height(root->left) , height(root->right) ) +1 );
}

//Print level order traversal line by line using recursion

void printAtLevel(Tree* root,int level)
{
	if(!root)
		return;
	if(level==1)
		cout<<root->data<<" ";
	else if(level>1)
	{
		printAtLevel(root->left,level-1);
		printAtLevel(root->right,level-1);
	}
		
}

void printLevelLineRec(Tree* root)
{
	int h=height(root);

	for(int i=1;i<=h;i++)
	{
		printAtLevel(root,i);
		cout<<endl;
	}
}

//Print level oredr traversal line by line using iteration
void printLevelLineNonRec(Tree* root)
{
	if(!root)
		return;

	queue <Tree* > qu;
	qu.push(root);

	while(1)
	{
		int c=qu.size();

		if(c==0)
			break;

		while(c>0)
		{
			Tree* temp=qu.front();
			cout<<temp->data<<" ";
			qu.pop();

			if(temp->left)
				qu.push(temp->left);
			if(temp->right)
				qu.push(temp->right);

			c--;
		}

		cout<<endl;
	}
}


//Perfect Binary Tree Specific Level Order Traversal
void SpecificLevelOrder(Tree* root)
{
	if(!root)
		return;
	cout<<root->data<<" ";

	if(root->left)
		cout<<root->left->data<<" "<<root->right->data<<" ";

	if(!root->left->left)
		return;

	queue <Tree* > q;
	q.push(root->left);
	q.push(root->right);

	Tree* first=NULL;
	Tree* second=NULL;

	while(!q.empty())
	{
		first=q.front();
		q.pop();
		second=q.front();
		q.pop();

		cout<<first->left->data<<" "<<second->right->data<<" ";
		cout<<first->right->data<<" "<<second->left->data<<" ";

		if(first->left->left)
		{
			q.push(first->left);
			q.push(second->right);
			q.push(first->right);
			q.push(second->left);
		}
	}
}


//Bottom View of a Binary Tree

bool  hd(Tree* root, Tree* node, int* key)
{
	if(!root)
		return false;
	if(root==node)
	    return true;
	else
	{
		if(hd(root->left,node,key))
		{
			(*key)-=1;
			return true;
		}
			
		else if(hd(root->right,node,key))
		{
			(*key)+=1;
			return true;
		}
			
	}
	
}


void bottomView(Tree* root)
{
	if(!root)
		return;

	int key=0;

	map<int,int> m;
	map<int,int> :: iterator pos;

	m.insert(make_pair(key,root->data));

	queue<Tree* > q;
	q.push(root);

	while(!q.empty())
	{
		Tree* temp=q.front();
		q.pop();

		int lkey=0;
		int rkey=0;

		if(temp->left)
		{
			q.push(temp->left);

			if(hd(root,temp->left,&lkey))
			{
				pos=m.find(lkey);
				if(pos!=m.end())
					 m.erase (pos);
               
			    m.insert(make_pair(lkey, temp->left->data));
			}

			
		}

		if(temp->right)
		{
			q.push(temp->right);
			if(hd(root,temp->right,&rkey))
			{
				pos=m.find(rkey);
                if(pos!=m.end())
					 m.erase (pos);

			    m.insert(make_pair(rkey, temp->right->data));
			}
		}
	}

	
	for(pos=m.begin();pos!=m.end();++pos)
		cout<<pos->second<<" ";
}


//Top view of a binary tree
void LtopView(Tree* root)
{
	if(root)
	{
		LtopView(root->left);
		cout<<root->data<<" ";
	}
}

void RtopView(Tree* root)
{
	if(root)
	{
		cout<<root->data<<" ";
		RtopView(root->right);
	}
}

void topView(Tree* root)
{
	if(!root)
		return;
	LtopView(root);
	RtopView(root->right);

}


//print the nodes between two given nodes of the binary tree
void printBetweenLevels(Tree* root,int l,int h)
{
	if(!root)
		return;
	if(l>h)
		cout<<"Please enter correctly"<<endl;

	queue <Tree* > q;
	q.push(root);

	int level=1;

	while(1)
	{
		int numNodes=q.size();

		if(numNodes==0)
			break;

		while(numNodes>0)
		{
			Tree* temp=q.front();
			q.pop();

			if(level>=l && level<=h)
				cout<<temp->data<<" ";

			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);

			numNodes--;
		}
		if(level>=l && level<=h)
			cout<<endl;
		level++;
	}
}

//use of /* to save compile time
*/

//--------------------------------------------------------------------------------------------------------------------------------------------------

//It needs to enable c++11
//Check if a binary tree is subtree of another binary tree in O(n) time complexity
/*
//utility function to store inorder
void storeInorder(Tree* root, string* sIn)
{
	if(!root)
	{
		*sIn+="$";
		return;
	}
	
	storeInorder(root->left,sIn);
	*sIn+=to_string(root->data);
	storeInorder(root->right,sIn);
}

//utility function to store preorder 
void storePreorder(Tree* root, string* sPre)
{
	if(!root)
	{
		*sPre+="$";
		return;
	}
	*sPre+=to_string(root->data);
	storePreorder(root,sPre);
	storePreorder(root,sPre);
}

bool isSubtree(Tree* T, Tree* S)
{
	if(!S)
		return true;
	if(!T)
		return false;

	string sInT="", sInS="";
	string sPreT="", sPreS="";

	storeInorder(T,&sInT);
	storeInorder(S,&sInS);

	storePreorder(T,&sPreT);
	storePreorder(S,&sPreS);

	if(sInT.find(sInS)!=(string :: npos) &&  sPreT.find(sPreS)!=(string :: npos))
		return true;


    return false;

}
*/


//--------------------------------------------------------------------------------------------------------------------------------------------------

/*

//check two nodes are sibling or not
bool isSibling(Tree* root, Tree* a, Tree* b)
{
	if(!root)
		return false;

	return((root->left==a && root->right==b) || (root->left==b && root->right==a) || isSibling(root->left,a,b) || isSibling(root->right,a,b));
}

//find level of the node
int level(Tree* root, Tree* a, int lev)
{
	if(!root)
		return 0;
	if(root==a)
		return lev;
	int l=level(root->left,a,lev+1);
	if(l!=0)
		return l;
	return (level(root->right,a,lev+1));

}

//check two nodes are cusion or not
bool isCusion(Tree* root,Tree* a,Tree* b)
{
	return (!isSibling(root,a,b) && (level(root,a,0)==level(root,b,0)) );
}

/*

-------------------------------------------------------------------------------------------

//Reverse alternate levels of a perfect binary tree

//store the data of nodes of odd level in inorder traversal
/*void storeOddIn(Tree* root, int a[], int* i, int l)
{
	if(!root)
		return;

	storeOddIn(root->left, a, i, l+1);

	if(l%2!=0)
	{
		a[*i]=root->data;
		*i++;
	}

	storeOddIn(root->right,a,i,l+1);
}*/

/*void storeOddIn(Tree* root, vector<int> &v, int l)
{
	if(!root)
		return;

	storeOddIn(root->left, v, l+1);

	if(l%2!=0)
	{
		v.push_back(root->data);
	}

	storeOddIn(root->right,v,l+1);
}*/

//modify the tree by changing data of odd level nodes in inoredr traversal;
/*void modifyAlt(Tree* root, int a[], int* i, int l)
{
	if(!root)
		return;
	modifyAlt(root->left,a,i,l+1);

	if(l%2!=0)
	{
		root->data=a[*i];
		*i++;
	}
	modifyAlt(root->right,a,i,l+1);
}*/

/*void modifyAlt(Tree* root, vector<int> &v, int* i, int l)
{
	if(!root)
		return;
	modifyAlt(root->left,v,i,l+1);

	if(l%2!=0)
	{
		root->data=v[*i];
		(*i)++;
	}
	modifyAlt(root->right,v,i,l+1);
}*/

//function to call above two functions to reverse alternate levels of perfect binry tree
/*void reverseAlt(Tree* root)
{
	if(!root)
		return;
	int index=0;
	int a[MAX];

	storeOddIn(root,a,&index,0);

	reverse(a.begin(),a.end());
    
    index=0;
	modifyAlt(root,a,&index,0);
}
*/

//------------------------------------------------------------------------------------------------------------------------------------

/*


void reverseAlt(Tree* root)
{
	if(!root)
		return;
	int index=0;
	vector <int> v;

	storeOddIn(root,v,0);

	reverse(v.begin(),v.end());
    
    //index=0;
	modifyAlt(root,v,&index,0);
}



//Find the maximum path sum between two leaves of a binary tree
//utility function

int maxPathUtil(Tree* root, int *res)
{
	if(!root)
		return 0;
	if(!root->left && !root->right)
		return root->data;

	int ls,rs;

	ls=maxPathUtil(root->left,res);
	rs=maxPathUtil(root->right,res);

	int cur_sum=ls+rs+root->data;

	if(cur_sum > *res)
		*res=cur_sum;

	if(!ls||!rs)
		return (!ls)? rs+root->data : ls+root->data;
	else
		return max(ls,rs)+root->data;

	return max(ls,rs)+root->data;
}

int maxPathSum(Tree* root)
{
    int res=INT_MIN;
    maxPathUtil(root,&res);
    return res;
}



//Construct a tree from Inorder and Level order traversals

int search(int in[], int start, int end, int key)
{
   for(int i=start; i<=end; i++)
   	 if(in[i]==key)
   	 	return i;

   	return -1;
}

int* extract(int in[], int level[], int m, int n)
{
	int* newlevel=new int[m];
	int j=0;

	for(int i=0; i<n; i++)
	{
		if(search(in, 0, m-1, level[i])!=-1)
		{
			newlevel[j]=level[i];
			j++;
		}
			

	}

	return newlevel;
}



Tree* build(int in[], int level[], int start, int end, int n)
{
  if(start > end)
  	 return NULL;

  Tree* root=newNode(level[0]);

     if(start==end)
     	return root;

  int inIndex = search(in,start,end,root->data);

  int* llevel = extract(in, level, inIndex, n);
  int* rlevel = extract(in+inIndex+1, level, n-inIndex-1, n);

  root->left = build(in, llevel, start, inIndex-1, n);
  root->right = build(in, rlevel, inIndex+1, end, n);

  delete [] llevel;
  delete [] rlevel;

  return root;
}



//Print a Binary Tree in Vertical Order

void findMinMax(Tree* root, int *min, int *max, int hd)
{
	if(!root)
		return;

	if(hd < *min)
		*min=hd;
	else if(hd > *max)
		*max=hd;

	findMinMax(root->left, min, max, hd-1);
	findMinMax(root->right, min, max, hd+1);
}

void printVertical(Tree* root, int d, int hd)
{
	if(!root)
		return;
	if(d==hd)
		cout<<root->data<<" ";

	printVertical(root->left,d,hd-1);
	printVertical(root->right,d,hd+1);
}

void verticalorder(Tree* root)
{
	int min=0,max=0;

    findMinMax(root,&min,&max,0);

    for(int i=min; i<=max; i++)
    {
    	printVertical(root, i, 0);
    	cout<<endl;
    }
    	
}


//Print all nodes at distance k from a given node

void printKdistanceNodesDown(Tree* root, int k)
{
	if(!root || k < 0)
		return;

	if(k==0)
	{
		cout<<root->data<<endl;
		return;
	}
	printKdistanceNodesDown(root->left,k-1);
	printKdistanceNodesDown(root->right,k-1);
}

int printKdistanceNodes(Tree* root, Tree* target, int k)
{
	if(!root )
		return -1;

	if(root == target)
	{
		printKdistanceNodesDown(root, k);
		return 0;
	}

	int ls=printKdistanceNodes(root->left, target, k);

	if(ls!=-1)
	{
		if(ls+1==k)
			cout<<root->data<<endl;
		else
			printKdistanceNodesDown(root->right, k-ls-2);

		return ls+1;
	}

	int rs=printKdistanceNodes(root->right, target, k);

	if(rs!=-1)
	{
		if(rs+1==k)
			cout<<root->data<<endl;
		else
			printKdistanceNodesDown(root->left, k-rs-2);

		return rs+1;
	}

    return -1;
}
*/

//Check if a given Binary Tree is height balanced like a Red-Black Tree (the maximum height of a node is at most twice the minimum height)
/*
bool isBalancedUtil(Tree* root, int *minh, int *maxh)
{
	if(!root)
	{
		*minh=0;
		*maxh=0;
		return true;
	}

	int lmin,lmax,rmin,rmax;

	if(!isBalancedUtil(root->left, &lmin, &lmax))
		return false;
	if(!isBalancedUtil(root->right, &rmin, &rmax))
		return false;

	(*maxh)=max(lmax, rmax)+1;
	(*minh)=min(lmin, rmin)+1;

	if(*maxh <= 2* (*minh))
		return true;

	return false;
}


bool isBalanced(Tree* root)
{
	int minh, maxh;
	return isBalancedUtil(root,&minh,&maxh);
}


//Print all nodes that are at distance k from a leaf node

void printKfromLeafUtil(Tree* root, int path[], bool visited[], int pathlength, int k)
{
	if(!root)
		return;

	path[pathlength]=root->data;
	visited[pathlength]=false;
	pathlength++;

	if(!root->left && !root->right && pathlength-k-1 >=0 && !visited[pathlength-k-1])
	{
		cout<<path[pathlength-k-1]<<" ";
		visited[pathlength-k-1]=true;
		return;
	}

	printKfromLeafUtil(root->left,path,visited,pathlength,k);
	printKfromLeafUtil(root->right,path,visited,pathlength,k);

}

void printKfromLeaf(Tree* root, int k)
{
	int path[1000];
	bool visited[1000]={false};
	printKfromLeafUtil(root,path,visited,0,k);
}

*/

//find lowest common ancestor
/*
Tree* lca(Tree* root, int x, int y)
{
	if(!root)
		return NULL;

	if(root->data==x || root->data==y)
		return root;

	Tree* left_lca=lca(root->left, x,y);
	Tree* right_lca=lca(root->right,x,y);

	if(left_lca && right_lca)
		return root;

	return ((!left_lca) ? right_lca : left_lca); 
}


//Find distance between two given keys of a Binary Tree

int findLevelUtil(Tree* root, int key, int level)
{
	if(!root )
		return -1;
	if(root->data==key)
		return level;

	int l=findLevelUtil(root->left,key,level+1);

	if(l!=-1)
		return l;
	
	int r=findLevelUtil(root->right,key,level+1);
	return r;


}

int findLevel(Tree* root, int key)
{
	return findLevelUtil(root,key,0);
}


int dist_nodes(Tree* root, int x, int y)
{
	Tree* lca_xy =lca(root, x, y);

	int lx=findLevel(root,x);
	int ly=findLevel(root,y);
	int l_lca=findLevel(root,lca_xy->data);

	return (lx+ly-2*l_lca);
}


//Sum of all the numbers that are formed from root to leaf paths

int pathSumUtil(Tree* root, int val)
{
	if(!root)
		return 0;

	val = 10*val + root->data;

	if(!root->left && !root->right)
		return val;

	return (pathSumUtil(root->left,val) + pathSumUtil(root->right,val));
}

int pathSum(Tree* root)
{
	return (pathSumUtil(root,0));
}


//Find next right node of a given key
Tree* findNextright(Tree* root, int k)
{
	if(!root)
		return NULL;
	queue <Tree* > qn;
	queue <int> ql;
	int level=0;
	qn.push(root);
	ql.push(level);

	while(!qn.empty())
	{
		Tree* temp=qn.front();
		level=ql.front();

		qn.pop();
		ql.pop();

		if(temp->data==k)
		{
			if(ql.empty() || ql.front()!=level)
				return NULL;

			return qn.front();
		}

		if(temp->left)
		{
			qn.push(temp->left);
			ql.push(level+1);
		}

		if(temp->right)
		{
			qn.push(temp->right);
            ql.push(level+1);

		}

		
		
	}
}


//Deepest left leaf node in a binary tree

void deepLeftLeafUtil(Tree* root, int lvl, int *maxlvl, bool isleft, Tree** res)
{
	if(!root)
		return;

	if(isleft && !root->left && !root->right && lvl > *maxlvl)
	{
		*maxlvl=lvl;
		*res=root;
		return;
	}

	deepLeftLeafUtil(root->left, lvl+1, maxlvl, true, res);
	deepLeftLeafUtil(root->right, lvl+1, maxlvl, false, res);
}

Tree* deepLeftLeaf(Tree* root)
{
	Tree* res=NULL;
	int maxl=0;

	deepLeftLeafUtil(root, 0, &maxl, false, &res);
	return res;
}


//Extract Leaves of a Binary Tree in a Doubly Linked List
Tree* extractLeavesInDLL(Tree* root, Tree** head)
{
	if(!root)
		return NULL;

	if(!root->left && !root->right)
	{
		root->right=*head;

		if(*head)
			(*head)->left=root;

		*head=root;
		return NULL;
	}

	root->right=extractLeavesInDLL(root->right, head);
	root->left=extractLeavesInDLL(root->left, head);

}


//Remove all nodes which don’t lie in any path with sum>= k
Tree* removeNodes_sum(Tree* root, int sum)
{
	if(!root)
		return NULL;

	root->left=removeNodes_sum(root->left, sum-root->data);
	root->right=removeNodes_sum(root->right, sum-root->data);

	if(!root->left && !root->right)
	{
		if(root->data < sum)
		{
			delete root;
			return NULL;
		}
	}

	return root;
}

//print left view of binary tree

void leftviewUtil(Tree* root, int lvl, int* maxlvl)
{
	if(!root)
		return;

	if(*maxlvl < lvl)
	{
		cout<<root->data<<" ";
		*maxlvl=lvl;
	}
	leftviewUtil(root->left, lvl+1, maxlvl);
	leftviewUtil(root->right, lvl+1, maxlvl);
}

void leftview(Tree* root)
{
	int maxlvl=0;
	leftviewUtil(root, 1 , &maxlvl);
}


//Check if all leaves are at same level

bool isLeavesSamelevelUtil(Tree* root, int lvl, int* maxlvl)
{
	if(!root)
		return true;

	if(!root->left && !root->right)
	{
		if(*maxlvl==1)
		{
			*maxlvl=lvl;
		}

		return (*maxlvl==lvl);
	}

	return (isLeavesSamelevelUtil(root->left, lvl+1, maxlvl) && isLeavesSamelevelUtil(root->right, lvl+1, maxlvl));
}

bool isLeavesSamelevel(Tree* root)
{
	int level=1, maxlvl=1;
	return isLeavesSamelevelUtil(root, level, &maxlvl);
}

//Find depth of the deepest odd level leaf node

int depthOddleafUtil(Tree* root, int level)
{
	if(!root)
		return 0;

	if(!root->left && !root->right && level&1)
	{
		return level;
	}

	return max(depthOddleafUtil(root->left,level+1), depthOddleafUtil(root->right, level+1));
}

int depthOddleaf(Tree* root)
{
	int level=1;
	return depthOddleafUtil(root,level);
}


//Print Postorder traversal from given Inorder and Preorder traversals

int search(int in[], int x, int n)
{
	for(int i=0;i<n;i++)
	{
		if(in[i]==x)
			return i;
	}
	return -1;
}

void printpost(int in[], int pre[], int n)
{
	int root=search(in,pre[0],n);

	if(root!=0)
		printpost(in, pre+1, root);

	if(root!=n-1)
		printpost(in+root+1, pre+root+1, n-root-1);

	cout<<pre[0]<<" ";
}


//Difference between sums of odd level and even level nodes of a Binary Tree
int sumLevelDiffer(Tree* root)
{
	if(!root)
		return 0;

	return (root->data - sumLevelDiffer(root->left) - sumLevelDiffer(root->right) );
}


void printList(Tree* head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->right;
	}
	cout<<endl;
}
*/

/*
//print ancestor of a node using recursion
bool ancestor(Tree* root, int key)
{
	if(!root)
		return false;

	if(root->data==key)
		return true;

	if(ancestor(root->left,key) || ancestor(root->right,key))
	{
		cout<<root->data<<" ";
		return true;
	}

	return false;
}

//print ancestor of a node without using recursion
void ancestor2(Tree* root, int key)
{
	if(!root)
		return;

	stack <Tree* > st;
	

	while(1)
	{
		while(root && root->data!=key)
		{
			st.push(root);
			root=root->left;
		}

		if(root && root->data==key)
			break;

		if(!((st.top())->right))
		{
			root=st.top();
			st.pop();

			while(!st.empty() && st.top()->right==root)
			{
				root=st.top();
				st.pop();
			}
		}
		root = st.empty() ? NULL : st.top()->right;

	}

	while(!st.empty())
	{
		cout<<st.top()->data<<" ";
		st.pop();
	}
}
*/

//bottom view of binary tree

void gethd(Tree* root, int hd, map<int,int> &m)
{
	if(!root)
		return;
	m[hd]=root->data;

	gethd(root->left,hd-1,m);
	gethd(root->right,hd+1,m);
}

void bottom_view(Tree* root)
{
	if(!root)
		return;
	map<int,int> m;
	int hd=0;
	gethd(root,hd,m);

	map<int,int>::iterator pos;
	for(pos=m.begin();pos!=m.end();pos++)
	{
		cout<<(pos->second)<<" ";
	}
}


//top view of binary tree

void gethd2(Tree* root, int hd, map<int,int> &m)
{
	if(!root)
		return;
	if(m.find(hd)==m.end())
	    m[hd]=root->data;

	gethd(root->left,hd-1,m);
	gethd(root->right,hd+1,m);
}

void top_view(Tree* root)
{
	if(!root)
		return;
	map<int,int> m;
	int hd=0;
	gethd2(root,hd,m);

	map<int,int>::iterator pos;
	for(pos=m.begin();pos!=m.end();pos++)
	{
		cout<<(pos->second)<<" ";
	}
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

//level oredre traversal
void levelorder(Tree* root)
{
	if(!root)
		return;

	queue <Tree* > q;
	q.push(root);

	while(!q.empty())
	{
		Tree* temp=q.front();
		q.pop();
		cout<<temp->data<<" ";

		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
}

int main()
{
	Tree* root =  newNode(1);
 
    root->left        = newNode(2);
    root->right       = newNode(3);
 
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    //root->left->left->left = newNode(2);
    //root->left->left->right = newNode(6);
    //root->left->right->left = newNode(10);
    //root->left->right->right = newNode(11);
    //root->right->left->left = newNode(12);
    //root->right->left->right = newNode(13);
    //root->right->right->left = newNode(14);
    //root->right->right->right = newNode(0);

    //root->right->right->right->left= newNode(4);
    //root->right->right->right->right= newNode(-1);
    //root->right->right->right->right->left= newNode(10);


    /*Tree* root2 =  newNode(12);
 
   
    root2->left = newNode(10);
    root2->right = newNode(14);*/
    
    //inorder(root);
    //cout<<endl;

    //printLevelLine(root);
    //printLevelLineRec(root);
    //printLevelLineNonRec(root);

    //SpecificLevelOrder(root);

    /*int k=0;

    if(hd(root, root->left->right->right ,&k))
    	cout<<k;*/

    //bottomView(root);

    //topView(root);
    //cout<<endl;
    //printBetweenLevels(root,2,4);
    /*if(isSubtree(root,root2))
    	cout<<"Second tree is subtree of first tree"<<endl;
    else
    	cout<<"Second tree is not subtree of first tree"<<endl;*/


    //(isCusion(root, root->left->left->left, root->left->left )) ? cout<<"Both nodes are cusion"<<endl : cout<<"Both nodes are not cusion"<<endl;
   
    //levelorder(root);
     cout<<endl;
   // reverseAlt(root);
    /*vector <int> v;

	storeOddIn(root,v,0);
    vector<int> :: iterator pos;
	
	for(pos=v.begin();pos!=v.end();pos++)
	  cout<<*pos<<" ";
    
    cout<<endl;
	reverse(v.begin(),v.end());
	for(pos=v.begin();pos!=v.end();pos++)
	  cout<<*pos<<" ";
    
    int index=0;
	modifyAlt(root,v,&index,0);*/

	//reverseAlt(root);

    cout<<endl;
    //levelorder(root);

    //cout << "Max pathSum of the given binary tree is " << maxPathSum(root)<<endl;

    /*int in[]    = {4, 8, 10, 12, 14, 20, 22};
    int level[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(in)/sizeof(in[0]);
    Tree *root = build(in, level, 0, n - 1, n);
    
    inorder(root);
    cout<<endl;
    levelorder(root);
    cout<<endl;*/
    
    //verticalorder(root);

    //printKdistanceNodes(root,root->right,3);

    //isBalanced(root)?cout<<"Tree is balanced "<<endl : cout<<"Tree is not balanced "<<endl;

    //printKfromLeaf(root,1);
    //Tree* lca_node = lca(root, -8, 1);
    //cout<<lca_node->data<<endl;

    
    //cout<<dist_nodes(root,4,7);

    //cout<<pathSum(root);

    //Tree* nextRight=findNextright(root,7);

    //(!nextRight) ? cout<<"No next right node " : cout<<nextRight->data;

    //Tree* dll=deepLeftLeaf(root);
    //cout<<dll->data;

    //levelorder(root);
    //cout<<endl;
    /*Tree* head=NULL;
    Tree* root2=extractLeavesInDLL(root,&head);
    levelorder(root2);
    cout<<endl;
    printList(head);*/
    //Tree* root2=removeNodes_sum(root,8);
    //levelorder(root2);
	
    //leftview(root);

    //(isLeavesSamelevel(root)) ? cout<<"All leaves are at same level " : cout<<"All leaves are not at same level ";
	//cout<<depthOddleaf(root);
	/*int in[]={4,2,5,1,6,3,7};
	int pre[]={1,2,4,5,3,6,7};
	int n=sizeof(in)/sizeof(in[0]);
	printpost(in,pre,n);*/

    //cout<<sumLevelDiffer(root);

    //ancestor(root,5);
    //ancestor2(root,5);
    bottom_view(root);
    cout<<endl;
    top_view(root);
	return 0;
}