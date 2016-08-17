#include <bits/stdc++.h>

using namespace std;

typedef struct trie
{
	bool eofString;
	struct trie *child[26];
}Trie;



//to insert the string in the trie
void insert(Trie* head, string s)
{
	
	int i,j;
	int len=s.size();

	for(i=0;i<len;i++)
	{
		if(!head->child[s[i]-'a'])
		{
			Trie *temp=new Trie;

 			for(j=0;j<26;j++)
 				temp->child[j]=NULL;

 			temp->eofString=false;

 			head->child[s[i]-'a']=temp;
 			head=temp;
		}
		else
			head=head->child[s[i]-'a'];
	}
	head->eofString=true;
}

//to check the string is present in the trie or not
bool search(Trie* head, string s)
{
	int len=s.size();
	int i;
	for(i=0;i<len;i++)
	{
		if(!head->child[s[i]-'a'])
			return false;
		else
			head=head->child[s[i]-'a'];
	}

	if(!head->eofString)
		return false;

	return true;
}

int main()
{
	Trie *head=new Trie;
	head->eofString=false;
	for(int i=0;i<26;i++)
		head->child[i]=NULL;

	string s[]={"the", "a", "there", "answer", "any", "by", "bye", "their"};
	for(int i=0;i<8;i++)
		insert(head,s[i]);

	cout<<search(head,"an");
}