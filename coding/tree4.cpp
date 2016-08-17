#include <iostream>
#include <fstream>
#define MARKER -1

using namespace std;

typedef struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
}Tree;

Tree* newNode(int item)
{
	Tree* temp=new Tree;
	temp->data=item;
	temp->left=NULL;
	temp->right=NULL;

	return temp;

}

void serialize(Tree* root, ofstream &myfile)
{
	if(!root)
	{
		myfile<<MARKER<<" ";
		return;
	}

	myfile<<root->data<<" ";
	serialize(root->left,myfile);
	serialize(root->right,myfile);
		
}

void deserialize(Tree* root, ifstream &myfile)
{
	int val;
	
			myfile>>val;
			if(val==MARKER)
				return;
			else
			{
				root=newNode(val);
			    deserialize(root->left, myfile);
			    deserialize(root->right, myfile);
			}
			
	
}

void inorder(Tree* root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

int main()
{
	Tree* root               = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    ofstream outfile("tree.txt");
    if(!outfile.is_open())
    {
    	cout<<"Unable to open the file";
    	return 0;
    }
    serialize(root,outfile);
    outfile.close();

    ifstream infile("tree.txt");
    if(!infile.is_open())
    {
    	cout<<"Unable to open the file";
    	return 0;
    }
    deserialize(root, infile);
    infile.close();
    inorder(root);


    return 0;

}