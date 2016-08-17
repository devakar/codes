#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void page_ref(deque<int> &dq, int cache, unordered_map<int, deque<int>::iterator > &m, int x )
{
	if(m.count(x)==0)
	{
		if(dq.size()==cache)
		{
			m.erase(dq.back());
			dq.pop_back();
		}	
		dq.push_front(x);
		m.insert(make_pair(x,dq.begin()));
	}
	
	else
	{
		if(m.at(x)!=dq.begin())
		{
			dq.erase(m.at(x));
			dq.push_front(x);
			m.insert(make_pair(x,dq.begin()));
		}
	}
	
}	

void print_queue(deque<int> dq)
{
	while(!dq.empty())
		{
			cout<<dq.front()<<"\t";
			dq.pop_front();
		}
}

int main() {
	// your code goes here
	deque<int> dq;
	unordered_map<int, deque<int>::iterator > m;
	int page,cache;
	cin>>page>>cache;
	int n,i,x;
	cin>>n;
	for(i=0;i<n;++i)
	{
		cin>>x;
		page_ref(dq,cache,m,x);
	}
	return 0;
}