#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
	node(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};

int Find(vector<int>a,int start,int n,int x)
{
	if(start >= a.size()-1) return 0;
	for(int i = 0 ; i < n-1 ; i++)
		if(a[start+i] > x) 
			return i;
	return 0;
}

node *build_node(vector<int>a,int start,int n)
{
	if(n==0) return NULL;
	node *temp = new node(a[start]);
	int i = Find(a,start+1,n,a[start]);
	temp->left = build_node(a,start+1,i);
	temp->right = build_node(a,start+i+1,n-1-i);
	return temp;
}

void Duyet_la(node *root)
{
	if(root==NULL) return;
	if(root->left==NULL&&root->right==NULL) 
		cout<<root->data<<" ";
	Duyet_la(root->left);
	Duyet_la(root->right);
}

main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<int>a(n);
		for(int i = 0 ; i < n ; i++)
			cin>>a[i];
		node *root = build_node(a,0,n);
		Duyet_la(root);
		cout<<endl;
	}
}
